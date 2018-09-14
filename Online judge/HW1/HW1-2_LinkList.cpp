#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int ElemList;
struct NodeList{
	ElemList data;
	NodeList *next;
};
typedef NodeList* LinkList;
int main()
{
	void InitList(LinkList &);
	int InsertList(LinkList &,ElemList);
	int DeleteList(LinkList &,ElemList);
	void PrintList(LinkList &, bool);
	LinkList lk;
	int temp;
	InitList(lk);
	scanf("%d", &temp);
	printf("%d\n",InsertList(lk, temp));
	scanf("%d", &temp);
	printf("%d\n",DeleteList(lk,temp));
	PrintList(lk, true);
	return 0;
}

void InitList(LinkList &L)
{
	LinkList p;
	int n;
	L = (LinkList)malloc(sizeof(NodeList));
	L->next = NULL;

	while (scanf("%d", &n) && n) {
		LinkList q = (LinkList)malloc(sizeof(NodeList));
		q->data = n;
		q->next = NULL;
		p = L;
		while (p->next && p->next->data < n)
			p = p->next;
		q->next = p->next;
		p->next = q;
	}
}
int InsertList(LinkList &L ,ElemList k)
{
	LinkList p = L, q = (LinkList)malloc(sizeof(NodeList));
	int i = 1;
	q->data = k;
	q->next = NULL;
	while (p->next && p->next->data < k) {
		p = p->next;
		i++;
	}
	q->next = p->next;
	p->next = q;
	return i;
}
int DeleteList(LinkList &L,ElemList e)
{
	LinkList p = L->next, pre = L;
	int i = 1;
	if (!p)
		return -1;
	while (p->data < e && p->next) {
		pre = p;
		p = p->next;
		i++;
	}
	if (p->data != e)
		return -1;
	pre->next = p->next;
	free(p);
	return i;
}
void PrintList(LinkList &L, bool flag) {
	if (!L->next)
		return;
	LinkList p = L->next;
	printf("%d", p->data);
	p = p->next;
	while (p) {
		printf(" %d", p->data);
		p = p->next;
	}
	putchar('\n');
}