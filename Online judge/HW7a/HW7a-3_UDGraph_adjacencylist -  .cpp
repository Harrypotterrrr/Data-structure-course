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
struct cmp1
{
	bool operator ()(pair<int, int> x, pair<int, int> y) {
		return x.first > y.first;//小的优先级高  
	}
};

template<typename T>
class UDGraph
{
public:
	VexNode<T> *vexlist;
	int vexnum, arcnum;
	int N;
	bool *visit;
	GraphType gtype;

	UDGraph() {
		cin >> vexnum >> arcnum;
		vexlist = new VexNode<T>[vexnum + 1];
		visit = new bool[vexnum];
	}
	~UDGraph() {
		delete[]vexlist;
	}

	/*Initial*/
	Status CreateVex()
	{
		for (int i = 0; i <= vexnum; i++) {
			vexlist[i].data = i;
			vexlist[i].firstedge = NULL;
		}
		return OK;
	}
	Status CreateArcDirected()
	{
		int start, loc;
		for (int k = 1; k <= arcnum; k++) {
			ArcNode<T>* arc = new ArcNode<T>;
			cin >> start >> arc->adjvex;
			loc = LocateVex(start);
			if (gtype == DirectedNet) {
				int data;
				cin >> data;
				arc->info = data;
			}
			arc->next = vexlist[loc].firstedge;
			vexlist[loc].firstedge = arc;
		}
		return OK;
	}
	Status CreateArcUndirected()
	{
		int loc1, loc2;
		for (int k = 1; k <= arcnum; k++) {
			ArcNode<T>* arc1 = new ArcNode<T>;
			ArcNode<T>* arc2 = new ArcNode<T>;
			cin >> arc1->adjvex >> arc2->adjvex;
			loc1 = LocateVex(arc1->adjvex);
			loc2 = LocateVex(arc2->adjvex);
			if (gtype == UndirectedNet) {
				/*int data;
				cin >> data;
				arc1->info = data;
				arc2->info = data;*/
				arc1->info = 1;
				arc2->info = 1;
			}
			arc2->next = vexlist[loc1].firstedge;
			vexlist[loc1].firstedge = arc2;
			arc1->next = vexlist[loc2].firstedge;
			vexlist[loc2].firstedge = arc1;
		}
		return OK;
	}

	int LocateVex(int n)
	{
		for (int i = 0; i <= vexnum; i++) {
			if (vexlist[i].data == n)
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
			if (!visit[vexlist[i].data]) {
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
		ArcNode<T> *p = vexlist[i].firstedge;
		visit[i] = true;
		if (!DFS_Flag) {
			cout << vexlist[i].data;
			DFS_Flag = true;
		}
		else
			cout << " " << vexlist[i].data;
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
			if (!visit[vexlist[i].data]) {
				cout << "{";
				cout << vexlist[i].data;
				visit[vexlist[i].data] = true;
				Q.push(i);
				while (!Q.empty()) {
					int tmp = Q.front();
					Q.pop();
					p = vexlist[tmp].firstedge;
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
		int *adjnode = new int[vexnum + 1];
		int *lowercost = new int[vexnum + 1];
		int count = 0;
		memset(adjnode, 0, sizeof(int)*(vexnum + 1));
		memset(lowercost, 0x3f, sizeof(int)*(vexnum + 1));
		ArcNode<T>* p = vexlist[1].firstedge;
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
			p = vexlist[tag].firstedge;
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

	/*Dijkstra_prioprityQueue*/
	void Dijkstra_PrioprityQueue(int N)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1 >Q;

		int *minpath = new int[vexnum + 1];
		bool *flag = new bool[vexnum + 1];
		memset(flag, false, vexnum + 1);

		memset(minpath, 0x3f, sizeof(int)*(vexnum + 1));
		minpath[N] = 0;
		pair<int, int>tmp(0, N);
		Q.push(tmp);
		while (!Q.empty()) {
			pair<int, int> nwNode = Q.top();
			Q.pop();
			int nwNum = nwNode.second;
			if (flag[nwNum])
				continue;
			flag[nwNum] = true;
			for (ArcNode<T> *p = vexlist[nwNum].firstedge; p; p = p->next) {
				if (flag[nwNum] && minpath[nwNum] + p->info < minpath[p->adjvex]) {
					minpath[p->adjvex] = minpath[nwNum] + p->info;
					pair<int, int>tmp(minpath[p->adjvex], p->adjvex);
					Q.push(tmp);
				}
			}
		}
		double rate = 0.0;
		int sum = 0;
		for (int i = 1; i <= vexnum; i++) {
			if (minpath[i] <= 6)
				sum++;
		}
		cout <<N<<": "<<setiosflags(ios::fixed)<<setprecision(2)<< sum * 100.0 / vexnum << "%\n";
		delete[]minpath;
		delete[]flag;
	}

};
int main()
{
	UDGraph<int> test;
	test.gtype = UndirectedNet;
	test.CreateVex();
	if (test.gtype == DirectedGraph || test.gtype == DirectedNet)
		test.CreateArcDirected();
	else
		test.CreateArcUndirected();
	for (int i = 1; i <= test.vexnum; i++)
		test.Dijkstra_PrioprityQueue(i);
	return 0;
}