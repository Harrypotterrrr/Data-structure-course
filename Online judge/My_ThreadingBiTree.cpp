#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
enum PointerTag{Link,Thread};
typedef char TElemType;
class BiThrNode;
typedef BiThrNode* BiThrTree;
class BiThrNode
{
	private:
		TElemType data;
		BiThrTree lchild, rchild;
		PointerTag ltag;
		PointerTag rtag;
	public:
		BiThrNode() {
			//data = '\0';
			lchild = NULL;
			rchild = NULL;
			ltag = Link;
			rtag = Thread;
		}
		
		void InThreading_Mid(BiThrTree &);
		void TraverseThrTree_Mid(BiThrTree &);
		void CreateBiTree_Pre();
		void IsEmptyThrTree(BiThrTree &);
		void PrintThrTree_Pre();
};

BiThrTree pre;		//???
void BiThrNode::InThreading_Mid(BiThrTree &btt)
{
	if (btt) {
		InThreading_Mid(btt->lchild);
		if (!btt->lchild) {
			btt->lchild = pre;
			btt->ltag = Thread;
		}
		if (!pre->rchild) {
			pre->rchild = btt;
			pre->rtag = Thread;
		}
		pre = btt;
		InThreading_Mid(btt->rchild);
	}
}
void BiThrNode::TraverseThrTree_Mid(BiThrTree &btt)
{
	BiThrTree p = btt;
	p = btt->lchild;
	while (p != btt) {
		while (p->ltag != Link)
			p = p->lchild;
		putchar(p->data);
		while (p->rtag == Thread && p->rchild != btt) {
			p = p->rchild;
			putchar(p->data);
		}
		p = p->rchild;
	}
}
void BiThrNode::CreateBiTree_Pre()
{
	char c = getchar();
	if (c == '#')
		return;
	this = new BiThrNode;
	nw.data = c;
	nw.lchild = NULL;
	nw.rchild = NULL;
	nw.lchild->CreateBiTree_Pre();
	nw.rchild->CreateBiTree_Pre();
}
void BiThrNode::PrintThrTree_Pre()
{
	if (this) {
		cout << this->data;
		this->lchild->PrintThrTree_Pre();
		this->rchild->PrintThrTree_Pre();
	}
}
int main()
{
	BiThrNode btt;
	btt.CreateBiTree_Pre();
	btt.PrintThrTree_Pre();
	putchar('\n');
	return 0;
}