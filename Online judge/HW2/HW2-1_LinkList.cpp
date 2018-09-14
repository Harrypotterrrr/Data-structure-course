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
	bool InsertList(LinkList &,ElemList);
	bool DeleteList(LinkList &,ElemList);
	int SearchList(LinkList &, ElemList);
	void PrintNum(LinkList &);
	void PrintList(LinkList &);
	LinkList lk;
	int temp;
	InitList(lk);
	PrintList(lk);
	scanf("%d", &temp);
	if (InsertList(lk, temp))
		PrintList(lk);
	else
		printf("-1\n");
	scanf("%d", &temp);
	if (DeleteList(lk, temp))
		PrintList(lk);
	else
		printf("-1\n");
	scanf("%d", &temp);
	printf("%d\n", SearchList(lk, temp));
	PrintNum(lk);
	return 0;
}

void InitList(LinkList &L)
{
	int temp;
	L = (NodeList*)malloc(sizeof(NodeList));
	L->next = NULL;
	scanf("%d", &temp);
	for (int i = 1; i <= temp; i++) {
		LinkList q = (NodeList *)malloc(sizeof(NodeList));
		scanf("%d", &q->data);
		q->next = L->next;
		L->next = q;
	}
}
bool InsertList(LinkList &L, ElemList k)
{
	LinkList p = L, q;
	ElemList temp;
	scanf("%d", &temp);
	if (k < 1)
		return false;
	k--;
	while (k-- && p->next)//注意第5个位置！！
		p = p->next;
	if (!p->next)
		return false;
	q = (NodeList*)malloc(sizeof(NodeList));
	q->data = temp;
	q->next = p->next;
	p->next = q;
	return true;
}
bool DeleteList(LinkList &L,ElemList k)
{
	LinkList p = L, q;
	if (k < 1)
		return false;
	k--;
	while (p->next && k--)
		p = p->next;
	if (p->next == NULL)
		return false;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
int SearchList(LinkList &L,ElemList e)
{
	LinkList p = L->next;
	int t = 1;
	while (p) {
		if (p->data == e)
			return t;
		t++;
		p = p->next;
	}
	if (!p)
		return -1;
}
void PrintNum(LinkList &L)
{
	LinkList p = L->next;
	int ans = 0;
	while (p) {
		ans++;
		p = p->next;
	}
	printf("%d\n", ans);
}
void PrintList(LinkList &L)
{
	LinkList p = L->next;
	printf("%d", p->data);
	p = p->next;
	while (p) {
		printf(" %d", p->data);
		p = p->next;
	}
	putchar('\n');
}