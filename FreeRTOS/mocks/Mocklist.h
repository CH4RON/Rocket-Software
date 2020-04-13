/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKLIST_H
#define _MOCKLIST_H

#include "FreeRTOS.h"
#include "list.h"
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

void Mocklist_Init(void);
void Mocklist_Destroy(void);
void Mocklist_Verify(void);

#define vListInitialise_Expect(pxList) vListInitialise_CMockExpect(__LINE__, pxList)
void vListInitialise_CMockExpect(UNITY_LINE_TYPE cmock_line, List_t* const pxList);
#define vListInitialiseItem_Expect(pxItem) vListInitialiseItem_CMockExpect(__LINE__, pxItem)
void vListInitialiseItem_CMockExpect(UNITY_LINE_TYPE cmock_line, ListItem_t* const pxItem);
#define vListInsert_Expect(pxList, pxNewListItem) vListInsert_CMockExpect(__LINE__, pxList, pxNewListItem)
void vListInsert_CMockExpect(UNITY_LINE_TYPE cmock_line, List_t* const pxList, ListItem_t* const pxNewListItem);
#define vListInsertEnd_Expect(pxList, pxNewListItem) vListInsertEnd_CMockExpect(__LINE__, pxList, pxNewListItem)
void vListInsertEnd_CMockExpect(UNITY_LINE_TYPE cmock_line, List_t* const pxList, ListItem_t* const pxNewListItem);
#define uxListRemove_ExpectAndReturn(pxItemToRemove, cmock_retval) uxListRemove_CMockExpectAndReturn(__LINE__, pxItemToRemove, cmock_retval)
void uxListRemove_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, ListItem_t* const pxItemToRemove, UBaseType_t cmock_to_return);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
