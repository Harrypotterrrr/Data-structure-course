#include <iostream>
using namespace std;
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //邻接矩阵类型

#define OK 1
#define ERROR -1
#define MAXSIZE 100
template<typename T>
class SqQueue //队列
{
private:
	T* base; //基地址
	int front, rear;
public:
	SqQueue() //构造函数
	{
		base = new T[MAXSIZE];
		front = rear = 0;
	}

	~SqQueue() //析构函数
	{
		delete[]base;
		front = rear = 0;
	}

	int Length() //求长度
	{
		return (rear - front + MAXSIZE) % MAXSIZE;
	}

	bool isEmpty() //判断是否为空
	{
		return (front == rear);
	}

	int EnQueue(T e) //入队
	{
		if ((rear + 1) % MAXSIZE == front)
			return ERROR;
		base[rear] = e;
		rear = (rear + 1) % MAXSIZE;
		return OK;
	}

	int DeQueue(T &e) //出队
	{
		if (isEmpty())
			return ERROR;
		e = base[front];
		front = (front + 1) % MAXSIZE;
		return OK;
	}

	int GetHead(T &e) //获取队首
	{
		if (isEmpty())
			return ERROR;
		e = base[front];
		return OK;
	}
};

class MGragh{
private:
    VertexType vexs[MAX_VERTEX_NUM]; //顶点表
    AdjMatrix arcs; //邻接矩阵
    int vexnum,arcnum; //图的顶点数和弧数
public:
	int LocateVex(VertexType u){
		int i;
		for(i=0;i<vexnum;i++){
			if(u==vexs[i])
				return i;
		}
		if(i==vexnum){
			cout<<"未找到顶点值"<<endl;exit(1);
		}
		return 0;
	}
	void CreateMGraph(){
		int i,j,k,w; VertexType v1,v2;
		cout<<"请输入顶点数和弧数："<<endl;
		cin>>vexnum>>arcnum;
		cout<<"请输入顶点："<<endl;
		for(i=0;i<vexnum;i++)
			cin>>vexs[i];
		for(i=0;i<vexnum;i++)
			for(j=0;j<vexnum;j++)
				arcs[i][j]=INFINITY;
		for(k=0;k<arcnum;k++){
			cout<<"请依次输入弧的两个顶点、权值：";
			cin>>v1>>v2>>w;
			i=LocateVex(v1);
			j=LocateVex(v2);
			arcs[i][j]=arcs[j][i]=w;
		}
		return;
	}
	void PrintMGraph(){
		int i,j;
		cout<<"各顶点值："<<endl;
		for(i=0;i<vexnum;i++)
			cout<<vexs[i]<<' ';
		cout<<endl;
		cout<<"邻接矩阵："<<endl;
		for(i=0;i<vexnum;i++){
			for(j=0;j<vexnum;j++){
				if(arcs[i][j]==INFINITY)cout<<'N'<<' ';
				else cout<<arcs[i][j]<<' ';
			}
			cout<<endl;
		}
		return;
	}
	bool visited[MAX_VERTEX_NUM];
	void DFS(int i){    //从第i个顶点出发DFS
		int j;
		cout<<vexs[i]<<' ';
		visited[i]=1;
		for(j=0;j<vexnum;j++){
			if(arcs[i][j]!=INFINITY&&!visited[j])
				DFS(j);
		}
	}
	void DFSTraverse(){
		int i;
	    for(i=0;i<vexnum;++i)
            visited[i]=0;
        for(i=0;i<vexnum;++i){
            if (!visited[i])
                DFS(i);
	    }
		cout<<endl;
	}
	void BFSTraverse(){
		int i;
		for(i=0;i<vexnum;++i)
			visited[i]=0;
		for(i=0;i<vexnum;i++)
			if(!visited[i])BFS(i);
		cout<<endl;
	}
	void BFS(int i){
		SqQueue<int> Q;
        visited[i]=1;
        cout<<vexs[i]<<' ';
    	Q.EnQueue(i);
		while(!Q.isEmpty()){
			Q.DeQueue(i);
		    for(int j=0;j<vexnum;++j)
				if(!visited[j]&&arcs[i][j]!=INFINITY){
                    visited[j]=1;
                    cout<<vexs[j]<<' ';
					Q.EnQueue(j);
                }
		}     
	}
	void mainpp(){
		cout<<"1.建立邻接矩阵"<<endl;
		cout<<"2.输出邻接矩阵"<<endl;
		cout<<"3.图的广度优先搜索"<<endl;
		cout<<"4.图的深度优先搜索"<<endl;
		cout<<"0.结束"<<endl;
	}
};

