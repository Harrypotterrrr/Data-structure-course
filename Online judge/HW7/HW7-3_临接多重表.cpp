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
	int ivex, jvex;
	ArcNode *ilink, *jlink;
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
		vexmatrix = new VexNode<T>[MAX_VERTEX_NUM];
		visit = new bool[MAX_VERTEX_NUM];
		vexnum = arcnum = 0;
		cin >> vexnum >> arcnum;
		gtype = UndirectedGraph;
	}
	~UDGraph() {
		delete[]vexmatrix;
	}
	Status CreateVexDGraph();
	Status CreateArcDGraph();
	int LocateVex(int);

	void DFSTraverse()
	{

		visit = new bool[vexnum];
		memset(visit, false, vexnum);
		for (int i = 0; i < vexnum; i++) {
			if (!visit[vexmatrix[i].data]) {
				cout<<"{";
				DFS(i);
				cout<<"}";
			}
		}
	}
	void DFS(int i)
	{
		ArcNode<T> *p = vexmatrix[i].firstedge;
		visit[i] = true;
		cout<<vexmatrix[i].data;
		while (p) {
			if (!visit[p->jvex])
				DFS(p->jvex);
			p = p->jlink;
		}
		p = vexmatrix[i].firstedge;
		while (p) {
			if (!visit[p->ivex])
				DFS(p->ivex);
			p = p->ilink;
		}
	}

	void BFSTraverse()
	{
		ArcNode<T> *p;
		visit = new bool[MAX_VERTEX_NUM];
		memset(visit, false, MAX_VERTEX_NUM);
		queue<int>Q;
		for (int i = 0; i < vexnum; i++) {
			if (!visit[vexmatrix[i].data]) {
				cout<<"{";
				cout<<vexmatrix[i].data;
				Q.push(i);
				while (!Q.empty()) {
					int tmp = Q.front();
					Q.pop();
					p = vexmatrix[tmp].firstedge;
					while (p) {
						if (!visit[p->jvex]) {
							visit[p->jvex] = true;
							cout<<p->jvex;
							Q.push(p->jvex);
						}
					}
					p = p->jlink;
				}
				cout<<"}";
			}
		}
	}
};

template<typename T>
Status UDGraph<T>::CreateVexDGraph()
{
	for (int i = 0; i < vexnum; i++) {
		vexmatrix[i].data = i;
		vexmatrix[i].firstedge = NULL;
	}
	return OK;
}
template<typename T>
Status UDGraph<T>::CreateArcDGraph()
{
	int n, i, j;
	for (int k = 0; k < arcnum; k++) {
		ArcNode<T>* arc = new ArcNode<T>;
		cin >> arc->ivex >> arc->jvex;
		i = LocateVex(arc->ivex);
		j = LocateVex(arc->jvex);
		if (gtype == UndirectedNet) {
			int data;
			cin >> data;
			arc->info = data;
		}
		arc->ilink = vexmatrix[i].firstedge;
		vexmatrix[i].firstedge = arc;
		arc->jlink = vexmatrix[j].firstedge;
		vexmatrix[j].firstedge = arc;
	}
	return OK;
}
template<typename T>
int UDGraph<T>::LocateVex(int n)
{
	for (int i = 0; i < vexnum; i++) {
		if (vexmatrix[i].data == n)
			return i;
	}
	return ERROR;
}


int main()
{
	UDGraph<int> test;
	test.CreateVexDGraph();
	test.CreateArcDGraph();
	test.DFSTraverse();
	test.BFSTraverse();
}