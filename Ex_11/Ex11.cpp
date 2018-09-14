#include <iostream>
using namespace std;
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
	void CreateBiTree(T space, T fin) //����������
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
	void ClearBiTree(BiTNode<T>* root) //��ն�����
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
	void LevelOrderTraversal(BiTNode<T>* root) //�������
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
	int Count(BiTNode<T>* root) //�������
	{
		if (root == NULL)
			return 0;
		return 1 + Count(root->lchild) + Count(root->rchild);
	}
	int Depth(BiTNode<T>* root) //�����
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
	int Leave(BiTNode<T>* root) //��Ҷ�ӽ����
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
	cout << "\t*   1.����������     *\n";
	cout << "\t*   2.�������       *\n";
	cout << "\t*   3.�������       *\n";
	cout << "\t*   4.�������       *\n";
	cout << "\t*   5.�������       *\n";
	cout << "\t*   6.�����         *\n";
	cout << "\t*   7.���ܽ����     *\n";
	cout << "\t*   8.��Ҷ�ӽ����   *\n";
	cout << "\t*   9.���          *\n";
	cout << "\t*   0.�˳�           *\n";
}
int main(){
    char space, fin;
	BiTree<char> T;
	int input;
	mainpp();
	while (1)
	{
		cout << "������0-9��";
		cin >> input;
		if (input == 0)
			break;
		switch (input)
		{
		case 1:
			cout << "������ս���ʶ�ַ� ";
			cin >> space;
			cout << "�����������ʶ�ַ� ";
			cin >> fin;
			cout << "�����������㣬�Կո�ָ� ";
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
			cout << "���Ϊ��" << T.Depth(T.GetRoot()) << endl;
			break;
		case 7:
			cout << "�������Ϊ��" << T.Count(T.GetRoot()) << endl;
			break;
		case 8:
			cout << "Ҷ�ӽ����Ϊ��" << T.Leave(T.GetRoot()) << endl;
			break;
		case 9:
			T.ClearBiTree(T.GetRoot());
			cout << "�����" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}