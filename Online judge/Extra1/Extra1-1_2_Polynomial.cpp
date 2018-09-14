#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct PolyNode{
	int coe;	//系数
	int exp;	//指数
	PolyNode *next;
};
typedef PolyNode* PolyList;
int main() 
{
	void InitialPoly(PolyList &, int);
	void PrintPoly(PolyList &);
	PolyList AddPoly(PolyList &, PolyList &);
	void PrintPoly(PolyList &);
	PolyList La, Lb, Lc;
	int La_len, Lb_len;
	scanf("%d", &La_len);
	InitialPoly(La, La_len);
	scanf("%d", &Lb_len);
	InitialPoly(Lb, Lb_len);
	Lc = AddPoly(La, Lb);
	PrintPoly(Lc);
	return 0;
}
void InitialPoly(PolyList &L, int n)
{
	PolyList p, q;
	L = (PolyList)malloc(sizeof(PolyNode));
	L->next = NULL;
	p = L;
	for (int i = 1; i <= n;i++) {
		q = (PolyList)malloc(sizeof(PolyNode));
		scanf("%d%d", &q->coe, &q->exp);
		q->next = NULL;

		p = L;

		while (p->next && q->exp > p->next->exp)
			p = p->next;
		if (!p->next)
			p->next = q;
		else {
			q->next = p->next;
			p->next = q;
		}
	}
}
PolyList AddPoly(PolyList &La, PolyList &Lb)
{
	PolyList p = La->next, q = Lb->next, r, temp;
	PolyList Lc = (PolyList)malloc(sizeof(PolyNode));
	Lc->next = NULL;
	r = Lc;
	while (p && q) {
			temp = (PolyList)malloc(sizeof(PolyNode));
		if (p->exp == q->exp) {
			temp->coe = p->coe + q->coe;
			temp->exp = p->exp;
			if (temp->coe) {
				r->next = temp;
				r = r->next;
			}
			p = p->next;
			q = q->next;
		}
		else if (p->exp > q->exp) {
			temp = q;
			r->next = temp;
			r = r->next;
			q = q->next;
		}
		else {
			temp = p;
			r->next = temp;
			r = r->next;
			p = p->next;
		}
	}
	if (q)
		r->next = q;
	if (p)
		r->next = p;
	return Lc;
}
void PrintPoly(PolyList &L)
{
	//cout << "*******" << endl;
	PolyList p = L->next;
	while (p) {
		printf("%d %d\n", p->coe, p->exp);
		p = p->next;
	}
	//cout << "*******" << endl;
}