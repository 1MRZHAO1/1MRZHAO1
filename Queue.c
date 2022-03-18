#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
//队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//队头出
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//1.1个
	//2.多个
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head=pq->tail= NULL;
	}
		QNode* next= pq->head->next;
	free(pq->head);
	pq->head = next;

}
//判顶队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);//为空不能调用，访问空指针了
	return pq->head->data;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->data;
}
//获取队列大小
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	//遍历来计算大小
	QNode* cur = pq->head;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size; 

}
//销毁队列
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{   
		QNode* next= cur->next;
		free(cur);
		cur = next;
	}
	pq->tail = pq->head = NULL;
}
