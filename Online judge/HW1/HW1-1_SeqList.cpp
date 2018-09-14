#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 1000
#define LIST_INCR_SIZE 15
using namespace std;
typedef int ElemList;
typedef struct {
	ElemList *data;
	int length;
	int listSize;
}SeqList;
void PrintList(SeqList &, bool);
int main()
{
	void InitList(SeqList &, int);
	void InsertList(SeqList &, int);
	void DeleteList(SeqList &,int);
	void FindList(SeqList &,int);
	SeqList sq;
	int n,k;

	scanf("%d", &n);
	InitList(sq, n);


	scanf("%d", &k);
	InsertList(sq, k);

	scanf("%d", &k);
	DeleteList(sq, k);

	scanf("%d", &k);
	FindList(sq, k);
	return 0;

}
void InitList(SeqList &L,int n)
{
	if (!n)
		return;
	L.data = (ElemList*)malloc((n+1)*sizeof(ElemList));
	L.length = n;
	L.listSize = LIST_INIT_SIZE;
	for (int i = 1; i <= n; i++)
		scanf("%d", L.data+i);
	PrintList(L, true);
}
void InsertList(SeqList &L,int n)
{
	ElemList nw,*p,*q;
	scanf("%d", &nw);
	if (n<1 || n>L.length) {
		PrintList(L, false);
		return;
	}
	ElemList *newBase = (ElemList*)realloc(L.data,(L.length + 1) * sizeof(ElemList));
	L.data = newBase;
	p = L.data + L.length;
	for (q = L.data + n;p >= q;p--)
		*(p + 1) = *p;
	*q = nw;
	L.length++;
	PrintList(L, true);
}
void DeleteList(SeqList &L,int n)
{
	ElemList *p,*q;
	if (n<1 || n>L.length) {
		PrintList(L, false);
		return;
	}
	p = L.data + n;
	for (q = L.data + L.length;p < q;p++)
		*p = *(p + 1);
	L.length--;
	PrintList(L, true);
}
void FindList(SeqList &L,int y)
{
	ElemList *p = L.data;
	for(int i=1 ; i<=L.length;i++)
		if (*(p+i) == y) {
			printf("%d\n", i);
			return;
		}
	printf("-1\n");
}
void PrintList(SeqList &L,bool flag)
{
	if (L.length < 1 || !flag) {
		printf("-1\n");
		return;
	}
	printf("%d", *(L.data + 1));
	for (int i = 2; i <= L.length ; i++)
		printf(" %d", *(L.data + i));
	putchar('\n');
}