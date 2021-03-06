/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKEVENT_GROUPS_H
#define _MOCKEVENT_GROUPS_H

#include "FreeRTOS.h"
#include "event_groups.h"
#include "unity.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void Mockevent_groups_Init(void);
void Mockevent_groups_Destroy(void);
void Mockevent_groups_Verify(void);

#define xEventGroupCreate_IgnoreAndReturn(cmock_retval) xEventGroupCreate_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupCreate_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t cmock_to_return);
#define xEventGroupCreate_ExpectAndReturn(cmock_retval) xEventGroupCreate_CMockExpectAndReturn(__LINE__, cmock_retval)
void xEventGroupCreate_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t cmock_to_return);
#define xEventGroupCreateStatic_IgnoreAndReturn(cmock_retval) xEventGroupCreateStatic_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupCreateStatic_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t cmock_to_return);
#define xEventGroupCreateStatic_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupCreateStatic_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupCreateStatic_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t cmock_to_return);
#define xEventGroupCreateStatic_ExpectAndReturn(pxEventGroupBuffer, cmock_retval) xEventGroupCreateStatic_CMockExpectAndReturn(__LINE__, pxEventGroupBuffer, cmock_retval)
void xEventGroupCreateStatic_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, StaticEventGroup_t* pxEventGroupBuffer, EventGroupHandle_t cmock_to_return);
#define xEventGroupCreateStatic_ExpectWithArrayAndReturn(pxEventGroupBuffer, pxEventGroupBuffer_Depth, cmock_retval) xEventGroupCreateStatic_CMockExpectWithArrayAndReturn(__LINE__, pxEventGroupBuffer, pxEventGroupBuffer_Depth, cmock_retval)
void xEventGroupCreateStatic_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, StaticEventGroup_t* pxEventGroupBuffer, int pxEventGroupBuffer_Depth, EventGroupHandle_t cmock_to_return);
#define xEventGroupCreateStatic_IgnoreArg_pxEventGroupBuffer() xEventGroupCreateStatic_CMockIgnoreArg_pxEventGroupBuffer(__LINE__)
void xEventGroupCreateStatic_CMockIgnoreArg_pxEventGroupBuffer(UNITY_LINE_TYPE cmock_line);
#define xEventGroupWaitBits_IgnoreAndReturn(cmock_retval) xEventGroupWaitBits_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupWaitBits_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupWaitBits_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupWaitBits_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupWaitBits_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupWaitBits_ExpectAndReturn(xEventGroup, uxBitsToWaitFor, xClearOnExit, xWaitForAllBits, xTicksToWait, cmock_retval) xEventGroupWaitBits_CMockExpectAndReturn(__LINE__, xEventGroup, uxBitsToWaitFor, xClearOnExit, xWaitForAllBits, xTicksToWait, cmock_retval)
void xEventGroupWaitBits_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToWaitFor, const BaseType_t xClearOnExit, const BaseType_t xWaitForAllBits, TickType_t xTicksToWait, EventBits_t cmock_to_return);
#define xEventGroupWaitBits_IgnoreArg_xEventGroup() xEventGroupWaitBits_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupWaitBits_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define xEventGroupWaitBits_IgnoreArg_uxBitsToWaitFor() xEventGroupWaitBits_CMockIgnoreArg_uxBitsToWaitFor(__LINE__)
void xEventGroupWaitBits_CMockIgnoreArg_uxBitsToWaitFor(UNITY_LINE_TYPE cmock_line);
#define xEventGroupWaitBits_IgnoreArg_xClearOnExit() xEventGroupWaitBits_CMockIgnoreArg_xClearOnExit(__LINE__)
void xEventGroupWaitBits_CMockIgnoreArg_xClearOnExit(UNITY_LINE_TYPE cmock_line);
#define xEventGroupWaitBits_IgnoreArg_xWaitForAllBits() xEventGroupWaitBits_CMockIgnoreArg_xWaitForAllBits(__LINE__)
void xEventGroupWaitBits_CMockIgnoreArg_xWaitForAllBits(UNITY_LINE_TYPE cmock_line);
#define xEventGroupWaitBits_IgnoreArg_xTicksToWait() xEventGroupWaitBits_CMockIgnoreArg_xTicksToWait(__LINE__)
void xEventGroupWaitBits_CMockIgnoreArg_xTicksToWait(UNITY_LINE_TYPE cmock_line);
#define xEventGroupClearBits_IgnoreAndReturn(cmock_retval) xEventGroupClearBits_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupClearBits_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupClearBits_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupClearBits_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupClearBits_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupClearBits_ExpectAndReturn(xEventGroup, uxBitsToClear, cmock_retval) xEventGroupClearBits_CMockExpectAndReturn(__LINE__, xEventGroup, uxBitsToClear, cmock_retval)
void xEventGroupClearBits_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToClear, EventBits_t cmock_to_return);
#define xEventGroupClearBits_IgnoreArg_xEventGroup() xEventGroupClearBits_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupClearBits_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define xEventGroupClearBits_IgnoreArg_uxBitsToClear() xEventGroupClearBits_CMockIgnoreArg_uxBitsToClear(__LINE__)
void xEventGroupClearBits_CMockIgnoreArg_uxBitsToClear(UNITY_LINE_TYPE cmock_line);
#define xEventGroupClearBitsFromISR_IgnoreAndReturn(cmock_retval) xEventGroupClearBitsFromISR_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupClearBitsFromISR_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, BaseType_t cmock_to_return);
#define xEventGroupClearBitsFromISR_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupClearBitsFromISR_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupClearBitsFromISR_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, BaseType_t cmock_to_return);
#define xEventGroupClearBitsFromISR_ExpectAndReturn(xEventGroup, uxBitsToClear, cmock_retval) xEventGroupClearBitsFromISR_CMockExpectAndReturn(__LINE__, xEventGroup, uxBitsToClear, cmock_retval)
void xEventGroupClearBitsFromISR_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToClear, BaseType_t cmock_to_return);
#define xEventGroupClearBitsFromISR_IgnoreArg_xEventGroup() xEventGroupClearBitsFromISR_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupClearBitsFromISR_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define xEventGroupClearBitsFromISR_IgnoreArg_uxBitsToClear() xEventGroupClearBitsFromISR_CMockIgnoreArg_uxBitsToClear(__LINE__)
void xEventGroupClearBitsFromISR_CMockIgnoreArg_uxBitsToClear(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSetBits_IgnoreAndReturn(cmock_retval) xEventGroupSetBits_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupSetBits_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupSetBits_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupSetBits_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupSetBits_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupSetBits_ExpectAndReturn(xEventGroup, uxBitsToSet, cmock_retval) xEventGroupSetBits_CMockExpectAndReturn(__LINE__, xEventGroup, uxBitsToSet, cmock_retval)
void xEventGroupSetBits_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToSet, EventBits_t cmock_to_return);
#define xEventGroupSetBits_IgnoreArg_xEventGroup() xEventGroupSetBits_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupSetBits_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSetBits_IgnoreArg_uxBitsToSet() xEventGroupSetBits_CMockIgnoreArg_uxBitsToSet(__LINE__)
void xEventGroupSetBits_CMockIgnoreArg_uxBitsToSet(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSetBitsFromISR_IgnoreAndReturn(cmock_retval) xEventGroupSetBitsFromISR_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupSetBitsFromISR_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, BaseType_t cmock_to_return);
#define xEventGroupSetBitsFromISR_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupSetBitsFromISR_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupSetBitsFromISR_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, BaseType_t cmock_to_return);
#define xEventGroupSetBitsFromISR_ExpectAndReturn(xEventGroup, uxBitsToSet, pxHigherPriorityTaskWoken, cmock_retval) xEventGroupSetBitsFromISR_CMockExpectAndReturn(__LINE__, xEventGroup, uxBitsToSet, pxHigherPriorityTaskWoken, cmock_retval)
void xEventGroupSetBitsFromISR_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToSet, BaseType_t* pxHigherPriorityTaskWoken, BaseType_t cmock_to_return);
#define xEventGroupSetBitsFromISR_ExpectWithArrayAndReturn(xEventGroup, uxBitsToSet, pxHigherPriorityTaskWoken, pxHigherPriorityTaskWoken_Depth, cmock_retval) xEventGroupSetBitsFromISR_CMockExpectWithArrayAndReturn(__LINE__, xEventGroup, uxBitsToSet, pxHigherPriorityTaskWoken, pxHigherPriorityTaskWoken_Depth, cmock_retval)
void xEventGroupSetBitsFromISR_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToSet, BaseType_t* pxHigherPriorityTaskWoken, int pxHigherPriorityTaskWoken_Depth, BaseType_t cmock_to_return);
#define xEventGroupSetBitsFromISR_IgnoreArg_xEventGroup() xEventGroupSetBitsFromISR_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupSetBitsFromISR_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSetBitsFromISR_IgnoreArg_uxBitsToSet() xEventGroupSetBitsFromISR_CMockIgnoreArg_uxBitsToSet(__LINE__)
void xEventGroupSetBitsFromISR_CMockIgnoreArg_uxBitsToSet(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSetBitsFromISR_IgnoreArg_pxHigherPriorityTaskWoken() xEventGroupSetBitsFromISR_CMockIgnoreArg_pxHigherPriorityTaskWoken(__LINE__)
void xEventGroupSetBitsFromISR_CMockIgnoreArg_pxHigherPriorityTaskWoken(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSync_IgnoreAndReturn(cmock_retval) xEventGroupSync_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupSync_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupSync_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupSync_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupSync_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupSync_ExpectAndReturn(xEventGroup, uxBitsToSet, uxBitsToWaitFor, xTicksToWait, cmock_retval) xEventGroupSync_CMockExpectAndReturn(__LINE__, xEventGroup, uxBitsToSet, uxBitsToWaitFor, xTicksToWait, cmock_retval)
void xEventGroupSync_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToSet, const EventBits_t uxBitsToWaitFor, TickType_t xTicksToWait, EventBits_t cmock_to_return);
#define xEventGroupSync_IgnoreArg_xEventGroup() xEventGroupSync_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupSync_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSync_IgnoreArg_uxBitsToSet() xEventGroupSync_CMockIgnoreArg_uxBitsToSet(__LINE__)
void xEventGroupSync_CMockIgnoreArg_uxBitsToSet(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSync_IgnoreArg_uxBitsToWaitFor() xEventGroupSync_CMockIgnoreArg_uxBitsToWaitFor(__LINE__)
void xEventGroupSync_CMockIgnoreArg_uxBitsToWaitFor(UNITY_LINE_TYPE cmock_line);
#define xEventGroupSync_IgnoreArg_xTicksToWait() xEventGroupSync_CMockIgnoreArg_xTicksToWait(__LINE__)
void xEventGroupSync_CMockIgnoreArg_xTicksToWait(UNITY_LINE_TYPE cmock_line);
#define xEventGroupGetBitsFromISR_IgnoreAndReturn(cmock_retval) xEventGroupGetBitsFromISR_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void xEventGroupGetBitsFromISR_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupGetBitsFromISR_ExpectAnyArgsAndReturn(cmock_retval) xEventGroupGetBitsFromISR_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void xEventGroupGetBitsFromISR_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, EventBits_t cmock_to_return);
#define xEventGroupGetBitsFromISR_ExpectAndReturn(xEventGroup, cmock_retval) xEventGroupGetBitsFromISR_CMockExpectAndReturn(__LINE__, xEventGroup, cmock_retval)
void xEventGroupGetBitsFromISR_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup, EventBits_t cmock_to_return);
#define xEventGroupGetBitsFromISR_IgnoreArg_xEventGroup() xEventGroupGetBitsFromISR_CMockIgnoreArg_xEventGroup(__LINE__)
void xEventGroupGetBitsFromISR_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define vEventGroupDelete_Ignore() vEventGroupDelete_CMockIgnore()
void vEventGroupDelete_CMockIgnore(void);
#define vEventGroupDelete_ExpectAnyArgs() vEventGroupDelete_CMockExpectAnyArgs(__LINE__)
void vEventGroupDelete_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define vEventGroupDelete_Expect(xEventGroup) vEventGroupDelete_CMockExpect(__LINE__, xEventGroup)
void vEventGroupDelete_CMockExpect(UNITY_LINE_TYPE cmock_line, EventGroupHandle_t xEventGroup);
#define vEventGroupDelete_IgnoreArg_xEventGroup() vEventGroupDelete_CMockIgnoreArg_xEventGroup(__LINE__)
void vEventGroupDelete_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define vEventGroupSetBitsCallback_Ignore() vEventGroupSetBitsCallback_CMockIgnore()
void vEventGroupSetBitsCallback_CMockIgnore(void);
#define vEventGroupSetBitsCallback_ExpectAnyArgs() vEventGroupSetBitsCallback_CMockExpectAnyArgs(__LINE__)
void vEventGroupSetBitsCallback_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define vEventGroupSetBitsCallback_Expect(pvEventGroup, ulBitsToSet) vEventGroupSetBitsCallback_CMockExpect(__LINE__, pvEventGroup, ulBitsToSet)
void vEventGroupSetBitsCallback_CMockExpect(UNITY_LINE_TYPE cmock_line, void* pvEventGroup, const uint32_t ulBitsToSet);
#define vEventGroupSetBitsCallback_ExpectWithArray(pvEventGroup, pvEventGroup_Depth, ulBitsToSet) vEventGroupSetBitsCallback_CMockExpectWithArray(__LINE__, pvEventGroup, pvEventGroup_Depth, ulBitsToSet)
void vEventGroupSetBitsCallback_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, void* pvEventGroup, int pvEventGroup_Depth, const uint32_t ulBitsToSet);
#define vEventGroupSetBitsCallback_IgnoreArg_pvEventGroup() vEventGroupSetBitsCallback_CMockIgnoreArg_pvEventGroup(__LINE__)
void vEventGroupSetBitsCallback_CMockIgnoreArg_pvEventGroup(UNITY_LINE_TYPE cmock_line);
#define vEventGroupSetBitsCallback_IgnoreArg_ulBitsToSet() vEventGroupSetBitsCallback_CMockIgnoreArg_ulBitsToSet(__LINE__)
void vEventGroupSetBitsCallback_CMockIgnoreArg_ulBitsToSet(UNITY_LINE_TYPE cmock_line);
#define vEventGroupClearBitsCallback_Ignore() vEventGroupClearBitsCallback_CMockIgnore()
void vEventGroupClearBitsCallback_CMockIgnore(void);
#define vEventGroupClearBitsCallback_ExpectAnyArgs() vEventGroupClearBitsCallback_CMockExpectAnyArgs(__LINE__)
void vEventGroupClearBitsCallback_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define vEventGroupClearBitsCallback_Expect(pvEventGroup, ulBitsToClear) vEventGroupClearBitsCallback_CMockExpect(__LINE__, pvEventGroup, ulBitsToClear)
void vEventGroupClearBitsCallback_CMockExpect(UNITY_LINE_TYPE cmock_line, void* pvEventGroup, const uint32_t ulBitsToClear);
#define vEventGroupClearBitsCallback_ExpectWithArray(pvEventGroup, pvEventGroup_Depth, ulBitsToClear) vEventGroupClearBitsCallback_CMockExpectWithArray(__LINE__, pvEventGroup, pvEventGroup_Depth, ulBitsToClear)
void vEventGroupClearBitsCallback_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, void* pvEventGroup, int pvEventGroup_Depth, const uint32_t ulBitsToClear);
#define vEventGroupClearBitsCallback_IgnoreArg_pvEventGroup() vEventGroupClearBitsCallback_CMockIgnoreArg_pvEventGroup(__LINE__)
void vEventGroupClearBitsCallback_CMockIgnoreArg_pvEventGroup(UNITY_LINE_TYPE cmock_line);
#define vEventGroupClearBitsCallback_IgnoreArg_ulBitsToClear() vEventGroupClearBitsCallback_CMockIgnoreArg_ulBitsToClear(__LINE__)
void vEventGroupClearBitsCallback_CMockIgnoreArg_ulBitsToClear(UNITY_LINE_TYPE cmock_line);
#define uxEventGroupGetNumber_IgnoreAndReturn(cmock_retval) uxEventGroupGetNumber_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void uxEventGroupGetNumber_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, UBaseType_t cmock_to_return);
#define uxEventGroupGetNumber_ExpectAnyArgsAndReturn(cmock_retval) uxEventGroupGetNumber_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void uxEventGroupGetNumber_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, UBaseType_t cmock_to_return);
#define uxEventGroupGetNumber_ExpectAndReturn(xEventGroup, cmock_retval) uxEventGroupGetNumber_CMockExpectAndReturn(__LINE__, xEventGroup, cmock_retval)
void uxEventGroupGetNumber_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, void* xEventGroup, UBaseType_t cmock_to_return);
#define uxEventGroupGetNumber_ExpectWithArrayAndReturn(xEventGroup, xEventGroup_Depth, cmock_retval) uxEventGroupGetNumber_CMockExpectWithArrayAndReturn(__LINE__, xEventGroup, xEventGroup_Depth, cmock_retval)
void uxEventGroupGetNumber_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, void* xEventGroup, int xEventGroup_Depth, UBaseType_t cmock_to_return);
#define uxEventGroupGetNumber_IgnoreArg_xEventGroup() uxEventGroupGetNumber_CMockIgnoreArg_xEventGroup(__LINE__)
void uxEventGroupGetNumber_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define vEventGroupSetNumber_Ignore() vEventGroupSetNumber_CMockIgnore()
void vEventGroupSetNumber_CMockIgnore(void);
#define vEventGroupSetNumber_ExpectAnyArgs() vEventGroupSetNumber_CMockExpectAnyArgs(__LINE__)
void vEventGroupSetNumber_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define vEventGroupSetNumber_Expect(xEventGroup, uxEventGroupNumber) vEventGroupSetNumber_CMockExpect(__LINE__, xEventGroup, uxEventGroupNumber)
void vEventGroupSetNumber_CMockExpect(UNITY_LINE_TYPE cmock_line, void* xEventGroup, UBaseType_t uxEventGroupNumber);
#define vEventGroupSetNumber_ExpectWithArray(xEventGroup, xEventGroup_Depth, uxEventGroupNumber) vEventGroupSetNumber_CMockExpectWithArray(__LINE__, xEventGroup, xEventGroup_Depth, uxEventGroupNumber)
void vEventGroupSetNumber_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, void* xEventGroup, int xEventGroup_Depth, UBaseType_t uxEventGroupNumber);
#define vEventGroupSetNumber_IgnoreArg_xEventGroup() vEventGroupSetNumber_CMockIgnoreArg_xEventGroup(__LINE__)
void vEventGroupSetNumber_CMockIgnoreArg_xEventGroup(UNITY_LINE_TYPE cmock_line);
#define vEventGroupSetNumber_IgnoreArg_uxEventGroupNumber() vEventGroupSetNumber_CMockIgnoreArg_uxEventGroupNumber(__LINE__)
void vEventGroupSetNumber_CMockIgnoreArg_uxEventGroupNumber(UNITY_LINE_TYPE cmock_line);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
