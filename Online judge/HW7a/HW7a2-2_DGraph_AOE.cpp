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
	int in;
	ArcNode<T> *firstedge;
};

struct cmp1
{
	bool operator ()(pair<int, int> x, pair<int, int> y) {
		return x.first > y.first;//小的优先级高  
	}
};

template<typename T>
class DGraph
{
public:
	VexNode<T> *vexlist;
	queue<T> Topo;
	int vexnum, arcnum;
	int startnode;
	bool *visit;
	GraphType gtype;

	DGraph() {
		cin >> vexnum >> arcnum;
		vexlist = new VexNode<T>[vexnum + 1];
		visit = new bool[vexnum + 1];
	}
	~DGraph() {
		delete[]vexlist;
	}

	/*Initial*/
	Status CreateVex()
	{
		for (int i = 0; i <= vexnum; i++) {
			vexlist[i].data = i;
			vexlist[i].firstedge = NULL;
			vexlist[i].in = 0;
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
				vexlist[arc->adjvex].in++;
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
				int data;
				cin >> data;
				arc1->info = data;
				arc2->info = data;
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
	void Dijkstra_PrioprityQueue()
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1 >Q;

		int *minpath = new int[vexnum + 1];
		bool *flag = new bool[vexnum + 1];
		memset(flag, false, vexnum + 1);

		memset(minpath, 0x3f, sizeof(int)*(vexnum + 1));
		minpath[startnode] = 0;
		pair<int, int>tmp(0, startnode);
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
		for (int i = 1; i <= vexnum; i++) {
			if (*(minpath + i) == INF)
				cout << "2147483647 ";
			else
				cout << *(minpath + i) << " ";
		}
		putchar('\n');
	}

	/*topological sort*/
	bool TopologicalSort()
	{
		stack<int>S;
		int count = 0;
		for (int i = 1; i <= vexnum; i++) {
			if (vexlist[i].in == 0)
				S.push(i);
		}
		while (!S.empty()) {
			int nwNum = S.top();
			S.pop();
			count++;
			Topo.push(nwNum);
			for (ArcNode<T> *p = vexlist[nwNum].firstedge; p; p = p->next) {
				vexlist[p->adjvex].in--;
				if (!vexlist[p->adjvex].in)
					S.push(p->adjvex);
			}
		}
		if (count == vexnum)
			return true;
		else
			return false;
	}

	/*AOE*/
	void AOE()
	{
		if (!TopologicalSort()) {
			cout << "0\n";
			return;
		}
		stack<T>S;
		int *Ve = new int[vexnum + 1];
		int *Vl = new int[vexnum + 1];
		int nwNum = Topo.front();
		memset(Ve, 0, sizeof(int)*(vexnum + 1));

		while (!Topo.empty()) {
			nwNum = Topo.front();
			S.push(nwNum);
			Topo.pop();
			for (ArcNode<T>*p = vexlist[nwNum].firstedge; p; p = p->next) {
				if (Ve[p->adjvex] < Ve[nwNum] + p->info) {
					Ve[p->adjvex] = Ve[nwNum] + p->info;
				}
			}
		}
		for (int i = 1; i <= vexnum; i++)
			Vl[i] = Ve[vexnum];
		while (!S.empty()) {
			nwNum = S.top();
			S.pop();
			for (ArcNode<T>*p = vexlist[nwNum].firstedge; p; p = p->next) {
				if (Vl[nwNum] > Vl[p->adjvex] - p->info) {
					Vl[nwNum] = Vl[p->adjvex] - p->info;
				}
			}
		}
		cout << Ve[vexnum] << endl;
		/*关键路径可能不只有一条..*/
		for (int i = 1; i <= vexnum; i++) {
			for (ArcNode<T>*p = vexlist[i].firstedge; p; p = p->next) {
				if (Ve[i] == Vl[p->adjvex] - p->info) {
					cout << i << "->" << p->adjvex << endl;
					//break;
				}
			}
		}
	}
};
int main()
{
	DGraph<int> test;
	test.gtype = DirectedNet;
	test.CreateVex();
	if (test.gtype == DirectedGraph || test.gtype == DirectedNet)
		test.CreateArcDirected();
	else
		test.CreateArcUndirected();
	test.AOE();

	return 0;
}