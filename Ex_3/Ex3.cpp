#include <iostream>
#include <cmath>
using namespace std;
class LinkList;
typedef LinkList polynomial;
typedef struct{
	float coef;
	int expn;
}term,ElemType;

struct LNode
{
	ElemType data;
    LNode *next;
};

class LinkList{
private:
    LNode *head;
	int len;
public:
	LinkList(){head=new LNode;head->next=NULL;len=0;}
	~LinkList(){if(len)ClearList_L();head=NULL;}
	int ClearList_L(){
	LNode *p,*q;
	p=head;
	if(!(p->next))return 0;
	p=p->next;
	while(!p){
		q=p;
	    p=q->next;
		free(q);
	}
	len=0;
	return 1;
}
	int LocateElem(int e){
		LNode *p;
	    p=head->next;
	    int i = 1;
		while(i<=len&&p->data.expn!=e){
		    ++i;
		    p=p->next;
    	}
	    if(i<=len) return i;
	    else return 0;
	}
	void CreatePolyn(int m){
		//输入m项的系数和指数，建立表示一元多项式的有序链表
		LNode *p,*q=head;
		ElemType e;
		q->data.coef=0.0;q->data.expn=-1;
		int i;
		for(i=1;i<=m;++i){
			cin>>e.coef>>e.expn;
			if(!LocateElem(e.expn)){
				p=new LNode;
				p->data.coef=e.coef;
				p->data.expn=e.expn;
		        q->next=p;
				p->next=NULL;
		        q=p;
			}
		}
		len=m;
	}
	void Print(){
		LNode *p=head;
		if(len==0)cout<<"当前多项式为空"<<endl;
		else{
			cout<<"多项式各项为：";
		    for(int i=0;i<len;i++){
			    p=p->next;
			    cout<<p->data.coef<<"*x^"<<p->data.expn<<" ";
		    }
		    cout<<endl;
	    }
	}
	void Calculate(){
		LNode *p=head;
		p=p->next;
		float x;
		double result=0;
		cout<<"请依次输入x的值"<<endl;
		for(int i=0;i<len;i++){
			cin>>x;
			result+=p->data.coef*pow(x,p->data.expn);
			p=p->next;
		}
		cout<<"多项式的值为"<<result<<endl;
	}
	int GetLen(){return len;}
	void MergePolyn(){
		LNode *p=head,*q,*r;
		int i,n=len;
		for(i=0;i<n;i++){
			p=p->next;
			for(q=head->next;q!=p;q=q->next){
    				if(q->data.expn==p->data.expn){
					q->data.coef+=p->data.coef;
					r=head;while(r&&r->next!=p)r=r->next;
					if(r){r->next=p->next;free(p);p=r;--len;break;}
				}
			}
		}
		for(q=head->next;q!=NULL;q=q->next){
			if(q->data.coef==0){
				r=head;while(r&&r->next!=q)r=r->next;
				if(r){r->next=q->next;free(q);q=r;--len;}
			}
		}
	}

	friend void AddPolyn(polynomial &Pa,polynomial &Pb,polynomial &Pc);
	friend void SubPolyn(polynomial &Pa,polynomial &Pb,polynomial &Pc);
	friend void MulPolyn(polynomial &Pa,polynomial &Pb,polynomial &Pc);
}; 

int cmp(int a,int b){
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}

void AddPolyn(polynomial &Pa,polynomial &Pb,polynomial &Pc){
	LNode *qa=Pa.head;
	LNode *qb=Pb.head;
	qa=qa->next;qb=qb->next;
	LNode *qc=Pc.head,*r;
	ElemType a,b;
	float sum;
	while(qa&&qb){
		a=qa->data;b=qb->data;
		switch(cmp(a.expn,b.expn)){
		case -1:
			r=new LNode;
			r->data.coef=a.coef;
			r->data.expn=a.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
            qa=qa->next;
			Pc.len++;
			break;
		case 0:
			sum=a.coef+b.coef;
			if(sum!=0.0){
				r=new LNode;
				r->data.coef=sum;
				r->data.expn=a.expn;
                qc->next=r;
                r->next=NULL;
                qc=r;
				qa=qa->next;
                qb=qb->next;
			    Pc.len++;}
			else{
				qa=qa->next;
				qb=qb->next;}
			break;
		case 1:
			r=new LNode;
			r->data.coef=b.coef;
			r->data.expn=b.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
            qb=qb->next;
			Pc.len++;
			break;
		}
	}
	while(qa!=NULL){
		    r=new LNode;
			r->data.coef=qa->data.coef;
			r->data.expn=qa->data.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
			qa=qa->next;
	        Pc.len++;}
	while(qb!=NULL){
		    r=new LNode;
			r->data.coef=qb->data.coef;
			r->data.expn=qb->data.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
			qb=qb->next;
	        Pc.len++;}
}

