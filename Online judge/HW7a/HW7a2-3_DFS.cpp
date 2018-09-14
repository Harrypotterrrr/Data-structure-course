#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#define INF 0x3f3f3f3f
#define MAX_VERTEX_NUM 30
#define ERROR -1
#define OK 1
using namespace std;
void dfs(bool Map[][6], int times, string str)
{
	if (times == 8) {
		cout << str << endl;
		return;
	}
	for (int i = 1; i <= 5; i++) {
		int tmp = str[str.length() - 1] - '0';
		if (Map[tmp][i]) {
			Map[tmp][i] = Map[i][tmp] = false;
			dfs(Map, times + 1, str + char('0' + i));
			Map[tmp][i] = Map[i][tmp] = true;
		}
	}
}

int main()
{
	bool Map[6][6];
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			if (i == j)
				Map[i][j] = false;
			else
				Map[i][j] = Map[j][i] = true;
	Map[1][4] = Map[4][1] = false;
	Map[2][4] = Map[4][2] = false;
	for (int i = 1; i <= 1; i++)
		dfs(Map, 1, string("") + char(i + '0'));
	return 0;
}