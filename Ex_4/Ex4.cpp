#include <iostream>
using namespace std;
#define OK 1
#define ERROR -1
struct LNode
{
    int data;
    LNode *next;
};

class LinkList
{
private:
    LNode *head;
	int len;
public:
	LinkList(){head=new LNode;head->next=head;len=0;}//���캯��

    void Create_L(int n){
	    LNode *p,*q;
	    q=head;
		if(n>=1)head->data=1;
	    for(int i=2;i<=n;i++){
	    	p=new LNode;
			p->data=i;
	    	q->next=p;
	    	q=p;
	    }
	    q->next=head;
	    len=n;
    }//β�巨��������Ϊn������

	LNode *Travel(LNode *p,int s){        //����
	for(int i=1;i<s;i++){
		p=p->next;
	}
	return p;
}

	LNode *Output(LNode *p){        //ɾ����㲢�����ֵ
	LNode *q;
	cout<<p->data<<' ';
	q=p;
	for(int i=1;i<len;i++){q=q->next;}
	q->next=p->next;
	free(p);
	p=q->next;
	--len;
	return p;
}

void Josephus(int s,int m){
	LNode *p=head;
	p=Travel(p,s);
	while(len!=0){
		p=Travel(p,m);
		p=Output(p);
	}
	cout<<endl;
}

};

int main(){
	int n,s,m;
	LinkList L,*p;
	p=&L;
	while(1){
	    cout<<"n����Χ��һȦ��������n��";
		cin>>n;
		cout<<"�ӵ�s���˿�ʼ������������s��";
		cin>>s;
		cout<<"������m���˳���,������m��";
		cin>>m;
		if(n<s)cout<<"�����nС��s������������"<<endl;
		else break;
	}
	p->Create_L(n);
	cout<<"�����д���õ���"<<n<<"���˵����У�"<<endl;
	p->Josephus(s,m);
	return 0;
}
	