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
class DGraph
{
public:
	T * *vexmatrix;
	int vexnum, arcnum;
	int startnode;
	bool *visit;
	GraphType gtype;

	DGraph() {
		cin >> vexnum >> arcnum;
		vexmatrix = new int*[vexnum + 1];
		for (int i = 1; i <= vexnum; i++)
			vexmatrix[i] = new int[vexnum + 1];
		visit = new bool[vexnum + 1];

		cin >> startnode;
	}
	~DGraph() {
		delete[]vexmatrix;
	}

	/*Initial*/
	Status CreateArcDirected()
	{
		int start, end;
		for (int i = 1; i <= vexnum; i++)
			memset(vexmatrix[i], 0x3f, sizeof(int)*(vexnum + 1));
		for (int k = 1; k <= arcnum; k++) {
			cin >> start >> end;
			if (gtype == DirectedNet) {
				int data;
				cin >> data;
				vexmatrix[start][end] = data;
			}
		}
		return OK;
	}
	/*Dijkstra_prioprityQueue*/

	void Dijkstra_matrix()
	{
		int *minpath = new int[vexnum + 1];
		int *minvex = new int[vexnum + 1];
		int Min, nwNode;
		memset(visit, false, vexnum + 1);
		memset(minpath, 0x3f, sizeof(int)*(vexnum + 1));

		visit[startnode] = true;
		for (int i = 1; i <= vexnum; i++)
			minpath[i] = vexmatrix[startnode][i];
		minpath[startnode] = 0;


		for (int i = 1; i <= vexnum; i++) {
			Min = INF;
			for (int i = 1; i <= vexnum; i++)
				if (!visit[i] && Min > minpath[i]) {
					Min = minpath[i];
					nwNode = i;
				}
			visit[nwNode] = true;
			for (int i = 1; i <= vexnum; i++)
				if (minpath[i] > vexmatrix[nwNode][i] + minpath[nwNode]) {
					minpath[i] = vexmatrix[nwNode][i] + minpath[nwNode];
				}
		}

		for (int i = 1; i <= vexnum; i++) {
			if (minpath[i] == INF)
				cout << "2147483647 ";
			else
				cout << minpath[i] << " ";
		}
		putchar('\n');
	}
};
int main()
{
	DGraph<int> test;
	test.gtype = DirectedNet;
	if (test.gtype == DirectedGraph || test.gtype == DirectedNet)
		test.CreateArcDirected();
	test.Dijkstra_matrix();
	return 0;
}