struct ArcNode{
    int adjvex;    //该弧所指向的顶点的位置
    struct ArcNode *nextarc;    //指向下一条弧的指针
    int info;
}; //边结点类型
typedef struct VNode{
    VertexType data; //顶点信息
    ArcNode *firstarc; //指向第一条依附该顶点的指针
}AdjList[MAX_VERTEX_NUM];
class ALGraph{
private:
    AdjList vertices; //邻接表
    int vexnum,arcnum;
public:
	int LocateVex(VertexType u){
		int i;
		for(i=0;i<vexnum;i++){
			if(u==vertices[i].data)
				return i;
		}
		if(i==vexnum){
			cout<<"未找到顶点值"<<endl;exit(1);
		}
		return 0;
	}
	void CreateALGraph_adjlist(){
		int i,j,k,w;
		VertexType v1,v2;
		ArcNode *p;
		cout<<"请输入顶点数和弧数："<<endl;
		cin>>vexnum>>arcnum;
		cout<<"请输入顶点："<<endl;
		for(i=0;i<vexnum;i++){
			cin>>vertices[i].data;
			vertices[i].firstarc=NULL;
		}
		for(k=0;k<arcnum;k++){
			cout<<"请依次输入弧的两个顶点、权值：";
			cin>>v1>>v2>>w;
			i=LocateVex(v1);
			j=LocateVex(v2);
			p=new ArcNode;
			p->adjvex=j;
			p->info=w;
			p->nextarc=vertices[i].firstarc;
			vertices[i].firstarc=p;
		}
		return;
	}
	void PrintALGraph(){
		int i;
		cout<<"各顶点值："<<endl;
		for(i=0;i<vexnum;i++)
			cout<<vertices[i].data<<' ';
		cout<<endl;
		cout<<"邻接表："<<endl;
		ArcNode *p;
		for(i=0;i<vexnum;i++){
			cout<<"顶点："<<vertices[i].data<<' ';
			p=vertices[i].firstarc;
			while(p){
				cout<<p->adjvex<<' ';
				p=p->nextarc;
			}
			cout<<endl;
		}
	}
	bool visited[MAX_VERTEX_NUM];
	void DFS(int v){
		ArcNode *p;
		cout<<vertices[v].data<<' ';
		visited[v]=1;
		p=vertices[v].firstarc;
		while(p){
			if(!visited[p->adjvex])DFS(p->adjvex);
			p=p->nextarc;
		}
	}//从第v个顶点出发DFS
	void DFSTraverse(){
		int i;
		for(i=0;i<vexnum;++i)
			visited[i]=0;
		for(i=0;i<vexnum;++i)
			if(!visited[i])
				DFS(i);
		cout<<endl;
	}
	void BFSTraverse(){
		int v;
		for(v=0;v<vexnum;++v)
			visited[v]=0;
		for(v=0;v<vexnum;++v)
			if(!visited[v])BFS(v);
		cout<<endl;
	}
	void BFS(int v){
		ArcNode *p;
		SqQueue<int> Q;
		cout<<vertices[v].data<<' ';
		visited[v]=1;
		Q.DeQueue(v);
		while(!Q.isEmpty()){
			Q.DeQueue(v);
			p=vertices[v].firstarc;
			while(p){
				if(!visited[p->adjvex]){
					cout<<vertices[p->adjvex].data<<' ';
					visited[p->adjvex]=1;
					Q.EnQueue(p->adjvex);
				}
				p=p->nextarc;
			}
		}
	}
	void mainpp(){
		cout<<"1.建立邻接表"<<endl;
		cout<<"2.输出邻接表"<<endl;
		cout<<"3.图的广度优先搜索"<<endl;
		cout<<"4.图的深度优先搜索"<<endl;
		cout<<"0.结束"<<endl;
	}
};

int main(){
	cout<<"1.图的邻接矩阵"<<endl;
	cout<<"2.图的邻接表"<<endl;
	int input;
	cin>>input;
	if(input==1){
		MGragh G;
		G.mainpp();
		while(1){
		    cout<<"请输入0-4"<<endl;
	    	cin>>input;
	    	if(input==0)break;
			switch(input){
			case 1:
				G.CreateMGraph();
				break;
			case 2:
				G.PrintMGraph();
				break;
			case 3:
				cout<<"广度优先遍历结果为："<<endl;
				G.DFSTraverse();
				break;
			case 4:
				cout<<"深度优先遍历结果为："<<endl;
				G.BFSTraverse();
				break;
			default:
				break;
			}
		}
	}
	else if(input==2){
		ALGraph G;
		G.mainpp();
		while(1){
		    cout<<"请输入0-4"<<endl;
	    	cin>>input;
	    	if(input==0)break;
			switch(input){
			case 1:
				G.CreateALGraph_adjlist();
				break;
			case 2:
				G.PrintALGraph();
				break;
			case 3:
				cout<<"广度优先遍历结果为："<<endl;
				G.DFSTraverse();
				break;
			case 4:
				cout<<"深度优先遍历结果为："<<endl;
				G.BFSTraverse();
				break;
			default:
				break;
			}
		}
	}
	return 0;
}