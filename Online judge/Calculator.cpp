#include <iostream>
#include <string>
//#include <Windows.h>
#include <map>
#define _STACK_SIZE 1000
#define _INC_STACK_SIZE 20
using namespace std;
typedef int ElemType;
struct Stack {
	ElemType *base;
	ElemType *top;
	int stackSize;
};
string str;
map <char, int> M;
int main()
{
	//cout << (5 > 3 && 2 || 8 < 4 - !0) << endl;
	void InitStack(Stack &);
	void PushStack(Stack &, ElemType);
	void ClearStack(Stack &);
	void PrintStack(Stack &);
	void DestroyStack(Stack &);
	void InverStack(Stack &);
	int GetSizeStack(Stack &);
	ElemType GetTopStack(Stack &);
	ElemType PopStack(Stack &);
	bool CalcStr(string &, Stack &, Stack &);

	Stack optr, opnd;
	M['+'] = M['-'] = 1;
	M['*'] = M['/'] = 2;
	M['('] = M[')'] = 3;
	M['='] = 0;
	//while (true) {
		InitStack(opnd);
		InitStack(optr);
		std::cin >> str;
		if (CalcStr(str, optr, opnd))
	//		system("cls");
	//		std::cout << str;
			printf("%d\n", PopStack(opnd));
		else
			printf("ERROR\n");
	//}
	//8-4*1-5*2=
	//10+15/5=5
	return 0;
}
void InitStack(Stack &S)
{
	S.base = (ElemType*)malloc(_STACK_SIZE * sizeof(Stack));
	S.top = S.base;
	S.stackSize = _STACK_SIZE;
}
void PushStack(Stack &S, ElemType e)
{
	if (S.top - S.base >= S.stackSize) {
		S.base = (ElemType*)realloc(S.base, (_STACK_SIZE + _INC_STACK_SIZE) * sizeof(Stack));
		S.stackSize = _STACK_SIZE + _INC_STACK_SIZE;
		S.top = S.base + S.stackSize;
	}
	*(S.top) = e;
	S.top++;
}
ElemType PopStack(Stack &S)
{
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
void ClearStack(Stack &S)
{
	S.top = S.base;
}
void DestroyStack(Stack &S)
{
	ClearStack(S);
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stackSize = 0;
}
int GetSizeStack(Stack &S)
{
	return S.top - S.base;
}
void InverStack(Stack &S)
{
	Stack S_tmp;
	InitStack(S_tmp);
	while(!EmptyStack(S))
		PushStack(S_tmp, PopStack(S));
	DestroyStack(S);
	S.base = S_tmp.base;
	S.top = S_tmp.top;
	S.stackSize = S_tmp.stackSize;
}
bool CalcStr(string &str, Stack &optr, Stack &opnd)
{
	ElemType *e = (ElemType*)malloc(sizeof(ElemType));
	bool CalcNum(int, int, char, ElemType *);
	int num = 0;
	for (int i = 0; i < int(str.length());i++) {
		if (str[i] <= '9' && str[i] >= '0') {
			num *= 10;
			num += str[i] - '0';
		}
		else if (str[i] == ' ')
			continue;
		else {
			ElemType tmp;
			PushStack(opnd, num);
			num = 0;
			if (!EmptyStack(optr)) {
				tmp = GetTopStack(optr);
				if(M[str[i]] > M[tmp])
					PushStack(optr, str[i]);
				else {	
					ElemType num2 = PopStack(opnd);
					ElemType num1 = PopStack(opnd);
					bool flag = CalcNum(num1, num2, tmp, e);
					if (!flag)
						return false;
					PushStack(opnd, *e);
					PopStack(optr);
					if (str[i] == '=') 
						break;
					else
						PushStack(optr, str[i]);
				}
			}
			else
				PushStack(optr, str[i]);
		}
	}
	InverStack(opnd);
	InverStack(optr);
	while (!EmptyStack(optr)) {
		ElemType num1 = PopStack(opnd);
		ElemType num2 = PopStack(opnd);
		ElemType opt = PopStack(optr);
		bool flag = CalcNum(num1, num2, opt, e);
		if (!flag)
			return false;
		PushStack(opnd, *e);
	}
	return true;
}
bool CalcNum(int num1, int num2, char opt, ElemType* e)
{
	int rtn;
	switch (opt) {
		case('+'):
			rtn = num1 + num2; break;
		case('*'):
			rtn = num1 * num2; break;
		case('-'):
			rtn = num1 - num2; break;
		case('/'):
			if(!num2)
				return false;
			rtn = num1 / num2; break;
		default: break;
	}
	*e = rtn;
	return true;
}
