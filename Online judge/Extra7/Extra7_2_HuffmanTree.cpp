#include <iostream>
#include <string>
#include <iomanip>
#define LENGTH_HuffmanTREE 100
using namespace std;
string str;
struct HuffmanNode {
	int weight;
	int father = 0;
	int lchild = 0, rchild = 0;
};
typedef HuffmanNode *HuffmanTree;
void swap(int *s1, int *s2)
{
	int temp;
	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}
void SelectMin(HuffmanTree &ht, int n, int *s1, int*s2)
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
void CreateHuffmanTree(HuffmanTree &ht, int n)
{
	int m;
	int *s1 = new int, *s2 = new int;
	m = 2 * n - 1;

	ht = new HuffmanNode[m + 1];
	ht[0].weight = m;
	int wi, pi, li;
	for (int i = 1; i <= m; i++) {
		cin >> wi >> pi >> li;
		ht[i].weight = wi;
		ht[i].father = pi;
		if (li)
			ht[pi].rchild = i;
		else
			ht[pi].lchild = i;
	}
}
int CalcHuffmanWPL(HuffmanTree &ht, int i, int depth)
{
	if (!ht[i].lchild && !ht[i].rchild)
		return ht[i].weight*depth;
	return CalcHuffmanWPL(ht, ht[i].lchild, depth + 1) + CalcHuffmanWPL(ht, ht[i].rchild, depth + 1);
}
void PrintTraverseTree(HuffmanTree &ht, int i, int depth)
{
	if (!ht[i].lchild && !ht[i].rchild) {
		for (int k = 1; k <= depth; k++)
			cout << "\t";
		cout << ht[i].weight << endl;
		return;
	}
	PrintTraverseTree(ht, ht[i].rchild, depth + 1);
	for (int i = 1; i <= depth; i++)
		cout << "\t";
	cout << ht[i].weight << endl;
	PrintTraverseTree(ht, ht[i].lchild, depth + 1);
}
void DestroyHuffmanTree(HuffmanTree &ht)
{
	delete[] ht;
	ht = NULL;
}
void PrintHuffmanTree(HuffmanTree &hT)
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
bool flag = false;
void DecodingHuffmanTree(HuffmanTree &ht, string str, int k, int i)
{
	if (flag)
		return;
	if (k == i) {
		cout << str;
		flag = true;
		return;
	}
	if (!ht[k].lchild && !ht[k].rchild)
		return;
	DecodingHuffmanTree(ht, str + "1", ht[k].rchild, i);
	DecodingHuffmanTree(ht, str + "0", ht[k].lchild, i);
}
int main()
{
	HuffmanTree ht;
	int n;
	cin >> n;
	CreateHuffmanTree(ht, n);
	//cout << CalcHuffmanWPL(ht, ht[0].weight, 0) << endl;
	//PrintHuffmanTree(ht);
	//PrintTraverseTree(ht, ht[0].weight, 0);
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
		str = "";
		flag = false;
		DecodingHuffmanTree(ht, str, ht[0].weight, i);
		putchar('\n');
	}
	return 0;
}