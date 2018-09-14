#include <iostream>
#include <string>
//#include <Windows.h>
#include <map>
#define _STACK_SIZE 1000
#define _INC_STACK_SIZE 20
#define _QUEUE_SIZE 1000
#define _INC_QUEUE_SIZE 20
using namespace std;
struct Node {
	int opnd;
	char optr;
	bool flag;
};
typedef Node ElemType;
struct Stack {
	ElemType *base;
	ElemType *top;
	int stackSize;
};
struct QueNode {
	ElemType data;
	QueNode *next;
	QueNode *pre;
};
typedef QueNode* QueList;
struct Queue {
	QueList front;
	QueList rear;
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

	bool CalcStr(string &, Stack &, Queue &);
	bool CalcNum(Stack &, Queue &);

	bool JudgeOptr(ElemType);
	bool JudgeNum(ElemType);

	void InitQueue(Queue &);
	bool EnQueue(Queue &, ElemType);
	bool EmptyQueue(Queue &);
	ElemType DeQueue(Queue &);
	int GetLengthQueue(Queue &);
	ElemType GetFirstQueue(Queue &);

	Queue q;
	Stack s;
	M['+'] = M['-'] = 1;
	M['*'] = M['/'] = 2;
	M['('] = M[')'] = 3;
	M['='] = 0;
	//while (true) {
		InitQueue(q);
		InitStack(s);
		std::cin >> str;
		if (CalcStr(str, s, q)) {
			if(CalcNum(s, q))
				printf("%d\n", PopStack(s));
			else
				printf("ERROR\n");
		}
	//		system("cls");
	//		std::cout << str;
		else
			printf("ERROR\n");
	//}
	//8-4*1-5*2=
	//10+15/5=5
	return 0;
}
void InitQueue(Queue &Q)
{
	Q.front = Q.rear = (QueList)malloc(_QUEUE_SIZE * sizeof(QueNode));
	Q.front->next = NULL;
	Q.front->pre = NULL;
}
bool EmptyQueue(Queue &Q)
{
	return (Q.front == Q.rear) ? true : false;
}
int GetLengthQueue(Queue &Q)
{
	QueList p = Q.front;
	int len = 0;
	while (p != Q.rear) {
		len++;
		p = p->next;
	}
	return len;
}
bool EnQueue(Queue &Q, ElemType e)
{
	QueList p = (QueList)malloc(sizeof(QueNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	p->pre = Q.rear;
	Q.rear = p;
	return true;
}
ElemType DeQueue(Queue &Q)
{
	QueList p;
	ElemType rtn;
	rtn = Q.front->next->data;
	p = Q.front;
	Q.front = Q.front->next;
	Q.front->pre = NULL;
	free(p);
	return rtn;
}
ElemType GetFirstQueue(Queue &Q)
{
	return Q.front->next->data;
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
bool JudgeOptr(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' \
		|| c == '%' || c == '(' || c == ')' )
		return true;
	return false;
}
bool JudgeNum(int n)
{
	return (n >= 0 && n <= 9) ? true : false;
}
bool CalcStr(string &str, Stack &s, Queue &q)
{
	ElemType *e = (ElemType*)malloc(sizeof(ElemType));
	bool CalcNum(int, int, char, ElemType *);
	bool jdg = false;
	ElemType nw;
	for (int i = 0; i < int(str.length()); ) {
		if (str[i] == '=') {
			if (!jdg)
				return false;
			break;
		}
		else if (JudgeNum((str[i] - '0'))) {
			if (jdg)
				return false;
			jdg = !jdg;
			nw.opnd = 0;
			while (JudgeNum((str[i] - '0'))) {
				nw.opnd *= 10;
				nw.opnd += str[i++] - '0';
			}
			nw.flag = true;
			EnQueue(q, nw);
		}
		else if (JudgeOptr(str[i])) {
			nw.flag = false;
			if (str[i] == ')') {
				bool flag = false;
				ElemType temp;
				while (!EmptyStack(s)) {
					temp = PopStack(s);
					if (temp.optr == '(') {
						flag = true;
						break;
					}
					EnQueue(q, temp);
				}
				if (!flag)
					return false;
				i++;
			}
			else {
				if (!jdg && str[i] != '(')
					return false;
				if(str[i] != '(')
					jdg = !jdg;
				while (!EmptyStack(s) && M[str[i]] <= M[GetTopStack(s).optr]) {
					if (GetTopStack(s).optr == '(')
						break;
					EnQueue(q, PopStack(s));
				}
				nw.optr = str[i++];
				PushStack(s, nw);
			}
		}
		else
			return false;
	}
	while (!EmptyStack(s))
		EnQueue(q, PopStack(s));
	return true;
}
bool CalcNum(Stack &s, Queue &q)
{
	Node num1, num2, ans;
	ElemType temp;
	while (!EmptyQueue(q)) {
		temp = DeQueue(q);
		if (temp.flag)
			PushStack(s, temp);
		else {
			num2 = PopStack(s);
			num1 = PopStack(s);
			switch (temp.optr) {
			case('+'):
				ans.opnd = num1.opnd + num2.opnd; 
				break;
			case('*'):
				ans.opnd = num1.opnd * num2.opnd;
				break;
			case('-'):
				ans.opnd = num1.opnd - num2.opnd;
				break;
			case('/'):
				if (!num2.opnd)
					return false;
				ans.opnd = num1.opnd / num2.opnd;
				break;
			case('%'):
				ans.opnd = int(num1.opnd) % int(num2.opnd); 
				break;
			default:
				break;
			}
			PushStack(s, ans);
		}
	}
	return true;
}
