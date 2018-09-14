#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
enum PointerTag { Link, Thread };
typedef char TElemType;
class BiThrNode;
typedef BiThrNode* BiThrTree;
struct BiThrNode
{
	TElemType data;
	BiThrTree lchild, rchild;
	PointerTag ltag;
	PointerTag rtag;
};
BiThrTree pre = NULL;		//???

/*先序线索化*/
void InThreading_Pre(BiThrTree &btt)
{
	if (btt) {
		if (btt->ltag == Thread)
			btt->lchild = pre;
		if (pre && !pre->rchild)
			pre->rchild = btt;
		pre = btt;
		if (btt->ltag == Link)
			InThreading_Pre(btt->lchild);
		if (btt->rtag == Link)
			InThreading_Pre(btt->rchild);
	}
}

/*先序遍历线索化树*/
void TraverseThrTree_Pre(BiThrTree &btt)
{
	BiThrTree p = btt;
	/*连续求一个节点的后继*/
	while (p) {
		putchar(p->data);
		if (p->ltag == Link)
			p = p->lchild;
		else
			p = p->rchild;
	}
	putchar('\n');
}

void CreateBiTree_Pre(BiThrTree &btt)
{
	char c = getchar();
	if (c == '#')
		return;
	btt = new BiThrNode;
	btt->data = c;
	btt->lchild = NULL;
	btt->rchild = NULL;
	CreateBiTree_Pre(btt->lchild);
	if (btt->lchild)
		btt->ltag = Link;
	else
		btt->ltag = Thread;
	CreateBiTree_Pre(btt->rchild);
	if (btt->rchild)
		btt->rtag = Link;
	else
		btt->rtag = Thread;
}

void PrintThrTree(BiThrTree &btt, int n)
{
	if (btt) {
		if(btt->rtag == Link)
			PrintThrTree(btt->rchild, n + 1);
		for (int i = 1;i <= n;i++)
			cout << "     ";
		cout << btt->data << btt->ltag << btt->rtag << endl;
		if(btt->ltag == Link)
		PrintThrTree(btt->lchild, n + 1);
	}
}

int main()
{
	BiThrTree btt;
	CreateBiTree_Pre(btt);
	InThreading_Pre(btt);
	PrintThrTree(btt, 0);
	TraverseThrTree_Pre(btt);
	return 0;
}

