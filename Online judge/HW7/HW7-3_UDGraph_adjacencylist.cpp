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
struct ArcNode {
	T info;
	int adjvex;
	ArcNode *next;
};
template<typename T>
struct VexNode {
	T data;
	ArcNode<T> *firstedge;
};
template<typename T>
class UDGraph
{
public:
	VexNode<T> *vexmatrix;
	int vexnum, arcnum;
	bool *visit;
	GraphType gtype;

	UDGraph() {
		cin >> vexnum >> arcnum;
		vexmatrix = new VexNode<T>[vexnum];
		visit = new bool[vexnum];
		gtype = UndirectedGraph;
	}
	~UDGraph() {
		delete[]vexmatrix;
	}

	bool DFS_Flag;
	void DFSTraverse()
	{
		memset(visit, false, vexnum);
		for (int i = 0; i < vexnum; i++) {
			if (!visit[vexmatrix[i].data]) {
				DFS_Flag = false;
				cout << "{";
				DFS(i);
				cout << "}";
			}
		}
		putchar('\n');
	}
	void DFS(int i)
	{
		ArcNode<T> *p = vexmatrix[i].firstedge;
		visit[i] = true;
		if (!DFS_Flag) {
			cout << vexmatrix[i].data;
			DFS_Flag = true;
		}
		else
			cout <<" "<< vexmatrix[i].data;
		while (p) {
			if (!visit[p->adjvex])
				DFS(p->adjvex);
			p = p->next;
		}
	}

	void BFSTraverse()
	{
		ArcNode<T> *p;
		memset(visit, false, vexnum);
		queue<int>Q;
		for (int i = 0; i < vexnum; i++) {
			if (!visit[vexmatrix[i].data]) {
				cout << "{";
				cout << vexmatrix[i].data;
				visit[vexmatrix[i].data] = true;
				Q.push(i);
				while (!Q.empty()) {
					int tmp = Q.front();
					Q.pop();
					p = vexmatrix[tmp].firstedge;
					while (p) {
						if (!visit[p->adjvex]) {
							visit[p->adjvex] = true;
							cout << " " << p->adjvex;
							Q.push(p->adjvex);
						}
						p = p->next;
					}
				}
				cout << "}";
			}
		}
		putchar('\n');
	}

	Status CreateVexDGraph()
	{
		for (int i = 0; i < vexnum; i++) {
			vexmatrix[i].data = i;
			vexmatrix[i].firstedge = NULL;
		}
		return OK;
	}
	Status CreateArcDGraph()
	{
		int loc1, loc2;
		for (int k = 0; k < arcnum; k++) {
			ArcNode<T>* arc1 = new ArcNode<T>;
			ArcNode<T>* arc2 = new ArcNode<T>;
			cin >> arc1->adjvex >> arc2->adjvex;
			loc1 = LocateVex(arc1->adjvex);
			loc2 = LocateVex(arc2->adjvex);
			if (gtype == UndirectedNet) {
				int data;
				cin >> data;
				arc1->info = data;
				cin >> data;
				arc2->info = data;
			}
			arc2->next = vexmatrix[loc1].firstedge;
			vexmatrix[loc1].firstedge = arc2;
			arc1->next = vexmatrix[loc2].firstedge;
			vexmatrix[loc2].firstedge = arc1;
		}
		return OK;
	}
	int LocateVex(int n)
	{
		for (int i = 0; i < vexnum; i++) {
			if (vexmatrix[i].data == n)
				return i;
		}
		return ERROR;
	}
};




int main()
{
	UDGraph<int> test;
	test.CreateVexDGraph();
	test.CreateArcDGraph();
	test.DFSTraverse();
	test.BFSTraverse();
}