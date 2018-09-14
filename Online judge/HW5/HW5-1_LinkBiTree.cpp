#define _CTR_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef char ElemType;
struct BiTreeNode {
	ElemType data;
	//BiTreeNode* parent;
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
	void TraverseBiTree_Pre(BiTree &);
	void TraverseBiTree_Mid(BiTree &);
	void TraverseBiTree_Post(BiTree &);
	void TraverseBiTree_Layer(BiTree &);
	int BiTreeLevel(BiTree &);
	void BiTreePrint(BiTree &, int);
	BiTree bi;
	int level;
	InitTree(bi);
	CreatBiTree_Pre(bi);
	TraverseBiTree_Pre(bi);
	putchar('\n');
	TraverseBiTree_Mid(bi);
	putchar('\n');
	TraverseBiTree_Post(bi);
	putchar('\n');
	TraverseBiTree_Layer(bi);
	putchar('\n');
	level = BiTreeLevel(bi);
	//cout << level<<"*********";
	BiTreePrint(bi, 1);
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
void TraverseBiTree_Pre(BiTree &bi)
{
	if (!bi)
		return;
	putchar(bi->data);
	TraverseBiTree_Pre(bi->lchild);
	TraverseBiTree_Pre(bi->rchild);
}
void TraverseBiTree_Mid(BiTree &bi)
{
	if (!bi)
		return;
	TraverseBiTree_Mid(bi->lchild);
	putchar(bi->data);
	TraverseBiTree_Mid(bi->rchild);
}
void TraverseBiTree_Post(BiTree &bi)
{
	if (!bi)
		return;
	TraverseBiTree_Post(bi->lchild);
	TraverseBiTree_Post(bi->rchild);
	putchar(bi->data);
}
void TraverseBiTree_Layer(BiTree &bi)
{
	BiTree layer[100];
	int p = 0,q=1;
	if (bi)
		layer[0] = bi;
	while (p<q) {
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
void BiTreePrint(BiTree &bi, int level)
{
	if (!bi)
		return;
	BiTreePrint(bi->rchild, level + 1);
	for (int i = 1; i < level; i++)
		printf("     ");
	printf("%c\n", bi->data);
	BiTreePrint(bi->lchild, level + 1);
}