#include <iostream>
using namespace std;
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
template<typename T>
struct ThrNode{
	T data;
	ThrNode *lchild,*rchild;
    int LTag,RTag;
public:
	ThrNode(){}
	ThrNode(T value,ThrNode *p,ThrNode *q,int i,int j){
		data=value;
		lchild=p;
		rchild=q;
		LTag=i;
		RTag=j;
	}
};
template<typename T>
class BiThrTree{
public:
	BiThrTree(){root=NULL;}
	bool IsEmpty(){if(root=NULL)return 1;else return 0;}
	void CreateBiTree(T space, T fin) //建立二叉树
	{
		SqQueue<ThrNode<T>*> Q;
		T x;
		ThrNode<T>* cur;
		cin >> x;
		if (x != space&&x != fin)
		{
			root = new ThrNode<T>(x, NULL, NULL,0,0);
			Q.EnQueue(root);
			while (!Q.isEmpty())
			{
				Q.DeQueue(cur);
				cin >> x;
				if (x == fin)
					return;
				if (x == space)
					cur->lchild = NULL;
				else
				{
					cur->lchild = new ThrNode<T>(x, NULL, NULL,0,0);
					Q.EnQueue(cur->lchild);
				}
				cin >> x;
				if (x == fin)
					return;
				if (x == space)
					cur->rchild = NULL;
				else
				{
					cur->rchild = new ThrNode<T>(x, NULL, NULL,0,0);
					Q.EnQueue(cur->rchild);
				}
			}
		}
	}
	void InThreading(ThrNode<T>* p,ThrNode<T>* &pre){
		//以指针p所指向的二叉树进行中序遍历，遍历过程中进行线索化  
        //pre指针是p的前驱指针
		if (p){
			InThreading(p->lchild,pre);
			if(p->lchild==NULL){
				p->LTag=1; p->lchild=pre;
			}
			if(pre!=NULL && pre->rchild==NULL){
				pre->RTag=1;pre->rchild=p;
			}
			pre=p;
			InThreading(p->rchild,pre);
		}
	}	
	void InOrderThreading(){
		//将二叉树线索化，按中序遍历的顺序  
		ThrNode<T> *pre=NULL;
		if(root!=NULL){
			InThreading(root,pre);
			pre->rchild=NULL;pre->RTag=1;
		}
	}
	void InOrderTraverse_Thr(){
		ThrNode<T> *p=root;
        while(p->LTag==0)p=p->lchild;
		cout<<p->data<<' ';
        while(p->rchild){
			if(p->RTag==0){
				p=p->rchild;
                while(p->LTag==0)
					p=p->lchild;
			}
			else p=p->rchild;
			cout<<p->data<<' ';
		}
		cout<<endl;
	}
	void display1(){
		PreOrderTraverse(root);
		cout<<endl;
	}
	void display2(){
		InOrderTraverse(root);
		cout<<endl;
	}
	void display3(){
		PostOrderTraverse(root);
		cout<<endl;
	}
	void PreOrderTraverse(ThrNode<T> *temp){
		if(temp){
			cout<<temp->data<<' ';
			PreOrderTraverse(temp->lchild);
			PreOrderTraverse(temp->rchild);
		}
	}
	void InOrderTraverse(ThrNode<T> *temp){
		if(temp){
			InOrderTraverse(temp->lchild);
			cout<<temp->data<<' ';
			InOrderTraverse(temp->rchild);
		}
	}
	void PostOrderTraverse(ThrNode<T> *temp){
		if(temp){
			PostOrderTraverse(temp->lchild);
			PostOrderTraverse(temp->rchild);
			cout<<temp->data<<' ';
		}
	}
private:
	ThrNode<T> *root;
};
int main(){
	BiThrTree<char> T;
	char space,fin;
	cout << "请输入空结点标识字符 ";
	cin >> space;
	cout << "请输入结束标识字符 ";
	cin >> fin;
	cout << "请依次输入结点，以空格分隔 ";
	T.CreateBiTree(space, fin);
	cout<<"先序遍历结果为："<<endl;
	T.display1();
	cout<<"中序遍历结果为："<<endl;
	T.display2();
	cout<<"后序遍历结果为："<<endl;
	T.display3();
	T.InOrderThreading();
    cout<<"二叉树已中序线索化"<<endl;
	cout<<"中序线索化后中序遍历结果为："<<endl;
	T.InOrderTraverse_Thr();
	return 0;
}