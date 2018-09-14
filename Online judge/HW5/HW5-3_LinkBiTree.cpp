#define _CTR_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;
typedef char ElemType;
struct BiTreeNode {
	ElemType data;
	BiTreeNode* lchild;
	BiTreeNode* rchild;
};
typedef BiTreeNode* BiTree;
int main()
{
	void InitTree(BiTree &);
	bool IsEmptyBiTree(BiTree &);
	void CreatBiTree_Pre(BiTree &);
	void ClearBiTree(BiTree &);
	void TraverseNoRecurBiTree_Pre(BiTree &);
	void TraverseNoRecurBiTree_Mid(BiTree &);
	void TraverseNoRecurBiTree_Post(BiTree &);
	void TraverseBiTree_Layer(BiTree &);
	int BiTreeLevel(BiTree &);
	int CountBiTreeNode(BiTree &);
	int CountBiTreeLeaves(BiTree &);
	void PrintBiTree(BiTree &, int);
	void PrintBiTree_reverse(BiTree &, int);

	void Postorder(BiTree T);

	BiTree bi;

	InitTree(bi);
	CreatBiTree_Pre(bi);
	TraverseNoRecurBiTree_Post(bi);
	//Postorder(bi);
	return 0;
}
void InitTree(BiTree &bt)
{
	bt = NULL;
}
bool IsEmptyBiTree(BiTree &bi)
{
	return bi == NULL ? true : false;
}
void CreatBiTree_Pre(BiTree &bi)
{
	char c = getchar();
	if (c == '#')
		return;
	bi = (BiTree)malloc(sizeof(BiTreeNode));
	bi->lchild = NULL;
	bi->rchild = NULL;
	bi->data = c;
	CreatBiTree_Pre(bi->lchild);
	CreatBiTree_Pre(bi->rchild);
}
void ClearBiTree(BiTree &bi)
{
	if (bi->lchild)
		ClearBiTree(bi->lchild);
	if (bi->rchild)
		ClearBiTree(bi->rchild);
	free(bi);
}
void TraverseNoRecurBiTree_Pre(BiTree &bi)
{
	stack<BiTree>sk;
	BiTree p = bi;
	while (p || !sk.empty()) {
		if (p) {
			sk.push(p);
			p = p->lchild;
		}
		else {
			p = sk.top();
			sk.pop();
			printf("%c", p->data);
			p = p->rchild;
		}
	}
	putchar('\n');
}
void TraverseNoRecurBiTree_Mid(BiTree &bi)
{
	stack <BiTree> sk;
	BiTree p = bi;
	while (p || !sk.empty()) {
		if (p) {
			sk.push(p);
			printf("push %c\n", p->data);
			p = p->lchild;
		}
		else {
			p = sk.top();
			printf("pop\n%c\n", p->data);
			sk.pop();
			p = p->rchild;
		}
	}
	putchar('\n');
}
void TraverseNoRecurBiTree_Post(BiTree &bi)
{
	BiTree p = bi, q = NULL;
	stack<BiTree>sk;
	while (p || !sk.empty()) {
		if (p) {
			sk.push(p);
			p = p->lchild;
		}
		else {
			p = sk.top();
			if (p->rchild != q) {
				p = p->rchild;
				q = p;
			}
			else {
				sk.pop();
				printf("%c", p->data);
				q = p;
				p = NULL;
			}
		}
	}
	putchar('\n');
}

void TraverseBiTree_Layer(BiTree &bi)
{
	BiTree layer[100];
	int p = 0, q = 1;
	if (bi)
		layer[0] = bi;
	while (p < q) {
		if (layer[p]->lchild)
			layer[q++] = layer[p]->lchild;
		if (layer[p]->rchild)
			layer[q++] = layer[p]->rchild;
		putchar(layer[p++]->data);
	}
}
int BiTreeLevel(BiTree &bi)
{
	int rdepth, ldepth;
	if (!bi)
		return 0;
	ldepth = BiTreeLevel(bi->lchild);
	rdepth = BiTreeLevel(bi->rchild);
	return (ldepth >= rdepth ? ldepth : rdepth) + 1;
}
int CountBiTreeLeaves(BiTree &bi)
{
	int count;
	if (!bi)
		return 0;
	if (!bi->lchild && !bi->rchild)
		return 1;
	count = CountBiTreeLeaves(bi->lchild);
	count += CountBiTreeLeaves(bi->rchild);
	return count;
}
int CountBiTreeNode(BiTree &bi)
{
	int count;
	if (!bi)
		return 0;
	count = CountBiTreeNode(bi->lchild);
	count += CountBiTreeNode(bi->rchild);
	return count + 1;
}
void PrintBiTree_reverse(BiTree &bi, int level)
{
	if (!bi)
		return;
	PrintBiTree_reverse(bi->lchild, level + 1);
	for (int i = 1; i < level;i++)
		printf("     ");
	printf("%c\n", bi->data);
	PrintBiTree_reverse(bi->rchild, level + 1);
}
void PrintBiTree(BiTree &bi, int level)
{
	if (!bi)
		return;
	PrintBiTree(bi->rchild, level + 1);
	for (int i = 1; i < level; i++)
		printf("     ");
	printf("%c\n", bi->data);
	PrintBiTree(bi->lchild, level + 1);
}
