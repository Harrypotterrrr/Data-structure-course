#define _CRT_SECURE_NO_WARNINGS
#define Stack_Init_Length 1000
#define Stack_Incr_Length 10
#include <iostream>
#include <cstring>
using namespace std;
typedef char ElemType;
struct Stack {
	ElemType *top;
	ElemType *base;
	int stackSize;
};
int main()
{
	void InitStack(Stack &);
	void PushStack(Stack &, ElemType *);
	void PopStack(Stack &);
	ElemType GetTopStack(Stack &);
	bool EmptyStack(Stack &);
	Stack sk;
	ElemType temp;
	char str[1000], get;
	InitStack(sk);
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			if (str[i] == '{' ||str[i] == '[' || str[i] == '(')
				PushStack(sk, &str[i]);

			else if (str[i] == '}') {
				if (EmptyStack(sk)) {
					printf("no\n}ÆÚ´ý×óÀ¨ºÅ\n");
					return 0;
				}
				else {
					get = GetTopStack(sk);
					if (get == '{')
						PopStack(sk);
					else {
						printf("no\n%cÆÚ´ýÓÒÀ¨ºÅ\n", get);
						return 0;
					}
				}
			}

			else if (str[i] == ']') {
				if (EmptyStack(sk)) {
					printf("no\n]ÆÚ´ý×óÀ¨ºÅ\n");
					return 0;
				}
				else {
					get = GetTopStack(sk);
					if (get == '[')
						PopStack(sk);
					else {
						printf("no\n%cÆÚ´ýÓÒÀ¨ºÅ\n", get);
						return 0;
					}
				}
			}

			else if (str[i] == ')') {
				if (EmptyStack(sk)) {
					printf("no\n)ÆÚ´ý×óÀ¨ºÅ\n");
					return 0;
				}
				else {
					get = GetTopStack(sk);
					if (get == '(')
						PopStack(sk);
					else {
						printf("no\n%cÆÚ´ýÓÒÀ¨ºÅ\n", get);
						return 0;
					}

				}
			}
	}
	if (!EmptyStack(sk)) {
		if(GetTopStack(sk) == '{')
			printf("no\n{ÆÚ´ýÓÒÀ¨ºÅ\n");
		else if (GetTopStack(sk) == '(')
			printf("no\n(ÆÚ´ýÓÒÀ¨ºÅ\n");
		else if (GetTopStack(sk) == '[')
			printf("no\n[ÆÚ´ýÓÒÀ¨ºÅ\n");
	}
	else
		printf("yes\n");
	return 0;
}
void InitStack(Stack &L)
{
	L.stackSize = Stack_Init_Length;
	L.base = (ElemType*)malloc(Stack_Init_Length * sizeof(ElemType));
	L.top = L.base;
}
void PushStack(Stack &L, ElemType *e)
{
	if (L.top - L.base >= L.stackSize) {
		L.base = (ElemType*)realloc(L.base,(Stack_Init_Length + Stack_Incr_Length) * sizeof(ElemType));
		L.top = L.base + L.stackSize;
		L.stackSize += Stack_Incr_Length;
	}
	*L.top = *e;
	L.top++;
}
void PopStack(Stack &L)
{
	if (L.top == L.base)
		return;
	L.top--;
}
bool EmptyStack(Stack &L)
{
	return L.top == L.base ? true : false;
}
ElemType GetTopStack(Stack &L)
{
	return *(L.top - 1);
}