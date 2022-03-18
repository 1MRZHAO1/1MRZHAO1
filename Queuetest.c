#include "Queue.h"


//测试时，想遍历存入的所有数据，必须边队出，边遍历，否则将一直读取队头那一个数据


void TestQueue()
{
	Queue q;//专门申请一个结构体用来存放队头指针head，队尾指针tail，这两个指针是脱离单链表之外的，专门用来对单链表进行操作
	QueueInit(&q);
	QueuePush(&q, 1);
    QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d", QueueFront(&q));
		QueuePop(&q);
	}
}
                          




int main()
{

	TestQueue();

}
