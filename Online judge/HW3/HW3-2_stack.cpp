#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#define _STACK_SIZE 1000
#define _INC_STACK_SIZE 20
typedef int ElemType;
struct Stack {
	ElemType *base;
	ElemType *top;
	int stackSize;
};
int main()
{
	void InitStack(Stack &);
	void PushStack(Stack &, ElemType);
	ElemType PopStack(Stack &);
	void ClearStack(Stack &);
	void PrintStack(Stack &);
	ElemType GetTopStack(Stack &);
	int CalcFrom(string str, int, int);
	string CalcTo(int, int, int);

	string str="", ans;
	int from, to;
	scanf("%d%d", &from, &to);
	cin >> str;
	int mid = CalcFrom(str, from, to);
	ans = CalcTo(mid, from, to);
	cout << ans << endl;
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
void ClearStack(Stack &S)
{
	S.top = S.base;
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
string CalcTo(int mid, int from, int to)
{
	string str = "";
	Stack sk;
	int temp;
	InitStack(sk);
	while (mid) {
		PushStack(sk, mid % to);
		mid /= to;
	}
	while (!EmptyStack(sk)) {
		temp = PopStack(sk);
		if (temp >= 10)
			str += (temp - 10 + 'A' );
		else
			str += (temp + '0');
	}
	return str;
}
int CalcFrom(string str, int from, int to)
{
	int ans = 0, temp;
	for (int i = 0; i < str.length();i++) {
		ans *= from;
		if (!(str[i] <= '9' && str[i] >= '0')) {
			if (str[i] <= 'Z')
				temp = str[i] - 'A' + 10;
			else
				temp = str[i] - 'a' + 10;
		}
		else
			temp = str[i] - '0';
		ans += temp;
	}
	return ans;
}