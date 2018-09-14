#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SEQ_LENGTH 1000005
#define SEQ_REP_LENGTH 10005
using namespace std;
typedef int ElemList;
struct SeqList {
	ElemList *data;
	int length;
};
int main()
{
	SeqList sq, ans, rep;
	ElemList *p, *q, *r, *last, *last_ans;
	int n, flag = false;
	sq.data = (ElemList*)malloc(SEQ_LENGTH * sizeof(ElemList));
	ans.data = (ElemList*)malloc(SEQ_LENGTH * sizeof(ElemList));
	rep.data = (ElemList*)malloc(SEQ_REP_LENGTH * sizeof(ElemList));

	scanf("%d", &sq.length);
	last = sq.data + sq.length;

	for (p = sq.data; p < last; p++) {
		scanf("%d", p);
		r = rep.data + *p;
		(*r)++;
	}

	ans.length = 0;
	for (q = ans.data, p = sq.data; p < last; p++) {
		if (*(rep.data + *p)) {
			*q++ = *p;
			ans.length++;
			r = rep.data + *p;
			*r = 0;
		}
	}
	if (ans.length--)
		printf("%d", *(ans.data));
	last_ans = ans.data + ans.length;
	for (q = ans.data + 1; q <= last_ans; q++)
		printf(" %d", *q);
	return 0;
}