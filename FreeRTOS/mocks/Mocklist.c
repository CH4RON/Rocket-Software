/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "Mocklist.h"

static const char* CMockString_pxItem = "pxItem";
static const char* CMockString_pxItemToRemove = "pxItemToRemove";
static const char* CMockString_pxList = "pxList";
static const char* CMockString_pxNewListItem = "pxNewListItem";
static const char* CMockString_uxListRemove = "uxListRemove";
static const char* CMockString_vListInitialise = "vListInitialise";
static const char* CMockString_vListInitialiseItem = "vListInitialiseItem";
static const char* CMockString_vListInsert = "vListInsert";
static const char* CMockString_vListInsertEnd = "vListInsertEnd";

typedef struct _CMOCK_vListInitialise_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  List_t* Expected_pxList;
  int Expected_pxList_Depth;
  char IgnoreArg_pxList;

} CMOCK_vListInitialise_CALL_INSTANCE;

typedef struct _CMOCK_vListInitialiseItem_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  ListItem_t* Expected_pxItem;
  int Expected_pxItem_Depth;
  char IgnoreArg_pxItem;

} CMOCK_vListInitialiseItem_CALL_INSTANCE;

typedef struct _CMOCK_vListInsert_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  List_t* Expected_pxList;
  ListItem_t* Expected_pxNewListItem;
  int Expected_pxList_Depth;
  int Expected_pxNewListItem_Depth;
  char IgnoreArg_pxList;
  char IgnoreArg_pxNewListItem;

} CMOCK_vListInsert_CALL_INSTANCE;

typedef struct _CMOCK_vListInsertEnd_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  List_t* Expected_pxList;
  ListItem_t* Expected_pxNewListItem;
  int Expected_pxList_Depth;
  int Expected_pxNewListItem_Depth;
  char IgnoreArg_pxList;
  char IgnoreArg_pxNewListItem;

} CMOCK_vListInsertEnd_CALL_INSTANCE;

typedef struct _CMOCK_uxListRemove_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  UBaseType_t ReturnVal;
  ListItem_t* Expected_pxItemToRemove;
  int Expected_pxItemToRemove_Depth;
  char IgnoreArg_pxItemToRemove;

} CMOCK_uxListRemove_CALL_INSTANCE;

static struct MocklistInstance
{
  char vListInitialise_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE vListInitialise_CallInstance;
  char vListInitialiseItem_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE vListInitialiseItem_CallInstance;
  char vListInsert_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE vListInsert_CallInstance;
  char vListInsertEnd_IgnoreBool;
  CMOCK_MEM_INDEX_TYPE vListInsertEnd_CallInstance;
  char uxListRemove_IgnoreBool;
  UBaseType_t uxListRemove_FinalReturn;
  CMOCK_MEM_INDEX_TYPE uxListRemove_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mocklist_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.vListInitialise_CallInstance;
  if (Mock.vListInitialise_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_vListInitialise);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.vListInitialiseItem_CallInstance;
  if (Mock.vListInitialiseItem_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_vListInitialiseItem);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.vListInsert_CallInstance;
  if (Mock.vListInsert_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_vListInsert);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.vListInsertEnd_CallInstance;
  if (Mock.vListInsertEnd_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_vListInsertEnd);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.uxListRemove_CallInstance;
  if (Mock.uxListRemove_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_uxListRemove);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
}

void Mocklist_Init(void)
{
  Mocklist_Destroy();
}

void Mocklist_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void vListInitialise(List_t* const pxList)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_vListInitialise_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_vListInitialise);
  cmock_call_instance = (CMOCK_vListInitialise_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.vListInitialise_CallInstance);
  Mock.vListInitialise_CallInstance = CMock_Guts_MemNext(Mock.vListInitialise_CallInstance);
  if (Mock.vListInitialise_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_pxList)
  {
    UNITY_SET_DETAILS(CMockString_vListInitialise,CMockString_pxList);
    if (cmock_call_instance->Expected_pxList == NULL)
      { UNITY_TEST_ASSERT_NULL(pxList, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxList), (void*)(pxList), sizeof(List_t), cmock_call_instance->Expected_pxList_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_vListInitialise(CMOCK_vListInitialise_CALL_INSTANCE* cmock_call_instance, List_t* const pxList, int pxList_Depth)
{
  cmock_call_instance->Expected_pxList = pxList;
  cmock_call_instance->Expected_pxList_Depth = pxList_Depth;
  cmock_call_instance->IgnoreArg_pxList = 0;
}

void vListInitialise_CMockIgnore(void)
{
  Mock.vListInitialise_IgnoreBool = (char)1;
}

void vListInitialise_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInitialise_CALL_INSTANCE));
  CMOCK_vListInitialise_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialise_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInitialise_CallInstance = CMock_Guts_MemChain(Mock.vListInitialise_CallInstance, cmock_guts_index);
  Mock.vListInitialise_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void vListInitialise_CMockExpect(UNITY_LINE_TYPE cmock_line, List_t* const pxList)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInitialise_CALL_INSTANCE));
  CMOCK_vListInitialise_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialise_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInitialise_CallInstance = CMock_Guts_MemChain(Mock.vListInitialise_CallInstance, cmock_guts_index);
  Mock.vListInitialise_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInitialise(cmock_call_instance, pxList, 1);
}

