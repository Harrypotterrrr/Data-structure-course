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
using namespace std;
void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
void BubbleSort(int *start, int n)
{
	bool flag = true;
	for (int i = 1; i < n && flag; i++) {
		flag = false;
		for (int j = 0; j < n - i; j++)
			if (start[j] > start[j + 1]) {
				flag = true;
				swap(start + j, start + j + 1);
			}
	}
}
void QuickSort(int *start, int *end)
{
	if (start > end)
		return;
	int *p = start, *q = end;
	while (p != q) {
		while (q > p && *q >= *start)
			q--;
		while (p < q && *p <= *start)
			p++;
		if (p != q)
			swap(p, q);
	}
	swap(start, p);
	QuickSort(start, p - 1);
	QuickSort(p + 1, end);
}
void InsertSort(int *start, int n)
{
	for (int i = 1; i < n; i++) {
		if (start[i - 1] > start[i]) {
			int tmp = start[i];
			for (int j = i - 1; start[j] > tmp; j--)
				start[j+1] = start[j];
			start[0] = tmp;
		}
	}
}
int main()
{
	int *p, *start;
	int n;
	cin >> n;
	p = new int[n];
	start = p;
	for (; p < start + n; p++)
		cin >> *p;
	//QuickSort(start, start+n-1);
	InsertSort(start, n);
	//BubbleSort(start, n);
	for (p = start; p < start + n; p++)
		cout << *p << " ";
	putchar('\n');
	return 0;
}