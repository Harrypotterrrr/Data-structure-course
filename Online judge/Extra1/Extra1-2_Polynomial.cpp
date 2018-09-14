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
	void AddPoly(PolyList &, PolyList &);
	void MulPoly(PolyList &, PolyList &);
	void PrintPoly(PolyList &);
	PolyList La, Lb;
	int La_len, Lb_len;
	scanf("%d", &La_len);
	InitialPoly(La, La_len);
	scanf("%d", &Lb_len);
	InitialPoly(Lb, Lb_len);
	MulPoly(La, Lb);
	PrintPoly(La);
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
void MulPoly(PolyList &La, PolyList &Lb)
{
	void AddPoly(PolyList &, PolyList &);
	PolyList p = La->next, q = Lb->next;
	PolyList Lc, Lc_tmp, r, nw_node;
	Lc = (PolyList)malloc(sizeof(PolyNode));
	Lc->next = NULL;
	while (p) {
		q = Lb->next;
		Lc_tmp = (PolyList)malloc(sizeof(PolyNode));
		r = Lc_tmp;
		while (q) {
			nw_node = (PolyList)malloc(sizeof(PolyNode));
			nw_node->coe = p->coe * q->coe;
			nw_node->exp = p->exp + q->exp;
			r->next = nw_node;
			r = r->next;
			q = q->next;
		}
		r->next = NULL;
		AddPoly(Lc, Lc_tmp);
		p = p->next;
		free(La->next);
		La->next = p;
	}
	AddPoly(La, Lc);
	free(Lb);
	Lb = NULL;
}
void AddPoly(PolyList &La, PolyList &Lb)
{
	PolyList p = La->next, q = Lb->next;
	PolyList p_pre = La, q_tmp;
	int temp;
	while (p && q) {
		if (p->exp == q->exp) {
			temp = p->coe + q->coe;
			if (temp) {
				p->coe = temp;
				p_pre = p;
				p = p->next;
			}
			else {
				p = p->next;
				free(p_pre->next);
				p_pre->next = p;
			}
			q_tmp = q;
			q = q->next;
			free(q_tmp);
		}
		else if (p->exp > q->exp) {
			q_tmp = q->next;
			q->next = p;
			p_pre->next = q;
			p_pre = q;
			q = q_tmp;
		}
		else {
			p_pre = p;
			p = p->next;
		}
	}
	if (q)
		p_pre->next = q;
	free(Lb);
	Lb = NULL;
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