#include <iostream>
#include <string>
#define LIST_LENGTH 1000
using namespace std;
typedef string ElemType;
int m, n;
struct SLinkList {
	ElemType data;
	int cur;
};
bool IsEmptySLinkList(SLinkList *sll)
{
	return sll[0].cur == -1 ? true : false;
}
bool IsFullSlinkList(SLinkList *sll)
{
	return sll[1].cur == -1 ? true : false;
}
bool FindSLinkList(SLinkList *sll, string *x)
{
	if (IsEmptySLinkList(sll))
		return false;
	int p = sll[0].cur, num = 1;
	while (p != -1 && sll[p].data != *x) {
		p = sll[p].cur;
		num++;
	}
	if (p == -1)
		return false;
	else
		cout << num << endl;
	return true;
}
void InsertSLinkList(SLinkList *sll, string *x, int k)
{
	int p = sll[0].cur, q, num = 1;
	if (k == 1) {
		q = sll[1].cur;
		sll[1].cur = sll[sll[1].cur].cur;
		sll[q].data = *x;
		sll[q].cur = p;
		sll[0].cur = q;
	}
	else {
		while (p != -1 && num != k) {
			q = p;
			p = sll[p].cur;
			num++;
		}
		int nw = sll[1].cur;
		sll[1].cur = sll[sll[1].cur].cur;
		sll[nw].data = *x;
		sll[nw].cur = p;
		sll[q].cur = nw;
	}
	for (int i = 2; i < m;i++)
		if (sll[i].data == "")
			return;
	sll[1].cur = -1;
	return;
}
void DeleteSLinkList(SLinkList *sll, string *e, int k)
{
	int p = sll[0].cur, pre, num = 1;
	if (k == 1) {			//1个元素
		sll[0].cur = sll[p].cur;
		*e = sll[p].data;
		sll[p].data = "";
		sll[p].cur = sll[1].cur;
		sll[1].cur = p;
	}
	else {
		while (num != k && p != -1) {
			pre = p;
			p = sll[p].cur;
			num++;
		}
		/*if (p == -1)
		return false;*/
		*e = sll[p].data;
		sll[pre].cur = sll[p].cur;
		sll[p].cur = sll[1].cur;
		sll[p].data = "";
		sll[1].cur = p;
	}
	if (IsEmptySLinkList(sll))
		sll[0].cur = -1;
}
void AddSLinkList(SLinkList *sll, string *x)
{
	int p = sll[0].cur;
	if (IsEmptySLinkList(sll)) {
		p = sll[1].cur;
		sll[1].cur = sll[sll[1].cur].cur;

		sll[p].data = *x;
		sll[p].cur = -1;
		sll[0].cur = p;
	}
	else {
		while (sll[p].cur != -1)
			p = sll[p].cur;
		sll[p].cur = sll[1].cur;
		sll[1].cur = sll[sll[1].cur].cur;

		p = sll[p].cur;
		sll[p].data = *x;
		sll[p].cur = -1;
	}
	for (int i = 2; i < m; i++)
		if (sll[i].data == "")
			return;
	sll[1].cur = -1;
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
			cout << "		";

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
	int i, j;
	cin >> m >> n;
	InitSLinkList(sll);
	for (int k = 1;k <= n;k++) {
		cin >> x;
		AddSLinkList(sll, &x);
	}
	PrintWholeSLinkList(sll);
	while (true) {
		int choose;
		cout << "===========\n选一个方式:\n1.insert\n2.delete\n3.find\n4.add\n5.print\n===========\n";
		cin >> choose;
		switch (choose) {
			case(1):	
				/*          insert            */
				cin >> i >> x;
				if (IsFullSlinkList(sll))
					cout << "FULL\n";
				else if (i > n+1 || i < 1)
					cout << "-1\n";
				else {
					InsertSLinkList(sll, &x, i);
					n++;
					PrintOrderSLinkList(sll);
				}
				break;
			case(2):
				/*          delete            */
				cin >> j;
				if (IsEmptySLinkList(sll))
					cout << "EMPTY\n";
				else if (j < 1 || j > n)
					cout << "-1\n";
				else {
					DeleteSLinkList(sll, &e, j);
					cout << e << endl;
					n--;
				}
				break;

			case(3):
				/*           find            */
				cin >> x;
				if (IsEmptySLinkList(sll))
					cout << "EMPTY\n";
				else if (!FindSLinkList(sll, &x))
					cout << "-1\n";
				break;

			case(4):
				/*           add             */
				cin >> x;
				if (IsFullSlinkList(sll))
					cout << "FULL\n";
				else {
					AddSLinkList(sll, &x);
					n++;
					PrintOrderSLinkList(sll);
				}
				PrintWholeSLinkList(sll);
				break;
				/*			print			 */		
			case(5):
				PrintOrderSLinkList(sll);
				PrintWholeSLinkList(sll);
		}
	}
	return 0;
}