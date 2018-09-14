#include <iostream>
using namespace std;
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef char VertexType;
typedef int AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //�ڽӾ�������

#define OK 1
#define ERROR -1
#define MAXSIZE 100
template<typename T>
class SqQueue //����
{
private:
	T* base; //����ַ
	int front, rear;
public:
	SqQueue() //���캯��
	{
		base = new T[MAXSIZE];
		front = rear = 0;
	}

	~SqQueue() //��������
	{
		delete[]base;
		front = rear = 0;
	}

	int Length() //�󳤶�
	{
		return (rear - front + MAXSIZE) % MAXSIZE;
	}

	bool isEmpty() //�ж��Ƿ�Ϊ��
	{
		return (front == rear);
	}

	int EnQueue(T e) //���
	{
		if ((rear + 1) % MAXSIZE == front)
			return ERROR;
		base[rear] = e;
		rear = (rear + 1) % MAXSIZE;
		return OK;
	}

	int DeQueue(T &e) //����
	{
		if (isEmpty())
			return ERROR;
		e = base[front];
		front = (front + 1) % MAXSIZE;
		return OK;
	}

	int GetHead(T &e) //��ȡ����
	{
		if (isEmpty())
			return ERROR;
		e = base[front];
		return OK;
	}
};

class MGragh{
private:
    VertexType vexs[MAX_VERTEX_NUM]; //�����
    AdjMatrix arcs; //�ڽӾ���
    int vexnum,arcnum; //ͼ�Ķ������ͻ���
public:
	int LocateVex(VertexType u){
		int i;
		for(i=0;i<vexnum;i++){
			if(u==vexs[i])
				return i;
		}
		if(i==vexnum){
			cout<<"δ�ҵ�����ֵ"<<endl;exit(1);
		}
		return 0;
	}
	void CreateMGraph(){
		int i,j,k,w; VertexType v1,v2;
		cout<<"�����붥�����ͻ�����"<<endl;
		cin>>vexnum>>arcnum;
		cout<<"�����붥�㣺"<<endl;
		for(i=0;i<vexnum;i++)
			cin>>vexs[i];
		for(i=0;i<vexnum;i++)
			for(j=0;j<vexnum;j++)
				arcs[i][j]=INFINITY;
		for(k=0;k<arcnum;k++){
			cout<<"���������뻡���������㡢Ȩֵ��";
			cin>>v1>>v2>>w;
			i=LocateVex(v1);
			j=LocateVex(v2);
			arcs[i][j]=arcs[j][i]=w;
		}
		return;
	}
	void PrintMGraph(){
		int i,j;
		cout<<"������ֵ��"<<endl;
		for(i=0;i<vexnum;i++)
			cout<<vexs[i]<<' ';
		cout<<endl;
		cout<<"�ڽӾ���"<<endl;
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
	void DFS(int i){    //�ӵ�i���������DFS
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
		cout<<"1.�����ڽӾ���"<<endl;
		cout<<"2.����ڽӾ���"<<endl;
		cout<<"3.ͼ�Ĺ����������"<<endl;
		cout<<"4.ͼ�������������"<<endl;
		cout<<"0.����"<<endl;
	}
};

struct ArcNode{
    int adjvex;    //�û���ָ��Ķ����λ��
    struct ArcNode *nextarc;    //ָ����һ������ָ��
    int info;
}; //�߽������
typedef struct VNode{
    VertexType data; //������Ϣ
    ArcNode *firstarc; //ָ���һ�������ö����ָ��
}AdjList[MAX_VERTEX_NUM];
class ALGraph{
private:
    AdjList vertices; //�ڽӱ�
    int vexnum,arcnum;
public:
	int LocateVex(VertexType u){
		int i;
		for(i=0;i<vexnum;i++){
			if(u==vertices[i].data)
				return i;
		}
		if(i==vexnum){
			cout<<"δ�ҵ�����ֵ"<<endl;exit(1);
		}
		return 0;
	}
	void CreateALGraph_adjlist(){
		int i,j,k,w;
		VertexType v1,v2;
		ArcNode *p;
		cout<<"�����붥�����ͻ�����"<<endl;
		cin>>vexnum>>arcnum;
		cout<<"�����붥�㣺"<<endl;
		for(i=0;i<vexnum;i++){
			cin>>vertices[i].data;
			vertices[i].firstarc=NULL;
		}
		for(k=0;k<arcnum;k++){
			cout<<"���������뻡���������㡢Ȩֵ��";
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
		cout<<"������ֵ��"<<endl;
		for(i=0;i<vexnum;i++)
			cout<<vertices[i].data<<' ';
		cout<<endl;
		cout<<"�ڽӱ�"<<endl;
		ArcNode *p;
		for(i=0;i<vexnum;i++){
			cout<<"���㣺"<<vertices[i].data<<' ';
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
	}//�ӵ�v���������DFS
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
		cout<<"1.�����ڽӱ�"<<endl;
		cout<<"2.����ڽӱ�"<<endl;
		cout<<"3.ͼ�Ĺ����������"<<endl;
		cout<<"4.ͼ�������������"<<endl;
		cout<<"0.����"<<endl;
	}
};

int main(){
	cout<<"1.ͼ���ڽӾ���"<<endl;
	cout<<"2.ͼ���ڽӱ�"<<endl;
	int input;
	cin>>input;
	if(input==1){
		MGragh G;
		G.mainpp();
		while(1){
		    cout<<"������0-4"<<endl;
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
				cout<<"������ȱ������Ϊ��"<<endl;
				G.DFSTraverse();
				break;
			case 4:
				cout<<"������ȱ������Ϊ��"<<endl;
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
		    cout<<"������0-4"<<endl;
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
				cout<<"������ȱ������Ϊ��"<<endl;
				G.DFSTraverse();
				break;
			case 4:
				cout<<"������ȱ������Ϊ��"<<endl;
				G.BFSTraverse();
				break;
			default:
				break;
			}
		}
	}
	return 0;
}