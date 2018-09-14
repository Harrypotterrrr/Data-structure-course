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
	LinkList MergeList(LinkList &, LinkList &);
	void PrintList(LinkList &);

	LinkList la, lb, lc;
	InitList(la);
	InitList(lb);
	lc = MergeList(la, lb);
	PrintList(lc);
	return 0;
}
void InitList(LinkList &L)
{
	LinkList p;
	int n;
	L = (LinkList)malloc(sizeof(NodeList));
	p = L;
	while (scanf("%d", &n) && n) {
		LinkList temp = (LinkList)malloc(sizeof(NodeList));
		temp->data = n;
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
}

LinkList MergeList(LinkList &la, LinkList &lb)
{
	void InsertList(LinkList &, LinkList &);
	LinkList head;
	head = (LinkList)malloc(sizeof(NodeList));
	head->next = NULL;
	InsertList(head, la);
	InsertList(head, lb);
	return head;
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