void vListInitialise_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, List_t* const pxList, int pxList_Depth)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInitialise_CALL_INSTANCE));
  CMOCK_vListInitialise_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialise_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInitialise_CallInstance = CMock_Guts_MemChain(Mock.vListInitialise_CallInstance, cmock_guts_index);
  Mock.vListInitialise_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInitialise(cmock_call_instance, pxList, pxList_Depth);
}

void vListInitialise_CMockIgnoreArg_pxList(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_vListInitialise_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialise_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.vListInitialise_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxList = 1;
}

void vListInitialiseItem(ListItem_t* const pxItem)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_vListInitialiseItem_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_vListInitialiseItem);
  cmock_call_instance = (CMOCK_vListInitialiseItem_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.vListInitialiseItem_CallInstance);
  Mock.vListInitialiseItem_CallInstance = CMock_Guts_MemNext(Mock.vListInitialiseItem_CallInstance);
  if (Mock.vListInitialiseItem_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_pxItem)
  {
    UNITY_SET_DETAILS(CMockString_vListInitialiseItem,CMockString_pxItem);
    if (cmock_call_instance->Expected_pxItem == NULL)
      { UNITY_TEST_ASSERT_NULL(pxItem, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxItem), (void*)(pxItem), sizeof(ListItem_t), cmock_call_instance->Expected_pxItem_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_vListInitialiseItem(CMOCK_vListInitialiseItem_CALL_INSTANCE* cmock_call_instance, ListItem_t* const pxItem, int pxItem_Depth)
{
  cmock_call_instance->Expected_pxItem = pxItem;
  cmock_call_instance->Expected_pxItem_Depth = pxItem_Depth;
  cmock_call_instance->IgnoreArg_pxItem = 0;
}

void vListInitialiseItem_CMockIgnore(void)
{
  Mock.vListInitialiseItem_IgnoreBool = (char)1;
}

void vListInitialiseItem_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInitialiseItem_CALL_INSTANCE));
  CMOCK_vListInitialiseItem_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialiseItem_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInitialiseItem_CallInstance = CMock_Guts_MemChain(Mock.vListInitialiseItem_CallInstance, cmock_guts_index);
  Mock.vListInitialiseItem_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void vListInitialiseItem_CMockExpect(UNITY_LINE_TYPE cmock_line, ListItem_t* const pxItem)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInitialiseItem_CALL_INSTANCE));
  CMOCK_vListInitialiseItem_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialiseItem_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInitialiseItem_CallInstance = CMock_Guts_MemChain(Mock.vListInitialiseItem_CallInstance, cmock_guts_index);
  Mock.vListInitialiseItem_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInitialiseItem(cmock_call_instance, pxItem, 1);
}

void vListInitialiseItem_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, ListItem_t* const pxItem, int pxItem_Depth)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInitialiseItem_CALL_INSTANCE));
  CMOCK_vListInitialiseItem_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialiseItem_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInitialiseItem_CallInstance = CMock_Guts_MemChain(Mock.vListInitialiseItem_CallInstance, cmock_guts_index);
  Mock.vListInitialiseItem_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInitialiseItem(cmock_call_instance, pxItem, pxItem_Depth);
}

void vListInitialiseItem_CMockIgnoreArg_pxItem(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_vListInitialiseItem_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInitialiseItem_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.vListInitialiseItem_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxItem = 1;
}

