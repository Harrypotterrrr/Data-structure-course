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
enum GraphType { null, DirectedGraph, DirectedNet, UndirectedGraph, UndirectedNet };
typedef int Status;
template<typename T>
class UDGraph
{
public:
	bool vexmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
	bool *visit;
	GraphType gtype;

	UDGraph() {
		vexnum = arcnum = 0;
		cin >> vexnum >> arcnum;
		visit = new bool[vexnum];
		gtype = UndirectedGraph;
	}
	~UDGraph() {}
	Status CreateVexDGraph();
	Status CreateArcDGraph();
	int LocateVex(int);
	bool DFS_flag,BFS_flag;
	void DFSTraverse()
	{
		memset(visit, false, vexnum);
		for (int i = 0; i < vexnum; i++) {
			if (!visit[i]) {
				DFS_flag = false;
				cout << "{";
				DFS(i);
				cout << "}";
			}
		}
		putchar('\n');
	}
	void DFS(int i)
	{
		visit[i] = true;
		if (!DFS_flag) {
			cout << i;
			DFS_flag = true;
		}
		else
			cout << " "<< i ;
		for (int j = 0; j < vexnum; j++) {
			if (vexmatrix[i][j] && !visit[j])
				DFS(j);
		}
	}

	void BFSTraverse()
	{
		memset(visit, false, MAX_VERTEX_NUM);
		queue<int>Q;
		for (int i = 0; i < vexnum; i++) {
			if (!visit[i]) {
				cout << "{";
				cout << i;
				visit[i] = true;
				Q.push(i);
				while (!Q.empty()) {
					int tmp = Q.front();
					Q.pop();
					for (int j = 0; j < vexnum; j++) {
						if (vexmatrix[tmp][j] && !visit[j]) {
							visit[j] = true;
							cout <<" "<< j;
							Q.push(j);
						}
					}
				}
				cout << "}";
			}
		}
		putchar('\n');
	}
};

template<typename T>
Status UDGraph<T>::CreateVexDGraph()
{
	memset(vexmatrix, false, sizeof vexmatrix);
	return OK;
}
template<typename T>
Status UDGraph<T>::CreateArcDGraph()
{
	int i, j;
	for (int k = 0; k < arcnum; k++) {
		cin >> i >> j;
		vexmatrix[i][j] = true;
		vexmatrix[j][i] = true;
	}
	return OK;
}
template<typename T>
//int UDGraph<T>::LocateVex(int n)
//{
//	for (int i = 0; i < vexnum; i++) {
//		if (vexmatrix[i].data == n)
//			return i;
//	}
//	return ERROR;
//}


int main()
{
	UDGraph<int> test;
	test.CreateVexDGraph();
	test.CreateArcDGraph();
	//for (int i = 0; i < test.vexnum; i++) {
	//	for (int j = 0; j < test.vexnum; j++)
	//		cout << test.vexmatrix[i][j] << " ";
	//	cout<<endl;
	//}
	test.DFSTraverse();
	test.BFSTraverse();
}