#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;
//队列初始化
void QueueInit(Queue* pq);
//销毁队列
void QueueDestory(Queue* pq);
//队尾入
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);
//队头数据查询
QDataType QueueFront(Queue* pq);
//队尾数据查询
QDataType QueueBack(Queue* pq);
//队列是否为空
bool QueueEmpty(Queue* pq);
//队列目前的数据个数
int QueueSize(Queue* pq);
