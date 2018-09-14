#include <iostream>
#include <iomanip>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
#define MAX_VERTEX_NUM 30
using namespace std;
//template<typename T>
enum GraphType{null,DirectedGraph,DirectedNet,UndirectedGraph,UndirectedNet};
typedef char ArcElem;
typedef char VexElem;
//struct ArcNode {
//	ArcElem info;
//	int tailvex, headvex;
//	ArcNode *taillink, *headlink;
//};
//struct VexNode {
//	VexElem data;
//	ArcNode *firstin, *firstout;
//};
//struct Graph{
//	VexNode vexmatrix[MAX_VERTEX_NUM];
//	int vexnum, arcnum;
//	int gtype;
//};
struct ArcNode {
	int info;
	ArcElem data;
	ArcNode *next;
};
struct VexNode {
	VexElem data;
	ArcNode *next;
};
struct Graph {
	int vexmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	VexNode vexlist[MAX_VERTEX_NUM];
	int vexnum, arcnum;
	int gtype;
};
map<char, int>M;
void AddNetArc(Graph &gp, char c1, char c2, int len)
{
	ArcNode *arc = new(ArcNode);
	arc->data = c2;
	arc->info = len;
	arc->next = gp.vexlist[M[c1]].next;
	gp.vexlist[M[c1]].next = arc;
}
void AddGraphArc(Graph &gp, char c1,char c2)
{
	ArcNode *arc = new(ArcNode);
	arc->data = c2;
	arc->next = gp.vexlist[M[c1]].next;
	gp.vexlist[M[c1]].next = arc;
}
void PrintMatrix(Graph &gp)
{
	for (int i = 1; i <= gp.vexnum; i++) {
		for (int j = 1; j <= gp.vexnum; j++)
			cout << setw(4) << gp.vexmatrix[i][j];
		putchar('\n');
	}
}
void CreateDirectedGraphMatrix(Graph &gp)
{
	char c1, c2;
	memset(gp.vexmatrix, 0, sizeof gp.vexmatrix);
	for (int i = 1; i <= gp.arcnum; i++) {
		cin >> c1 >> c2;
		gp.vexmatrix[M[c1]][M[c2]] = 1;
		AddGraphArc(gp, c1, c2);
	}
}
void CreateUndirectedGraphMatrix(Graph &gp)
{
	char c1, c2;
	memset(gp.vexmatrix, 0, sizeof gp.vexmatrix);
	for (int i = 1; i <= gp.arcnum; i++) {
		cin >> c1 >> c2;
		gp.vexmatrix[M[c1]][M[c2]] = 1;
		gp.vexmatrix[M[c2]][M[c1]] = 1;
		AddGraphArc(gp, c1, c2);
		AddGraphArc(gp, c2, c1);
	}
}
void CreateDirectedNetMatrix(Graph &gp)
{
	char c1, c2;
	int len;
	memset(gp.vexmatrix, 0, sizeof gp.vexmatrix);
	for (int i = 1; i <= gp.arcnum; i++) {
		cin >> c1 >> c2 >> len;
		gp.vexmatrix[M[c1]][M[c2]] = len;
		AddNetArc(gp, c1, c2, len);
	}
}
void CreateUndirectedNetMatrix(Graph &gp)
{
	char c1, c2;
	int len;
	memset(gp.vexmatrix, 0, sizeof gp.vexmatrix);
	for (int i = 1; i <= gp.arcnum; i++) {
		cin >> c1 >> c2 >> len;
		gp.vexmatrix[M[c1]][M[c2]] = len;
		gp.vexmatrix[M[c2]][M[c1]] = len;
		AddNetArc(gp, c1, c2, len);
		AddNetArc(gp, c2, c1, len);
	}
}
void TraverseGraphList(Graph &gp)
{
	ArcNode *p;
	for (int i = 1; i <= gp.vexnum; i++) {
		cout << gp.vexlist[i].data << "-->";
		p = gp.vexlist[i].next;
		while (p) {
			cout << M[p->data]-1 << " ";
			p = p->next;
		}
		putchar('\n');
	}
}
void TraverseNetList(Graph &gp)
{
	ArcNode *p;
	for (int i = 1; i <= gp.vexnum; i++) {
		cout << gp.vexlist[i].data << "-->";
		p = gp.vexlist[i].next;
		while (p) {
			cout << M[p->data] - 1 << ',' << p->info << " ";
			p = p->next;
		}
		putchar('\n');
	}
}
void PrintVertex(Graph &gp)
{
	cout << gp.vexlist[1].data;
	for (int i = 2; i <= gp.vexnum; i++)
		cout << " " << gp.vexlist[i].data;
	putchar('\n');
}
int main()
{
	Graph gp;
	cin >> gp.gtype >> gp.vexnum >> gp.arcnum;
	for (int i = 1; i <= gp.vexnum; i++) {
		cin >> gp.vexlist[i].data;
		gp.vexlist[i].next = NULL;
		M[gp.vexlist[i].data] = i;
	}
	if (gp.gtype == DirectedGraph) {
		CreateDirectedGraphMatrix(gp);
		PrintVertex(gp);
		PrintMatrix(gp);
		TraverseGraphList(gp);
	}
	else if (gp.gtype == UndirectedGraph) {
		CreateUndirectedGraphMatrix(gp);
		PrintVertex(gp);
		PrintMatrix(gp);
		TraverseGraphList(gp);
	}
	else if (gp.gtype == DirectedNet) {
		CreateDirectedNetMatrix(gp);
		PrintVertex(gp);
		PrintMatrix(gp);
		TraverseNetList(gp);
	}
	else if (gp.gtype == UndirectedNet) {
		CreateUndirectedNetMatrix(gp);
		PrintVertex(gp);
		PrintMatrix(gp);
		TraverseNetList(gp);
	}
	return 0;
}