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
		vexmatrix = new VexNode<T>[vexnum+1];
		visit = new bool[vexnum];
		gtype = UndirectedNet;
	}
	~UDGraph() {
		delete[]vexmatrix;
	}

	/*Initial*/
	Status CreateVexDGraph()
	{
		for (int i = 0; i <= vexnum; i++) {
			vexmatrix[i].data = i;
			vexmatrix[i].firstedge = NULL;
		}
		return OK;
	}
	Status CreateArcDGraph()
	{
		int loc1, loc2;
		for (int k = 1; k <= arcnum; k++) {
			ArcNode<T>* arc1 = new ArcNode<T>;
			ArcNode<T>* arc2 = new ArcNode<T>;
			cin >> arc1->adjvex >> arc2->adjvex;
			loc1 = LocateVex(arc1->adjvex);
			loc2 = LocateVex(arc2->adjvex);
			if (gtype == UndirectedNet) {
				int data;
				cin >> data;
				arc1->info = data;
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
		for (int i = 0; i <= vexnum; i++) {
			if (vexmatrix[i].data == n)
				return i;
		}
		return ERROR;
	}

	/*DFS*/
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
	/*BFS*/
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


	/*Prim*/
	int Prim()
	{
		int *adjnode = new int[vexnum+1];
		int *lowercost = new int[vexnum+1];
		int count = 0;
		memset(adjnode, 0, sizeof(int)*(vexnum+1));
		memset(lowercost, 0x3f, sizeof(int)*(vexnum+1));
		ArcNode<T>* p = vexmatrix[1].firstedge;
		while (p) {
			lowercost[p->adjvex] = p->info;
			p = p->next;
		}
		int Min = INF, tag = 1;
		lowercost[1] = 0;
		for (int i = 1; i < vexnum; i++) {
			Min = INF;
			for (int j = 1; j <= vexnum; j++) {
				if (lowercost[j] && Min >= lowercost[j]) {
					Min = lowercost[j];
					tag = j;//ATTENTION!!tag为下标
				}
			}
			//cout << "权值最小边" << tag << endl;
			count += lowercost[tag];

			lowercost[tag] = 0;
			p = vexmatrix[tag].firstedge;
			while (p) {
				if (lowercost[p->adjvex] && p->info < lowercost[p->adjvex]) {
					lowercost[p->adjvex] = p->info;
					adjnode[p->adjvex] = tag;
				}
				p = p->next;
			}
		}
		for (int i = 1; i <= vexnum; i++)
			if (lowercost[i] == 0x3f3f3f3f)
				return -1;
		delete[]adjnode;
		delete[]lowercost;
		return count;
	}
};

int main()
{
	UDGraph<int> test;
	test.CreateVexDGraph();
	test.CreateArcDGraph();
	cout<<test.Prim()<<endl;
}