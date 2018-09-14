#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 10000
using namespace std;
typedef int ElemList;
struct SeqList {
    ElemList *data;
    int length;
};
int main()
{
    void InitList(SeqList &);
    void MergeList(SeqList &, SeqList &, SeqList &);
 
    SeqList la, lb, lc;
    InitList(la);
    InitList(lb);
    MergeList(la, lb, lc);
    return 0;
}
void InitList(SeqList &L)
{
    void PrintList(SeqList &);
    L.data = (ElemList*)malloc(LIST_INIT_SIZE * sizeof(ElemList));
    L.length = 0;
    ElemList *p = L.data + 1;
    int n;
    while (scanf("%d", &n) && n) {
        *p++ = n;
        L.length++;
    }
 
    for (int i = 1; i < L.length; i++) {
//        bool flag = false;
        for(int j=1 ; j<=L.length-i ; j++)
            if (*(L.data + j) > *(L.data + j + 1)) {
                int chg = *(L.data + j);
                *(L.data + j) = *(L.data + j + 1);
                *(L.data + j + 1) = chg;
//                flag = true;
            }
//        if (flag)
//            break;
    }
 
    //PrintList(L);
}
void MergeList(SeqList &la, SeqList &lb, SeqList &lc)
{
    void PrintList(SeqList &);
 
    ElemList *p = la.data + 1, *q = lb.data + 1, *r;
    ElemList *la_last = la.data + la.length, *lb_last = lb.data + lb.length;
    lc.length = la.length + lb.length;
    lc.data = (ElemList*)malloc((lc.length) * sizeof(ElemList));
    r = lc.data + 1;
    while (p <= la_last && q <= lb_last) {
        if (*p < *q)
            *r++ = *p++;
        else
            *r++ = *q++;
    }
    while (p <= la_last)
        *r++ = *p++;
    while (q <= lb_last)
        *r++ = *q++;
    PrintList(lc);
}
void PrintList(SeqList &L)
{
    ElemList *p = L.data + 1, *last = L.data + L.length;
    printf("%d", *p++);
    while (p <= last) {
        printf(" %d", *p++);
    }
    putchar('\n');
}