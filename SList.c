#include"SList.h"
//链表的遍历
SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d", cur->data); 
			cur = cur->next;
			   
	}
}
void SListPushBack(SListNode** pphead, SListDataType x)
{

	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;

    }
	else {
        //找到尾tail
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//插入结点
		tail->next = newNode;

	}
	 }
void SListPopBack(SListNode**pphead)
{
	//1、空
	if (*pphead == NULL)
	{
		return;
	}
	//2.一个
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		
	}
	//3.一个以上
	else
	{   //找尾，并保留尾的上一个
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next=NULL;
    }
}
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopFront(SListNode** pphead)
{
	//1.为空则不删
	if (*pphead == NULL)//防止出现空指针被解应用的情况
	{
		return;
	}
	//2.如果有一个节点+//3.如果有一个以上节点
	else
	{
		SListNode* next = (*pphead)->next;//先保存下一个节点的地址，再free释放
		free(*pphead);
		*pphead = next;
	}
}//注意链表中查就可以用来改
//单链表查找
SListNode* SListFind(SListNode**pphead, SListDataType x)
{
	SListNode* cur =*pphead;
	while (cur)//空指针其实就是0
	{
		if (cur->data == x)
		{
			return cur;

		}

	}return NULL;

}
