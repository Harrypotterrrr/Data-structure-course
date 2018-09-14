#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#define SUCCESS 1
#define UNSUCCESS 0
#define OK 1
#define FAIL 0
#define ERROR 0
#define Hashtable_SIZE 1000
#define SIGN 0
#define prime 11
double sum = 0;
using namespace std;
typedef int Status;
struct BinaryTree {
	int data;
	BinaryTree * leftchild, *rightchild;
};
typedef BinaryTree* BT;
bool tag2 = false;
Status SearchNode(BT &bt, BT &pre, int v, BT &addr)
{
	if (!bt) {
		addr = pre;
		return FAIL;
	}
	if (bt->data == v) {
		addr = bt;
		return SUCCESS;
	}
	else if (bt->data > v) {
		return SearchNode(bt->leftchild, bt, v, addr);
	}
	else {
		return SearchNode(bt->rightchild, bt, v, addr);
	}
}
void CreateBinaryNode(BT &bt)
{
	//BT p = new BinaryTree;
	BT p = (BT)malloc(sizeof(BinaryTree));
	//BT addr = new BinaryTree;
	BT addr = (BT)malloc(sizeof(BinaryTree));
	cin >> p->data;
	p->rightchild = p->leftchild = NULL;
	SearchNode(bt, bt, p->data, addr);
	if (!addr)
		bt = p;
	else if (p->data > addr->data)
		addr->rightchild = p;
	else
		addr->leftchild = p;
}
bool tag = false;
void DeleteNode(BT &bt, const int num)
{
	if (tag)
		return;
	if (!bt) {
		cout<<"0\n";
		tag = true;
		return;
	}
	else{
		if (bt->data == num) {
			tag = true;
			cout << "1\n";
			//BT q = new BinaryTree;
			BT q = (BT)malloc(sizeof(BinaryTree));
			q = bt;
			if (!bt->rightchild) {
				bt = bt->leftchild;
				delete q;
			}
			else if (!bt->leftchild) {
				bt = bt->rightchild;
				delete q;
			}
			else {
				//BT s = new BinaryTree;
				BT s = (BT)malloc(sizeof(BinaryTree));
				s = bt->leftchild;
				while (s->rightchild) {
					q = s;
					s = s->rightchild;
				}
				bt->data = s->data;
				if (q != bt)
					q->rightchild = s->leftchild;
				else
					q->leftchild = s->leftchild;
				delete s;
			}
		}
		else if (bt->data > num)
			DeleteNode(bt->leftchild,num);
		else
			DeleteNode(bt->rightchild,num);
	}
}
void TransverseTree(BT &bt,int num)
{
	if (!bt)
		return;
	sum += num;
	cout << bt->data << " ";
	if (bt->leftchild)
		TransverseTree(bt->leftchild,num+1);
	if (bt->rightchild)
		TransverseTree(bt->rightchild,num+1);
}
void InsertNode(BT &bt, int num)
{
	//BT p = new BinaryTree;
	BT p = (BT)malloc(sizeof(BinaryTree));
	//BT addr = new BinaryTree;
	BT addr = (BT)malloc(sizeof(BinaryTree));
	p->data = num;
	p->rightchild = p->leftchild = NULL;
	bool flag = SearchNode(bt, bt, p->data, addr);
	if (!flag)
		cout << "0\n";
	else
		cout << "1\n";
	if (p->data > addr->data)
		addr->rightchild = p;
	else
		addr->leftchild = p;
}
int main()
{
	BT bt = NULL;		//IMPORTANT!
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		CreateBinaryNode(bt);
	int num;
	cin >> num;
	DeleteNode(bt, num);
	InsertNode(bt,num);
	TransverseTree(bt,1);
	putchar('\n');
	cout << setiosflags(ios::fixed) << setprecision(2) << sum / n << endl;
	return 0;
}