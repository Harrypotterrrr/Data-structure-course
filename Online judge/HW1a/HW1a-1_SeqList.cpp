#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SEQ_LENGTH 1000005
using namespace std;
typedef int ElemList;
struct SeqList {
	ElemList *data;
	int length;
};
int main()
{
	SeqList sq, ans;
	ElemList *p, *q, *last;
	int n, flag = false;
	sq.data = (ElemList*)malloc(SEQ_LENGTH * sizeof(ElemList));
	scanf("%d", &sq.length);
	last = sq.data + sq.length;
	for (p = sq.data; p < last; p++) {
		scanf("%d", &*p);
	}
	scanf("%d", &n);
	ans.data = (ElemList*)malloc(SEQ_LENGTH * sizeof(ElemList));
	ans.length = 0;
	for (q = ans.data, p = sq.data; p < last; p++) {
		if (*p != n) {
			*q++ = *p;
			ans.length++;
		}
		else
			flag = true;
	}
	if (!ans.length)
		printf("\n");
	else if (!flag)
		printf("-1\n");
	else {
		q = ans.data;
		printf("%d", *q++);
		ElemList *f = ans.data + ans.length - 1;
		for (; q <= f; q++) {
			printf(" %d", *q);
		}
		putchar('\n');
	}
	return 0;
}