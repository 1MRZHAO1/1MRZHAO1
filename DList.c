//特点：结构复杂，操作简单
//单链表尾插时不想找尾，可直接在最后一个结点留一个尾指针
//一个结点都没有时，head的next和prev都要指向自己
//写代码的要求，写正确的代码，写效率高的代码，写易懂的代码
//解引用可以连续解 例cur->prev->head但不易读
//一定记住不论怎么操作都不容许将头结点删除
//双向循环列表操作上的优点是无死角，修改时不会出现特例
//两种命名风格
//变量风格  pos_prev posPrev   函数 ListPrint list_print
#include"List.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//刚申请出来的结点，内部指针可能是随机值，应置空
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;                                                                 
}
ListNode* ListInit()
{


	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;


}


void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}


}
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* tail =phead-> prev;//prev指向最后一个结点，tail便是尾结点地址
	ListNode* newnode = BuyListNode(x);
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = phead;
		phead->prev = newnode;
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//还剩一个结点时就不删了
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;

}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	newnode->next = first;
	first->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;

}
//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next!= phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	//phead first second 目的是删除first
	phead->next = second;
	second->prev = phead;
	free(first);
}

//查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{   
	assert(phead);
	assert(phead->next != phead);
	ListNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x);
		return cur;
		cur = cur->next;
	}
	return NULL;//循环一次没找到则返回空

}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* posPrev = pos->prev;
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;

}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
