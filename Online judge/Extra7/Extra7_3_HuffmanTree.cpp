#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#define LENGTH_HuffmanTREE 10000
using namespace std;
string str;
struct HuffmanNode {
	char data;
	HuffmanNode *lchild, *rchild;
};
typedef HuffmanNode *HuffmanTree;
void CreateHuffmanTree(HuffmanTree &ht, int n)
{
	HuffmanTree p,q;
	string str;
	char c;
	for (int i = 1; i <= n; i++) {
		getchar();
		c = getchar();
		cin >> str;
		//cin.ignore(1024, '\n');
		p = ht;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '0') {
				if (!p->lchild) {
					q = new(HuffmanNode);
					q->data = '\0';
					q->rchild = q->lchild = NULL;
					p->lchild = q;
				}
				p = p->lchild;
			}
			else {
				if (!p->rchild) {
					q = new(HuffmanNode);
					q->data = '\0';
					q->rchild = q->lchild = NULL;
					p->rchild = q;
				}
				p = p->rchild;
			}
		}
		p->data = c;
	}
}
void DecodingHuffmanTree(HuffmanTree &ht, string code)
{
	HuffmanTree p = ht;
	for (int i = 0; i < code.length(); i++) {
		if (code[i] == '0') {
			p = p->lchild;
		}
		else {
			p = p->rchild;
		}
		if (p->data != '\0') {
			cout << p->data;
			p = ht;

		}
	}
	putchar('\n');
}
int main()
{
	HuffmanTree ht = new(HuffmanNode);
	string str,code;
	int n;
	cin >> n;
	//cin.ignore(1024, '\n');
	ht->lchild = ht->rchild = NULL;
	CreateHuffmanTree(ht,n);
	cin >> code;
	DecodingHuffmanTree(ht, code);
	return 0;
}
