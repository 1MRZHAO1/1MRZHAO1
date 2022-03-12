#pragma once
#include<stdio.h>
#include<stdlib.h>
//结点
typedef int SListDataType;
 typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;

}SListNode;
 SListNode* BuySListNode(SListDataType x);
 void SListPushBack(SListNode** pphead, SListDataType x);
 void SListPopBack(SListNode** pphead);
 void SListPushFront(SListNode** pphead, SListDataType x);
 void SListPopFront(SListNode** pphead);
 SListNode* SListFind(SListNode** pphead, SListDataType x);
 void SListPrint(SListNode* phead);
