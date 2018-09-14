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
	int InitList(LinkList &);
	void SearchList(LinkList &, int);
	LinkList lk;
	int k = InitList(lk);
	SearchList(lk, k);

	return 0;
}
int InitList(LinkList &L)
{
	LinkList p;
	int n, t;

	L = (LinkList)malloc(sizeof(NodeList));
	L->next = NULL;
	p = L;
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++){
		scanf("%d", &t);
		LinkList temp = (LinkList)malloc(sizeof(NodeList));
		temp->data = t;
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	return n;
}
void SearchList(LinkList &L, int k)
{
	void PrintList(LinkList &);
	int n, flag = false;
	scanf("%d", &n);
	LinkList p = L->next, pre = L;
/*
	if (k == 1 && p->data == n) {
		putchar('\n');
		return;
	}
*/
	while (p) {
		if (p->data == n) {
			pre->next = p->next;
			p = p->next;
			flag = true;
			continue;
		}
		pre = p;
		p = p->next;
	}
	if (flag)
		PrintList(L);
	else
		printf("-1\n");
}
void PrintList(LinkList &L)
{
	LinkList p = L->next;
	if (!p) {
		printf("\n");
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