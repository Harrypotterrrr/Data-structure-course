#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int *num;
	int n, find, left, right, mid;
	bool flag = false;
	cin >> n;
	num = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", num + i);
	cin >> find;
	if (find > num[n-1] || find<num[0]) {
		cout << "-1\n";
		return 0;
	}
	left = 0;
	right = n - 1;
	mid = (left + right) / 2;
	while (left != right) {
		mid = (left + right) / 2;
		if (num[mid] > find)
			right = mid-1;
		else if (num[mid] < find)
			left = mid+1;
		else
			break;
	}
	if (num[mid] == find) {
		while (find == num[mid])
			mid--;
		cout << mid + 1 << endl;
	}
	else
		cout << "-1\n";
	return 0;
}