#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int ElemList;
struct NodeList {
	ElemList data;
	NodeList *next;
};
typedef NodeList* LinkList;
int main()
{
	void InitList(LinkList &);
	void MergeList(LinkList &, LinkList &);
	void PrintList(LinkList &);

	LinkList la, lb;
	InitList(la);
	InitList(lb);
	MergeList(la, lb);
	PrintList(la);
	return 0;
}
void InitList(LinkList &L)
{
	LinkList p = L;
	int n;
	L = (LinkList)malloc(sizeof(NodeList));
	L->next = NULL;
	while (scanf("%d", &n) && n) {
		LinkList temp = (LinkList)malloc(sizeof(NodeList));
		temp->data = n;	
		temp->next = NULL;
		p = L;
		while (p->next && p->next->data < n)
			p = p->next;
		temp->next = p->next;
		p->next = temp;
		p = p->next;
	}
}

void MergeList(LinkList &la, LinkList &lb)
{
	void InsertList(LinkList &, LinkList &);
	InsertList(la, lb);
}
void InsertList(LinkList &head, LinkList &L)
{
	LinkList p = head, q = L->next;
	while (q) {
		LinkList temp = (LinkList)malloc(sizeof(NodeList));
		temp->data = q->data;
		temp->next = NULL;
		p = head;
		while (p->next && p->next->data < q->data)
			p = p->next;
		temp->next = p->next;
		p->next = temp;
		q = q->next;
	}
}
void PrintList(LinkList &L)
{
	LinkList p = L->next;
	if (!p) {
		printf("-1\n");
		return;
	}
	printf("%d", p->data);
	p = p->next;
	while (p) {
		printf(" %d", p->data);
		p = p->next;
	}
	putchar('\n');
}