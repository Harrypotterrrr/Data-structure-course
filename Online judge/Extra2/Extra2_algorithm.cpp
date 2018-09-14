#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int num[100005];
	bool flag[100005], F = true;
	int n, s, m, p;
	cin >> n >> s >> m;
	p = (s - 1) % n;
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp = p % n + 1;
			while (flag[tmp])
				tmp = tmp % n + 1;
			p = tmp;
		}
		flag[p] = true;
		if (F) {
			cout << p;
			F = false;
		}
		else
			cout << "  " << p;
	}
	putchar('\n');
	return 0;
}