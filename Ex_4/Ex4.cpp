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
	LinkList(){head=new LNode;head->next=head;len=0;}//构造函数

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
    }//尾插法建立长度为n的链表

	LNode *Travel(LNode *p,int s){        //报数
	for(int i=1;i<s;i++){
		p=p->next;
	}
	return p;
}

	LNode *Output(LNode *p){        //删除结点并输出其值
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
	    cout<<"n个人围坐一圈，请输入n：";
		cin>>n;
		cout<<"从第s个人开始报数，请输入s：";
		cin>>s;
		cout<<"数到第m个人出列,请输入m：";
		cin>>m;
		if(n<s)cout<<"输入的n小于s，请重新输入"<<endl;
		else break;
	}
	p->Create_L(n);
	cout<<"按出列次序得到的"<<n<<"个人的序列："<<endl;
	p->Josephus(s,m);
	return 0;
}
	