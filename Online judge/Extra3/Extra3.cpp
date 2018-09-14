#include <iostream>
#include <string>
#define LIST_LENGTH 1000
#define EMPTY -3
#define FULL -2
#define ERROR -1
#define OK 0
using namespace std;
typedef string ElemType;
int m, n;
struct SLinkList {
	ElemType data;
	int cur;
};
bool IsEmptySLinkList(SLinkList *sll)
{
	return sll[0].cur == -1;
}
bool IsFullSlinkList(SLinkList *sll)
{
	return sll[1].cur == -1;
}
int FindSLinkList(SLinkList *sll, string *x)
{
	int p = sll[0].cur, num = 1;
	while (p != -1 && sll[p].data != *x) {
		p = sll[p].cur;
		num++;
	}
	if (p == -1)
		return -1;
	else
		return num;
}
int AddSLinkList(SLinkList *sll, string *x)
{
	if (IsFullSlinkList(sll))
		return FULL;
	int p = sll[1].cur;			//available pointer
	if (IsEmptySLinkList(sll))
		sll[0].cur = p;
	else {
		int q = sll[0].cur;
		while (sll[q].cur != -1)
			q = sll[q].cur;
		sll[q].cur = p;
	}
	sll[1].cur = sll[p].cur;
	sll[p].data = *x;
	sll[p].cur = -1;
	return OK;
}
int InsertSLinkList(SLinkList *sll, string *x, int k)
{
	if (IsFullSlinkList(sll))
		return FULL;
	int p = sll[0].cur, pre = 0, num = 1;
	while (p != -1 && num != k) {
		pre = p;
		p = sll[p].cur;
		num++;
	}
	if (k < 1)
		return ERROR;
	if (p == -1 && num <= k - 1)
		return ERROR;

	int tmp = sll[1].cur;
	sll[1].cur = sll[tmp].cur;
	sll[tmp].data = *x;
	sll[tmp].cur = p;
	sll[pre].cur = tmp;
}
int DeleteSLinkList(SLinkList *sll, string *e, int k)
{
	if (IsEmptySLinkList(sll))
		return EMPTY;
	int p = sll[0].cur, pre = 0, num = 1;
	while (num < k && p != -1) {
		pre = p;
		p = sll[p].cur;
		num++;
	}
	if (k < 1 || p == -1)
		return ERROR;
	*e = sll[p].data;
	sll[pre].cur = sll[p].cur;
	sll[p].cur = sll[1].cur;
	sll[p].data = "";
	sll[1].cur = p;
	return OK;
}
void InitSLinkList(SLinkList *sll)
{
	for (int i = 1; i < m; i++) {
		sll[i].cur = i + 1;
		sll[i].data = "";
	}
	sll[m - 1].cur = -1;
	sll[0].cur = -1;
}
void PrintWholeSLinkList(SLinkList *sll)
{
	int c = 0;
	for (int i = 0; i < m; i++) {
		cout << i << " : ";
		if (sll[i].data == "" || i == 0 || i == 1)
			cout << "N/A : " << sll[i].cur;
		else
			cout << sll[i].data << " : " << sll[i].cur;

		if (i == m - 1)
			putchar('\n');
		else if (!((i + 1) % 3))
			putchar('\n');
		else
			cout << "\t\t";	
			
	}
}
void PrintOrderSLinkList(SLinkList *sll)
{
	int p = sll[0].cur;
	while (p != -1) {
		if (p == sll[0].cur)
			cout << sll[p].data;
		else
			cout << " " << sll[p].data;
		p = sll[p].cur;
	}
	putchar('\n');
}
int main()
{
	SLinkList sll[LIST_LENGTH];
	string x, e;
	int loc, flag;
	cin >> m >> n;
	InitSLinkList(sll);
	for (int k = 1 ; k <= n ; k++) {
		cin >> x;
		AddSLinkList(sll, &x);
	}
	PrintWholeSLinkList(sll);

	/*          insert            */
		cin >> loc >> x;
		flag = InsertSLinkList(sll, &x, loc);

		if (flag == FULL)
			cout << "FULL\n";
		else if (flag == ERROR)
			cout << "-1\n";
		else 
			PrintOrderSLinkList(sll);

	/*          delete            */
		cin >> loc;
		flag = DeleteSLinkList(sll, &e, loc);
		if(flag == EMPTY)
			cout << "EMPTY\n";
		else if (flag == ERROR)
			cout << "-1\n";
		else
			cout << e << endl;

	/*           find            */
		cin >> x;
		cout << FindSLinkList(sll, &x) << endl;

	/*           add             */
		cin >> x;
		if (AddSLinkList(sll, &x) == FULL)
			cout << "FULL\n";
		else
			PrintOrderSLinkList(sll);
		PrintWholeSLinkList(sll);	
	return 0;
}