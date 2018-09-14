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
struct BiTNode 
{
	T data;
	BiTNode *lchild, *rchild;
public:
	BiTNode(){};
	BiTNode(T value, BiTNode *p, BiTNode *q){
		data = value;
		lchild = p;
		rchild = q;
	}
};
template<typename T>
class BiTree{
public:
	BiTree(){root=NULL;}
	bool IsEmpty(){if(root=NULL)return 1;else return 0;}
	void CreateBiTree(T space, T fin) //建立二叉树
	{
		SqQueue<BiTNode<T>*> Q;
		T x;
		BiTNode<T>* cur;
		cin >> x;
		if (x != space&&x != fin)
		{
			root = new BiTNode<T>(x, NULL, NULL);
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
					cur->lchild = new BiTNode<T>(x, NULL, NULL);
					Q.EnQueue(cur->lchild);
				}
				cin >> x;
				if (x == fin)
					return;
				if (x == space)
					cur->rchild = NULL;
				else
				{
					cur->rchild = new BiTNode<T>(x, NULL, NULL);
					Q.EnQueue(cur->rchild);
				}
			}
		}
	}
	void ClearBiTree(BiTNode<T>* root) //清空二叉树
	{
		if (root == NULL)
			return;
		else
		{
			ClearBiTree(root->lchild);
			ClearBiTree(root->rchild);
			delete root;
		}
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
	void PreOrderTraverse(BiTNode<T> *temp){
		if(temp){
			cout<<temp->data<<' ';
			PreOrderTraverse(temp->lchild);
			PreOrderTraverse(temp->rchild);
		}
	}
	void InOrderTraverse(BiTNode<T> *temp){
		if(temp){
			InOrderTraverse(temp->lchild);
			cout<<temp->data<<' ';
			InOrderTraverse(temp->rchild);
		}
	}
	void PostOrderTraverse(BiTNode<T> *temp){
		if(temp){
			PostOrderTraverse(temp->lchild);
			PostOrderTraverse(temp->rchild);
			cout<<temp->data<<' ';
		}
	}
	void LevelOrderTraversal(BiTNode<T>* root) //层序遍历
	{
		BiTNode<T> *p;
		SqQueue<BiTNode<T>*> Q;
		if (root)
		{
			Q.EnQueue(root);
			while (!Q.isEmpty())
			{
				Q.DeQueue(p);
				cout << p->data << ' ';
				if (p->lchild)
					Q.EnQueue(p->lchild);
				if (p->rchild)
					Q.EnQueue(p->rchild);
			}
		}
	}
	int Count(BiTNode<T>* root) //求结点个数
	{
		if (root == NULL)
			return 0;
		return 1 + Count(root->lchild) + Count(root->rchild);
	}
	int Depth(BiTNode<T>* root) //求深度
	{
		int l,r;
		if (root == NULL)
			return 0;
		else
		{
			l = Depth(root->lchild);
			r = Depth(root->rchild);
			return max(l, r) + 1;
		}
	}
	int Leave(BiTNode<T>* root) //求叶子结点数
	{
		if (root == NULL)
			return 0;
		if (root->lchild == NULL&&root->rchild == NULL)
			return 1;
		return Leave(root->lchild) + Leave(root->rchild);
	}
	BiTNode<T>* GetRoot()
	{
		return root;
	}
private:
	BiTNode<T> *root;
};
void mainpp()
{
	cout << "\t*   1.建立二叉树     *\n";
	cout << "\t*   2.先序遍历       *\n";
	cout << "\t*   3.中序遍历       *\n";
	cout << "\t*   4.后序遍历       *\n";
	cout << "\t*   5.层序遍历       *\n";
	cout << "\t*   6.求深度         *\n";
	cout << "\t*   7.求总结点数     *\n";
	cout << "\t*   8.求叶子结点数   *\n";
	cout << "\t*   9.清空          *\n";
	cout << "\t*   0.退出           *\n";
}
int main(){
    char space, fin;
	BiTree<char> T;
	int input;
	mainpp();
	while (1)
	{
		cout << "请输入0-9：";
		cin >> input;
		if (input == 0)
			break;
		switch (input)
		{
		case 1:
			cout << "请输入空结点标识字符 ";
			cin >> space;
			cout << "请输入结束标识字符 ";
			cin >> fin;
			cout << "请依次输入结点，以空格分隔 ";
			T.CreateBiTree(space, fin);
			break;
		case 2:
			T.display1();
			break;
		case 3:
			T.display2();
			break;
		case 4:
			T.display3();
			break;
		case 5:
			T.LevelOrderTraversal(T.GetRoot());
			cout << endl;
			break;
		case 6:
			cout << "深度为：" << T.Depth(T.GetRoot()) << endl;
			break;
		case 7:
			cout << "结点总数为：" << T.Count(T.GetRoot()) << endl;
			break;
		case 8:
			cout << "叶子结点数为：" << T.Leave(T.GetRoot()) << endl;
			break;
		case 9:
			T.ClearBiTree(T.GetRoot());
			cout << "已清空" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}