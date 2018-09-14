#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int ElemType;
struct Stack {
	ElemType *base;
	ElemType *top;
	int stackSize;
};
int main()
{
	void InitStack(Stack &, int n);
	bool PushStack(Stack &, ElemType);
	ElemType PopStack(Stack &);
	void ClearStack(Stack &);
	void PrintStack(Stack &);
	ElemType GetTopStack(Stack &);
	void CalcStr(string &, Stack &, Stack &);
	
	ElemType num;
	Stack sk;
	char order[6];
	int size;
	scanf("%d", &size);
	InitStack(sk, size);
	while (scanf("%s", order) != '\0' && strcmp(order, "quit")) {
		if (!strcmp(order, "pop") == 1) {
			ElemType rcv = PopStack(sk);
			if (rcv < 0)
				printf("Stack is Empty\n");
			else
				printf("%d\n", rcv);
		}
		else if (!strcmp(order, "push") == 1) {
			scanf("%d", &num);
			bool flag = PushStack(sk, num);
			if (!flag)
				printf("Stack is Full\n");
		}
	}
	PrintStack(sk);
	return 0;
}
void InitStack(Stack &S,int n)
{
	S.base = (ElemType*)malloc(n * sizeof(Stack));
	S.top = S.base;
	S.stackSize = n;
}
bool PushStack(Stack &S, ElemType e)
{
	if (S.top - S.base >= S.stackSize) {
		return false;
	}
	*(S.top) = e;
	S.top++;
	return true;
}
void ClearStack(Stack &S)
{
	S.top = S.base;
}
ElemType PopStack(Stack &S)
{
	if (S.top == S.base)
		return -1;
	S.top--;
	return *(S.top);
}
bool EmptyStack(Stack &S)
{
	return (S.top == S.base) ? true : false;
}
ElemType GetTopStack(Stack &S)
{
	ElemType rtn;
	rtn = *(S.top - 1);
	return rtn;
}
void PrintStack(Stack &S)
{
	ElemType *p = S.top-1;
	if (p >= S.base)
		printf("%d", *p--);
	while (p >= S.base)
		printf(" %d", *p--);
	putchar('\n');
}
