#include <iostream>
#include <iomanip>
#define LENGTH_HAFFMANTREE 100
using namespace std;
struct HaffmanNode {
	int weight;
	int father = 0;
	int lchild = 0, rchild = 0;
};
typedef HaffmanNode *HaffmanTree;
void swap(int *s1, int *s2)
{
	int temp;
	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}
void SelectMin(HaffmanTree &ht, int n, int *s1, int*s2)
{
	int i;
	for (i = 1; i <= n; i++) {
		if (!ht[i].father) {
			if (!(*s1))
				*s1 = i;
			else {
				*s2 = i;
				break;
			}
		}
	}
	if (ht[*s1].weight > ht[*s2].weight)
		swap(s1, s2);
	for (++i;i < n;i++) {
		if (!ht[i].father && ht[i].weight < ht[*s2].weight) {
			*s2 = i;
			if (ht[*s1].weight > ht[*s2].weight)
				swap(s1, s2);
		}
	}
}
void CreateHaffmanTree(HaffmanTree &ht)
{
	int n, m;
	int *s1 = new int, *s2 = new int;
	cin >> n;
	m = 2 * n - 1;

	ht = new HaffmanNode[m + 1];
	ht[0].weight = m;
	for (int i = 1; i <= n; i++)
		cin >> ht[i].weight;
	for (int i = n + 1;i <= m;i++) {
		*s1 = *s2 = 0;
		SelectMin(ht, i, s1, s2);
		ht[i].weight = ht[*s1].weight + ht[*s2].weight;
		ht[i].lchild = *s1;
		ht[i].rchild = *s2;
		ht[*s1].father = ht[*s2].father = i;
	}
}
int CalcHaffmanWPL(HaffmanTree &ht, int i, int depth)
{
	if (!ht[i].lchild && !ht[i].rchild)
		return ht[i].weight*depth;
	return CalcHaffmanWPL(ht, ht[i].lchild, depth + 1) + CalcHaffmanWPL(ht, ht[i].rchild, depth + 1);
}
void PrintHaffmanTree(HaffmanTree &hT)
{
	cout << "index weight parent lChild rChild" << endl;
	cout << left;    // ×ó¶ÔÆëÊä³ö 
	for (int i = 1, m = hT[0].weight; i <= m; ++i) {
		cout << setw(5) << i << " ";
		cout << setw(6) << hT[i].weight << " ";
		cout << setw(6) << hT[i].father << " ";
		cout << setw(6) << hT[i].lchild << " ";
		cout << setw(6) << hT[i].rchild << endl;
	}
}
int main()
{
	HaffmanTree ht;
	CreateHaffmanTree(ht);
	cout << CalcHaffmanWPL(ht, ht[0].weight, 0) << endl;
	//PrintHaffmanTree(ht);
	return 0;
}