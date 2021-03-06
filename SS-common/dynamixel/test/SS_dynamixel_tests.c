/*
 * SS_dynamixel_test.c
 *
 *  Created on: Dec 29, 2019
 *      Author: maciek
 */

#include "Mockqueue.h"
#include "Mockstm32f4xx_hal.h"
#include "Mockstm32f4xx_hal_gpio.h"
#include "Mockstm32f4xx_hal_uart.h"
#include "SS_dynamixel.c"
#include "stdio.h"
#include "unity_fixture.h"

Dynamixel dynamixel = {
    .id = 0x01};

TEST_GROUP(dynamixel);

TEST_GROUP_RUNNER(dynamixel) {
    RUN_TEST_CASE(dynamixel, crc1);
    RUN_TEST_CASE(dynamixel, crc2);
    RUN_TEST_CASE(dynamixel, enable_torque);
    RUN_TEST_CASE(dynamixel, disable_torque);
    RUN_TEST_CASE(dynamixel, set_opened_position);
    RUN_TEST_CASE(dynamixel, set_closed_position);
    RUN_TEST_CASE(dynamixel, prepare_packet);
    RUN_TEST_CASE(dynamixel, create_packet);
    RUN_TEST_CASE(dynamixel, crc_check);
    RUN_TEST_CASE(dynamixel, crc_check_error);
    RUN_TEST_CASE(dynamixel, write);
    RUN_TEST_CASE(dynamixel, read);
    RUN_TEST_CASE(dynamixel, write_homing_offset);
    RUN_TEST_CASE(dynamixel, ping);
    RUN_TEST_CASE(dynamixel, opened_closed_postion);
}

TEST_SETUP(dynamixel) {}

TEST_TEAR_DOWN(dynamixel) {}

static void ignore_all() {
    xQueueSemaphoreTake_IgnoreAndReturn(pdTRUE);
    HAL_GPIO_WritePin_Ignore();
    xQueueGenericSend_IgnoreAndReturn(pdTRUE);
    HAL_UART_Transmit_IgnoreAndReturn(HAL_OK);
    HAL_UART_Transmit_IT_IgnoreAndReturn(HAL_OK);
    HAL_UART_Receive_IgnoreAndReturn(HAL_OK);
}

TEST(dynamixel, enable_torque) {
    ignore_all();
    dynamixel.torque_enabled = false;
    SS_dynamixel_enable_torque(&dynamixel);
    TEST_ASSERT_TRUE(dynamixel.torque_enabled);
}

TEST(dynamixel, disable_torque) {
    ignore_all();
    dynamixel.torque_enabled = true;
    SS_dynamixel_disable_torque(&dynamixel);
    TEST_ASSERT_FALSE(dynamixel.torque_enabled);
}

TEST(dynamixel, set_opened_position) {
    ignore_all();
    SS_dynamixel_set_opened_position(&dynamixel, 555);
    TEST_ASSERT_EQUAL(555, dynamixel.opened_position);
}

TEST(dynamixel, set_closed_position) {
    ignore_all();
    SS_dynamixel_set_closed_position(&dynamixel, 123);
    TEST_ASSERT_EQUAL(123, dynamixel.closed_position);
}

TEST(dynamixel, crc1) {
    uint8_t packet[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x55, 0x00, 0x06, 0x04, 0x26};
    uint16_t crc = SS_dynamixel_calculate_crc(0, packet, sizeof(packet));
    TEST_ASSERT_EQUAL_HEX16(0x5D65, crc);
}

TEST(dynamixel, crc2) {
    uint8_t packet[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x02, 0x84, 0x00, 0x04, 0x00};
    uint16_t crc = SS_dynamixel_calculate_crc(0, packet, sizeof(packet));
    TEST_ASSERT_EQUAL_HEX16(0x151D, crc);
}

TEST(dynamixel, prepare_packet) {
    DynamixelMessage message;
    uint8_t expected[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x02, 0x84, 0x00, 0x04, 0x00, 0x1D, 0x15};
    InstructionPacket packet = {0xFDFFFF, 0x00, 0x01, 0x07, 0x02};
    uint8_t data[] = {0x84, 0x00, 0x04, 0x00};
    SS_dynamixel_packet_to_buf(&packet, data, &message);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, message.packet, sizeof(expected));
    TEST_ASSERT_EQUAL_UINT(14, message.packet_size);
}