void vListInsert(List_t* const pxList, ListItem_t* const pxNewListItem)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_vListInsert);
  cmock_call_instance = (CMOCK_vListInsert_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.vListInsert_CallInstance);
  Mock.vListInsert_CallInstance = CMock_Guts_MemNext(Mock.vListInsert_CallInstance);
  if (Mock.vListInsert_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_pxList)
  {
    UNITY_SET_DETAILS(CMockString_vListInsert,CMockString_pxList);
    if (cmock_call_instance->Expected_pxList == NULL)
      { UNITY_TEST_ASSERT_NULL(pxList, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxList), (void*)(pxList), sizeof(List_t), cmock_call_instance->Expected_pxList_Depth, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_pxNewListItem)
  {
    UNITY_SET_DETAILS(CMockString_vListInsert,CMockString_pxNewListItem);
    if (cmock_call_instance->Expected_pxNewListItem == NULL)
      { UNITY_TEST_ASSERT_NULL(pxNewListItem, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxNewListItem), (void*)(pxNewListItem), sizeof(ListItem_t), cmock_call_instance->Expected_pxNewListItem_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_vListInsert(CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance, List_t* const pxList, int pxList_Depth, ListItem_t* const pxNewListItem, int pxNewListItem_Depth)
{
  cmock_call_instance->Expected_pxList = pxList;
  cmock_call_instance->Expected_pxList_Depth = pxList_Depth;
  cmock_call_instance->IgnoreArg_pxList = 0;
  cmock_call_instance->Expected_pxNewListItem = pxNewListItem;
  cmock_call_instance->Expected_pxNewListItem_Depth = pxNewListItem_Depth;
  cmock_call_instance->IgnoreArg_pxNewListItem = 0;
}

void vListInsert_CMockIgnore(void)
{
  Mock.vListInsert_IgnoreBool = (char)1;
}

void vListInsert_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInsert_CALL_INSTANCE));
  CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsert_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInsert_CallInstance = CMock_Guts_MemChain(Mock.vListInsert_CallInstance, cmock_guts_index);
  Mock.vListInsert_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void vListInsert_CMockExpect(UNITY_LINE_TYPE cmock_line, List_t* const pxList, ListItem_t* const pxNewListItem)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInsert_CALL_INSTANCE));
  CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsert_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInsert_CallInstance = CMock_Guts_MemChain(Mock.vListInsert_CallInstance, cmock_guts_index);
  Mock.vListInsert_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInsert(cmock_call_instance, pxList, 1, pxNewListItem, 1);
}

void vListInsert_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, List_t* const pxList, int pxList_Depth, ListItem_t* const pxNewListItem, int pxNewListItem_Depth)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInsert_CALL_INSTANCE));
  CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsert_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInsert_CallInstance = CMock_Guts_MemChain(Mock.vListInsert_CallInstance, cmock_guts_index);
  Mock.vListInsert_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInsert(cmock_call_instance, pxList, pxList_Depth, pxNewListItem, pxNewListItem_Depth);
}

void vListInsert_CMockIgnoreArg_pxList(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsert_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.vListInsert_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxList = 1;
}

void vListInsert_CMockIgnoreArg_pxNewListItem(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_vListInsert_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsert_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.vListInsert_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxNewListItem = 1;
}

void vListInsertEnd(List_t* const pxList, ListItem_t* const pxNewListItem)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_vListInsertEnd);
  cmock_call_instance = (CMOCK_vListInsertEnd_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.vListInsertEnd_CallInstance);
  Mock.vListInsertEnd_CallInstance = CMock_Guts_MemNext(Mock.vListInsertEnd_CallInstance);
  if (Mock.vListInsertEnd_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_pxList)
  {
    UNITY_SET_DETAILS(CMockString_vListInsertEnd,CMockString_pxList);
    if (cmock_call_instance->Expected_pxList == NULL)
      { UNITY_TEST_ASSERT_NULL(pxList, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxList), (void*)(pxList), sizeof(List_t), cmock_call_instance->Expected_pxList_Depth, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_pxNewListItem)
  {
    UNITY_SET_DETAILS(CMockString_vListInsertEnd,CMockString_pxNewListItem);
    if (cmock_call_instance->Expected_pxNewListItem == NULL)
      { UNITY_TEST_ASSERT_NULL(pxNewListItem, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxNewListItem), (void*)(pxNewListItem), sizeof(ListItem_t), cmock_call_instance->Expected_pxNewListItem_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_vListInsertEnd(CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance, List_t* const pxList, int pxList_Depth, ListItem_t* const pxNewListItem, int pxNewListItem_Depth)
{
  cmock_call_instance->Expected_pxList = pxList;
  cmock_call_instance->Expected_pxList_Depth = pxList_Depth;
  cmock_call_instance->IgnoreArg_pxList = 0;
  cmock_call_instance->Expected_pxNewListItem = pxNewListItem;
  cmock_call_instance->Expected_pxNewListItem_Depth = pxNewListItem_Depth;
  cmock_call_instance->IgnoreArg_pxNewListItem = 0;
}

void vListInsertEnd_CMockIgnore(void)
{
  Mock.vListInsertEnd_IgnoreBool = (char)1;
}

void vListInsertEnd_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInsertEnd_CALL_INSTANCE));
  CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsertEnd_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInsertEnd_CallInstance = CMock_Guts_MemChain(Mock.vListInsertEnd_CallInstance, cmock_guts_index);
  Mock.vListInsertEnd_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void vListInsertEnd_CMockExpect(UNITY_LINE_TYPE cmock_line, List_t* const pxList, ListItem_t* const pxNewListItem)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInsertEnd_CALL_INSTANCE));
  CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsertEnd_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInsertEnd_CallInstance = CMock_Guts_MemChain(Mock.vListInsertEnd_CallInstance, cmock_guts_index);
  Mock.vListInsertEnd_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInsertEnd(cmock_call_instance, pxList, 1, pxNewListItem, 1);
}

