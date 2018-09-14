#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
typedef int ElemType;
struct QueNode {
	ElemType data;
	QueNode *next;
};
typedef QueNode* QueList;
struct LinkQueue {
	QueList front;
	QueList rear;
};
int n;
int main()
{
	void InitQueue(LinkQueue &, ElemType);
	bool EnQueue(LinkQueue &, ElemType);
	bool EmptyQueue(LinkQueue &);
	ElemType DeQueue(LinkQueue &);
	int GetLengthQueue(LinkQueue &);
	void PrintQueue(LinkQueue &);

	LinkQueue lq;
	char order[10];
	int num;
	scanf("%d", &n);
	InitQueue(lq,n);
	while (scanf("%s", order) != '\0' && strcmp(order, "quit")) {
		if (!strcmp(order, "dequeue")) {
			num = DeQueue(lq);
			if (num < 0)
				printf("Queue is Empty\n");
			else
				printf("%d\n", num);
		}
		else if (!strcmp(order, "enqueue")) {
			scanf("%d", &num);
			if(!EnQueue(lq, num))
				printf("Queue is Full\n");
		}
	}
	PrintQueue(lq);
}

void InitQueue(LinkQueue &lq, int n)
{
	lq.front = lq.rear = (QueList)malloc(n * sizeof(QueNode));
	lq.front->next = NULL;
}
bool EmptyQueue(LinkQueue &lq)
{
	return (lq.front == lq.rear) ? true : false;
}
int GetLengthQueue(LinkQueue &lq)
{
	QueList p = lq.front;
	int len = 0;
	while (p != lq.rear) {
		len++;
		p = p->next;
	}
	return len;
}
bool EnQueue(LinkQueue &lq, ElemType e)
{
	int len = GetLengthQueue(lq);
	if (len >= n)
		return false;
	QueList p = (QueList)malloc(sizeof(QueNode));
	p->data = e;
	p->next = NULL;
	lq.rear->next = p;
	lq.rear = p;
	return true;
}
ElemType DeQueue(LinkQueue &lq)
{
	QueList p;
	ElemType rtn;
	if (lq.front == lq.rear)
		return -1;
	rtn = lq.front->next->data;
	p = lq.front;
	lq.front = lq.front->next;
	free(p);
	return rtn;
}
void PrintQueue(LinkQueue &lq)
{
	QueList p = lq.front->next;
	if (lq.front == lq.rear) {
		printf("\n");
		return;
	}
	printf("%d", p->data);
	while (p->next) {
		p = p->next;
		printf(" %d", p->data);
	}
	putchar('\n');
}