TEST(dynamixel, create_packet) {
    DynamixelMessage message;
    uint8_t expected[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x02, 0x84, 0x00, 0x04, 0x00, 0x1D, 0x15};
    uint8_t data[] = {0x84, 0x00, 0x04, 0x00};
    SS_dynamixel_create_packet(&dynamixel, 0x02, data, sizeof(data), &message);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, message.packet, sizeof(expected));
}

TEST(dynamixel, write) {
    HAL_UART_AbortReceive_IgnoreAndReturn(0);
    HAL_GPIO_WritePin_Ignore();
    uint8_t expected[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x09, 0x00, 0x03, 0x74, 0x00, 0x00, 0x02, 0x00, 0x00, 0xCA, 0x89};
    HAL_UART_Transmit_ExpectWithArrayAndReturn(0, 0, expected, sizeof(expected), sizeof(expected), 1000, HAL_OK);
    HAL_UART_Receive_IgnoreAndReturn(HAL_OK);
    uint8_t data[] = {0x00, 0x02, 0x00, 0x00};
    SS_dynamixel_write(&dynamixel, 0x74, data, sizeof(data));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, dynamixel.tx_packet_buff, sizeof(expected));
}

TEST(dynamixel, read) {
    HAL_UART_AbortReceive_IgnoreAndReturn(0);
    HAL_GPIO_WritePin_Ignore();
    uint8_t expected[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x07, 0x00, 0x02, 0x84, 0x00, 0x04, 0x00, 0x1D, 0x15};
    HAL_UART_Transmit_ExpectWithArrayAndReturn(0, 0, expected, sizeof(expected), sizeof(expected), 1000, HAL_OK);
    SS_dynamixel_read(&dynamixel, 0x84, dynamixel.rx_packet_buff, 4);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, dynamixel.tx_packet_buff, sizeof(expected));
}

TEST(dynamixel, crc_check) {
    uint8_t data[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x09, 0x00, 0x03, 0x74, 0x00, 0x00, 0x02, 0x00, 0x00, 0xCA, 0x89};
    uint8_t result = SS_dynamixel_check_crc(data, sizeof(data));
    TEST_ASSERT_EQUAL_UINT8(true, result);
}

TEST(dynamixel, crc_check_error) {
    uint8_t data[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x09, 0x00, 0x04, 0x68, 0x00, 0xC8, 0x00, 0x00, 0x00, 0xA9, 0x8E};
    uint8_t result = SS_dynamixel_check_crc(data, sizeof(data));
    TEST_ASSERT_EQUAL_UINT8(false, result);
}

TEST(dynamixel, write_homing_offset) {
    HAL_UART_AbortReceive_IgnoreAndReturn(0);
    HAL_GPIO_WritePin_Ignore();
    uint8_t expected[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x09, 0x00, 0x03, 0x14, 0x00, 500 & 0xFF, 500 >> 8, 0x00, 0x00};
    uint32_t data = 500;
    HAL_UART_Transmit_ExpectWithArrayAndReturn(0, 0, expected, sizeof(expected), sizeof(expected) + 2, 1000, HAL_OK);
    SS_dynamixel_write(&dynamixel, DYNAMIXEL_HOMING_OFFSET, &data, 4);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, dynamixel.tx_packet_buff, sizeof(expected));
}

TEST(dynamixel, ping) {
    HAL_UART_AbortReceive_IgnoreAndReturn(0);
    HAL_GPIO_WritePin_Ignore();
    uint8_t expected[] = {0xFF, 0xFF, 0xFD, 0x00, 0x01, 0x03, 0x00, 0x01, 0x19, 0x4E};
    HAL_UART_Transmit_ExpectWithArrayAndReturn(0, 0, expected, sizeof(expected), sizeof(expected), 1000, HAL_OK);
    SS_dynamixel_ping(&dynamixel);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, dynamixel.tx_packet_buff, sizeof(expected));
}

TEST(dynamixel, opened_closed_postion) {
    ignore_all();
    SS_dynamixel_set_closed_position(&dynamixel, 11);
    SS_dynamixel_set_opened_position(&dynamixel, 3999);
    TEST_ASSERT_EQUAL(11, dynamixel.closed_position);
    TEST_ASSERT_EQUAL(3999, dynamixel.opened_position);
}

void tests(void) {
    RUN_TEST_GROUP(dynamixel);
}

int main(int argc, const char *argv[]) {
    return UnityMain(argc, argv, tests);
}