void vListInsertEnd_CMockExpectWithArray(UNITY_LINE_TYPE cmock_line, List_t* const pxList, int pxList_Depth, ListItem_t* const pxNewListItem, int pxNewListItem_Depth)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_vListInsertEnd_CALL_INSTANCE));
  CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsertEnd_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.vListInsertEnd_CallInstance = CMock_Guts_MemChain(Mock.vListInsertEnd_CallInstance, cmock_guts_index);
  Mock.vListInsertEnd_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_vListInsertEnd(cmock_call_instance, pxList, pxList_Depth, pxNewListItem, pxNewListItem_Depth);
}

void vListInsertEnd_CMockIgnoreArg_pxList(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsertEnd_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.vListInsertEnd_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxList = 1;
}

void vListInsertEnd_CMockIgnoreArg_pxNewListItem(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_vListInsertEnd_CALL_INSTANCE* cmock_call_instance = (CMOCK_vListInsertEnd_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.vListInsertEnd_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxNewListItem = 1;
}

UBaseType_t uxListRemove(ListItem_t* const pxItemToRemove)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_uxListRemove);
  cmock_call_instance = (CMOCK_uxListRemove_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.uxListRemove_CallInstance);
  Mock.uxListRemove_CallInstance = CMock_Guts_MemNext(Mock.uxListRemove_CallInstance);
  if (Mock.uxListRemove_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.uxListRemove_FinalReturn;
    memcpy((void*)(&Mock.uxListRemove_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(UBaseType_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(UBaseType_t) ? 1 : -1])); /* add UBaseType_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_pxItemToRemove)
  {
    UNITY_SET_DETAILS(CMockString_uxListRemove,CMockString_pxItemToRemove);
    if (cmock_call_instance->Expected_pxItemToRemove == NULL)
      { UNITY_TEST_ASSERT_NULL(pxItemToRemove, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY((void*)(cmock_call_instance->Expected_pxItemToRemove), (void*)(pxItemToRemove), sizeof(ListItem_t), cmock_call_instance->Expected_pxItemToRemove_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_uxListRemove(CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance, ListItem_t* const pxItemToRemove, int pxItemToRemove_Depth)
{
  cmock_call_instance->Expected_pxItemToRemove = pxItemToRemove;
  cmock_call_instance->Expected_pxItemToRemove_Depth = pxItemToRemove_Depth;
  cmock_call_instance->IgnoreArg_pxItemToRemove = 0;
}

void uxListRemove_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, UBaseType_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uxListRemove_CALL_INSTANCE));
  CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance = (CMOCK_uxListRemove_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uxListRemove_CallInstance = CMock_Guts_MemChain(Mock.uxListRemove_CallInstance, cmock_guts_index);
  Mock.uxListRemove_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.uxListRemove_IgnoreBool = (char)1;
}

void uxListRemove_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, UBaseType_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uxListRemove_CALL_INSTANCE));
  CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance = (CMOCK_uxListRemove_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uxListRemove_CallInstance = CMock_Guts_MemChain(Mock.uxListRemove_CallInstance, cmock_guts_index);
  Mock.uxListRemove_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void uxListRemove_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, ListItem_t* const pxItemToRemove, UBaseType_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uxListRemove_CALL_INSTANCE));
  CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance = (CMOCK_uxListRemove_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uxListRemove_CallInstance = CMock_Guts_MemChain(Mock.uxListRemove_CallInstance, cmock_guts_index);
  Mock.uxListRemove_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_uxListRemove(cmock_call_instance, pxItemToRemove, 1);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(UBaseType_t[sizeof(cmock_to_return) == sizeof(UBaseType_t) ? 1 : -1])); /* add UBaseType_t to :treat_as_array if this causes an error */
}

void uxListRemove_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, ListItem_t* const pxItemToRemove, int pxItemToRemove_Depth, UBaseType_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_uxListRemove_CALL_INSTANCE));
  CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance = (CMOCK_uxListRemove_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.uxListRemove_CallInstance = CMock_Guts_MemChain(Mock.uxListRemove_CallInstance, cmock_guts_index);
  Mock.uxListRemove_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_uxListRemove(cmock_call_instance, pxItemToRemove, pxItemToRemove_Depth);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void uxListRemove_CMockIgnoreArg_pxItemToRemove(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_uxListRemove_CALL_INSTANCE* cmock_call_instance = (CMOCK_uxListRemove_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.uxListRemove_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_pxItemToRemove = 1;
}