void SubPolyn(polynomial &Pa,polynomial &Pb,polynomial &Pc){
	LNode *qa=Pa.head;
	LNode *qb=Pb.head;
	qa=qa->next;qb=qb->next;
	LNode *qc=Pc.head,*r;
	ElemType a,b;
	float sub;
	while(qa&&qb){
		a=qa->data;b=qb->data;
		switch(cmp(a.expn,b.expn)){
		case -1:
			r=new LNode;
			r->data.coef=a.coef;
			r->data.expn=a.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
            qa=qa->next;
			Pc.len++;
			break;
		case 0:
			sub=a.coef-b.coef;
			if(sub!=0.0){
				r=new LNode;
				r->data.coef=sub;
				r->data.expn=a.expn;
                qc->next=r;
                r->next=NULL;
                qc=r;
				qa=qa->next;
                qb=qb->next;
			    Pc.len++;}
			else{
				qa=qa->next;
				qb=qb->next;}
			break;
		case 1:
			r=new LNode;
			r->data.coef=b.coef;
			r->data.expn=b.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
            qb=qb->next;
			Pc.len++;
			break;
		}
	}
	while(qa!=NULL){
		    r=new LNode;
			r->data.coef=qa->data.coef;
			r->data.expn=qa->data.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
			qa=qa->next;
	        Pc.len++;}
	while(qb!=NULL){
		    r=new LNode;
			r->data.coef=qb->data.coef;
			r->data.expn=qb->data.expn;
			qc->next=r;
			qc=r;
            r->next=NULL;
			qb=qb->next;
	        Pc.len++;}
}

void MulPolyn(polynomial &Pa,polynomial &Pb,polynomial &Pc){
	LNode *pa=Pa.head;
	LNode *pb=Pb.head;
	LNode *pc=Pc.head;
	LNode *p,*q,*r;
	for(p=pa->next;p;p=p->next)
		for(q=pb->next;q;q=q->next){
			r=new LNode;
			r->data.coef=p->data.coef*q->data.coef;
			r->data.expn=p->data.expn+q->data.expn;
			pc->next=r;
			pc=r;
			r->next=NULL;
			Pc.len++;
		}
}
	

void mainpp(){
	cout<<"1、多项式的创建\n";
    cout<<"2、多项式的相加\n";
    cout<<"3、多项式的相减\n";
    cout<<"4、多项式的相乘\n";
    cout<<"5、多项式的求值\n";
	cout<<"0、退出\n";
    cout<<"请输入0-5：";
}

int main(){
	int m,input;
	polynomial Pa,Pb,Pc,P;
	while(1){
		mainpp();
		cin>>input;
		if(input==0)break;
		switch(input){
		case 1:
			cout<<"请输入要建立的多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			P.CreatePolyn(m);
			P.Print();
			break;

		case 2:
			cout<<"请输入第一个多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			Pa.CreatePolyn(m);
			cout<<"请输入第二个多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			Pb.CreatePolyn(m);
			AddPolyn(Pa,Pb,Pc);
			Pc.Print();
			Pa.ClearList_L();
			Pb.ClearList_L();
			Pc.ClearList_L();
			break;

		case 3:
			cout<<"请输入第一个多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			Pa.CreatePolyn(m);
			cout<<"请输入第二个多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			Pb.CreatePolyn(m);
			SubPolyn(Pa,Pb,Pc);
			Pc.Print();
			Pa.ClearList_L();
			Pb.ClearList_L();
			Pc.ClearList_L();
			break;

		case 4:
			cout<<"请输入第一个多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			Pa.CreatePolyn(m);
			cout<<"请输入第二个多项式的项数：";
			cin>>m;
			cout<<"请连续输入"<<m<<"组系数和指数，以空格或回车间隔"<<endl;
			Pb.CreatePolyn(m);
			MulPolyn(Pa,Pb,Pc);
			Pc.MergePolyn();
			Pc.Print();
			Pa.ClearList_L();
			Pb.ClearList_L();
			Pc.ClearList_L();
			break;

		case 5:
			if(P.GetLen()==0){
				cout<<"当前多项式为空，请先建立"<<endl;
				break;}
			P.Calculate();
			break;

		default:
			break;
		}
	}
	return 0;
}