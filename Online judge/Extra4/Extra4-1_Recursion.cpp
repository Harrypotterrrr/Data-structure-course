#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
using namespace std;
string input;
void solve(stack<char> sk, int n, string ans)
{
	if (sk.empty() && !n)
		cout << ans<<endl;
	else {
		if (!sk.empty()) {
			char temp = sk.top();
			sk.pop();
			solve(sk, n, ans + temp);
			sk.push(temp);
		}
		if (n) {
			sk.push(input[input.size()-n]);
			solve(sk, n - 1, ans);
			sk.pop();
		}
	}
}
int main()
{
	stack<char>	sk;
	string ans;
	cin >> input;
	solve(sk, input.size(), "");
	return 0;
}