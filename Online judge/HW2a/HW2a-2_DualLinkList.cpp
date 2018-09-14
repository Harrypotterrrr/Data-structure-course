#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef int ElemType;
struct NodeList {
	ElemType data;
	NodeList *next;
	NodeList *pre;
};
typedef NodeList* LinkList;
int main()
{
	LinkList InitList_Head(LinkList &,int);
	void InitList_Rear(LinkList &, LinkList &, int);
	void CreatList(LinkList &, LinkList &);
	void PrintList(LinkList &, LinkList &);
	void PrintBackThreeMult(LinkList &,LinkList &);
	void DeleteList(LinkList &, LinkList &);
	LinkList L_head, L_rear;
	int n;
	scanf("%d", &n);
	CreatList(L_head, L_rear);
	InitList_Rear(L_head, L_rear, n);
	DeleteList(L_head, L_rear);
	return 0;
}
void CreatList(LinkList &head, LinkList &rear)
{
	head = (LinkList)malloc(sizeof(NodeList));
	rear = (LinkList)malloc(sizeof(NodeList));
	head->next = rear;
	rear->pre = head;
	head->pre = NULL;
	rear->next = NULL;
}
LinkList InitList_Head(LinkList &head, int n)
{
	LinkList q, rear;
	rear = head->next;
	for (int i = 1; i <= n; i++) {
		q = (LinkList)malloc(sizeof(NodeList));
		scanf("%d", &q->data);
		q->next = head->next;
		head->next->pre = q;
		head->next = q;
		q->pre = head;
	}
	return rear;
}
void InitList_Rear(LinkList &head, LinkList &rear, int n)
{
	LinkList p, q;
	p = head;
	for (int i = 1; i <= n; i++) {
		q = (LinkList)malloc(sizeof(NodeList));
		scanf("%d", &q->data);
		p->next = q;
		q->pre = p;
		p = p->next;
	}
	rear->pre = p;
	p->next = rear;
}
void DeleteList(LinkList &head, LinkList &rear)
{
	void PrintList(LinkList &, LinkList &);
	LinkList p = head->next, q = head, del;
	int temp, flag = 1;
	scanf("%d", &temp);
	while (p != rear) {
		if (p->data == temp) {
			flag = 0;
			q->next = p->next;
			p->next->pre = q;
			del = p;
			p = p->next;
			free(del);
		}
		else {
			q = p;
			p = p->next;
		}
	}
	if (flag)
		printf("-1\n");
	else
		PrintList(head, rear);
}
void PrintBackThreeMult(LinkList &head,LinkList &rear)
{
	LinkList p = rear->pre;
	bool flag = true;
	while (p != head) {
		if (!(p->data % 3) && flag) {
			printf("%d", p->data);
			flag = false;
		}
		else if (!(p->data % 3))
			printf(" %d", p->data);
		p = p->pre;
	}
}
void PrintList(LinkList &head, LinkList &rear)
{
	LinkList p = head->next;
	if (p == rear) {
		printf("\n");
		return;
	}
	printf("%d", p->data);
	p = p->next;
	while (p != rear) {
		printf(" %d", p->data);
		p = p->next;
	}
	putchar('\n');
}