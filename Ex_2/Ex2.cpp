#include <iostream>
using namespace std;
#define OK 1
#define ERROR -1
typedef int ElemType;
struct LNode
{
    int data;
    LNode *next;
};

struct DuLNode
{
    int data;
	DuLNode *prior;
	DuLNode *next;
};

class LinkList
{
public:
    //单链表具体操作
LinkList(){head=new LNode;head->next=NULL;tail=head;len=0;}//构造函数

~LinkList(){if(len)ClearList_L();head=tail=NULL;}//析构函数
	
int ClearList_L(){
	LNode *p,*q;
	p=head;
	if(!(p->next))return ERROR;
	p=p->next;
	while(!p){
		q=p;
	    p=q->next;
		free(q);
	}
	tail=head;
	len=0;
	return OK;
}

int ListEmpty(){
	if(len==0) return NULL;
	else return OK;
}

void Create_L(int n){
	LNode *p;
	for(int i=0;i<n;i++){
		p=new LNode;
		cin>>p->data;
		p->next=head->next;
		head->next=p;
	}
	p=head;
	while(!(p->next))p=p->next;
	tail=p;
	len=n;
}//头插法建立长度为n的单链表

void Create2_L(int n){
	LNode *p,*q;
	q=head;
	for(int i=0;i<n;i++){
		p=new LNode;
		cin>>p->data;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	tail=q;
	len=n;
}//尾插法建立长度为n的单链表

int GetElem_L(int i,ElemType &e){
	LNode *p;
	p=head->next;
	int j=1;
	while(p&&j<i){
		p=p->next;++j;
	}
	if(!p||j>i)return ERROR;
	e=p->data;
	return OK;
}

int ListInsert_L(int i,ElemType e){
	LNode *p;
	p=head;
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		++j;
	}
	if(!p||j>i-1)return ERROR;
	LNode *s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	++len;
	return OK;
}

int ListDelete_L(int i,ElemType &e){
	LNode *p,*q;
	p=head;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	--len;
	return OK;
}

int LocateElem_L(int e){
	LNode *p;
	p=head->next;
	int i = 1;
	while(i<=len&&p->data!=e){
		++i;
		p=p->next;
	}
	if(i<=len) return i;
	else return ERROR;
}

void Print(){
	if(len==0){
		cout<<"当前链表为空"<<endl;
	}
	else{
		cout<<"当前链表为：";
	    LNode *p=head;
	    for(int i=0;i<len;i++){
		    p=p->next;
		    cout<<p->data<<" ";
	    }
	    cout<<endl;
	}
}
		
void MergeList_L(LinkList &La,LinkList &Lb){
	LNode *pa=La.head->next;
	LNode *pb=Lb.head->next;
	LNode *pc,*p;
	pc=head;
	while(pa&&pb){
		if(pa->data <= pb->data){
			p=new LNode;
			p->data=pa->data;
			pc->next=p;
			pc=p;
			pa=pa->next;
		}
		else{
			p=new LNode;
			p->data=pb->data;
			pc->next=p;
			pc=p;
			pb=pb->next;
		}
	}
	while(pa){
		p=new LNode;
		p->data=pa->data;
		pc->next=p;
		pc=p;
		pa=pa->next;
	}
	while(pb){
		p=new LNode;
		p->data=pb->data;
		pc->next=p;
		pc=p;
		pb=pb->next;
	}
	tail=pc;
	len=La.len+Lb.len;
	La.ClearList_L();
	Lb.ClearList_L();
}

void ChangeElem_L(LNode *p,LNode *q){
	int m=p->data;
	p->data=q->data;
	q->data=m;
}

void ReverseList_L(){
	LNode *p,*q;
	p=head;
	int j=len/2,i,k;
	for(i=0;i<j;i++){
		p=p->next;
		q=p;
		for(k=i+1;k<(len-i);k++)
			q=q->next;
		ChangeElem_L(p,q);
	}
}

int GetLen(){return len;}

void mainpp(){
	cout<<"\t1. 建立一个单链表     2. 输出一个单链表\n";
	cout<<"\t3. 销毁单链表         4. 清空单链表\n";
	cout<<"\t5. 按位置查找         6. 按值查找\n";
	cout<<"\t7. 按位置删除一个结点 8. 按位置插入一个结点\n";
	cout<<"\t9. 逆置单链表         10.合并两个有序链表\n";
	cout<<"\t11.返回链表长度       0. 退出\n";
	cout<<"请输入0-11：";
}

private:
    LNode *head;
	LNode *tail;
	int len;
}; 

class LinkList1
{
private:
    LNode *head;
	LNode *tail;
	int len;
public:
    //单链表具体操作
LinkList1(){head=new LNode;head->next=NULL;tail=head;tail->next=head;len=0;}//构造函数

~LinkList1(){if(len)ClearList_L();head=tail=NULL;}//析构函数

int ClearList_L(){
	LNode *p,*q;
	p=head;
	if((p->next)==head)return OK;
	p=p->next;
	while((p->next)!=head){
		q=p;
	    p=q->next;
		free(q);
	}
	tail=head;
	len=0;
	return OK;
}

int ListEmpty(){
	if(len==0) return NULL;
	else return OK;
}

void Create_L(int n){
	LNode *p,*q;
	q=head;
	for(int i=0;i<n;i++){
		p=new LNode;
		cin>>p->data;
		q->next=p;
		q=p;
	}
	q->next=NULL;
	tail=q;
	tail->next=head;
	len=n;
}//尾插法建立长度为n的单链表

int GetLen(){return len;}

int GetElem_L(int i,ElemType &e){
	LNode *p;
	p=head->next;
	int j=1;
	while(p!=head&&j<i){
		p=p->next;++j;
	}
	if(p==head||j>i)return ERROR;
	e=p->data;
	return OK;
}

int ListInsert_L(int i,ElemType e){
	LNode *p;
	p=head;
	int j=0;
	if(i<1||i>len+1)return ERROR;
	while(j<i-1){
		p=p->next;
		++j;
	}
	LNode *s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	++len;
	if(i==len)tail=s;
	return OK;
}

int ListDelete_L(int i,ElemType &e){
	LNode *p,*q;
	p=head;
	int j=0;
	if(i<1||i>len)return ERROR;
	while(j<i-1){
		p=p->next;
		++j;
	}
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	--len;
	if(i==len+1)tail=p;
	return OK;
}

int LocateElem_L(int e){
	LNode *p;
	p=head->next;
	int i = 1;
	while(i<=len&&p->data!=e){
		++i;
		p=p->next;
	}
	if(i<=len) return i;
	else return ERROR;
}

void MergeList_L(LinkList1 &La,LinkList1 &Lb){
	LNode *pa=La.head->next;
	LNode *pb=Lb.head->next;
	LNode *pc,*p;
	pc=head;
	while(pa!=La.head&&pb!=Lb.head){
		if(pa->data <= pb->data){
			p=new LNode;
			p->data=pa->data;
			pc->next=p;
			pc=p;
			pa=pa->next;
		}
		else{
			p=new LNode;
			p->data=pb->data;
			pc->next=p;
			pc=p;
			pb=pb->next;
		}
	}
	while(pa!=La.head){
		p=new LNode;
		p->data=pa->data;
		pc->next=p;
		pc=p;
		pa=pa->next;
	}
	while(pb!=Lb.head){
		p=new LNode;
		p->data=pb->data;
		pc->next=p;
		pc=p;
		pb=pb->next;
	}
	tail=pc;
	tail->next=head;
	len=La.len+Lb.len;
	La.ClearList_L();
	Lb.ClearList_L();
}

void Print(){
	if(len==0){
		cout<<"当前链表为空"<<endl;
	}
	else{
		cout<<"当前链表为：";
	    LNode *p=head;
	    for(int i=0;i<len;i++){
		    p=p->next;
		    cout<<p->data<<" ";
	    }
	    cout<<endl;
	}
}

void mainpp(){
	cout<<"\t1. 建立一个循环链表   2. 输出一个循环链表\n";
	cout<<"\t3. 销毁循环链表       4. 清空循环链表\n";
	cout<<"\t5. 按位置查找         6. 按值查找\n";
	cout<<"\t7. 按位置删除一个结点 8. 按位置插入一个结点\n";
	cout<<"\t9. 合并两个有序链表   10.返回链表长度\n";
	cout<<"\t0. 退出\n";
	cout<<"请输入0-10：";
}
};

class LinkList2
{
private:
    DuLNode *head;
	DuLNode *tail;
	int len;
public:
    //双向链表具体操作
	LinkList2(){head=new DuLNode;head->next=head;head->prior=head;len=0;}//构造函数

~LinkList2(){if(len)ClearList_L();head=tail=NULL;}//析构函数
	
int ClearList_L(){
	DuLNode *p,*q;
	p=head;
	if((p->next)==head)return OK;
	p=p->next;
	while(!p){
		q=p;
	    p=q->next;
		free(q);
	}
	tail=head;
	len=0;
	return OK;
}

int ListEmpty(){
	if(len==0) return NULL;
	else return OK;
}

void Create_L(int n){
	DuLNode *p,*q;
	q=head;
	for(int i=0;i<n;i++){
		p=new DuLNode;
		cin>>p->data;
		q->next=p;
		p->prior=q;
		q=p;
	}
	tail=q;
	tail->next=head;
	head->prior=tail;
	len=n;
}//尾插法建立长度为n的单链表

int GetLen(){return len;}

int GetElem_L(int i,ElemType &e){
	DuLNode *p;
	p=head->next;
	int j=1;
	while(p!=head&&j<i){
		p=p->next;++j;
	}
	if(p==head||j>i)return ERROR;
	e=p->data;
	return OK;
}

int ListInsert_L(int i,ElemType e){
	DuLNode *p;
	p=head->next;
	int j=0;
	if(i<1||i>len+1)return ERROR;
	while(j<i-1){
		p=p->next;
		++j;
	}
	DuLNode *s=new DuLNode;
	s->data=e;
	s->prior=p->prior;p->prior->next=s;
	s->next=p;p->prior=s;
	++len;
	if(i==len)tail=s;
	return OK;
}

int ListDelete_L(int i,ElemType &e){
	DuLNode *p;
	p=head->next;
	int j=0;
	if(i<1||i>len)return ERROR;
	while(j<i-1){
		p=p->next;
		++j;
	}
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	if(i==len)tail=p;
	free(p);
	--len;
	return OK;
}

int LocateElem_L(int e){
	DuLNode *p;
	p=head->next;
	int i = 1;
	while(i<=len&&p->data!=e){
		++i;
		p=p->next;
	}
	if(i<=len) return i;
	else return ERROR;
}

void MergeList_L(LinkList2 &La,LinkList2 &Lb){
	DuLNode *pa=La.head->next;
	DuLNode *pb=Lb.head->next;
	DuLNode *pc,*p;
	pc=head;
	while(pa!=La.head&&pb!=Lb.head){
		if(pa->data <= pb->data){
			p=new DuLNode;
			p->data=pa->data;
			pc->next=p;
			p->prior=pc;
			pc=p;
			pa=pa->next;
		}
		else{
			p=new DuLNode;
			p->data=pb->data;
			pc->next=p;
			p->prior=pc;
			pc=p;
			pb=pb->next;
		}
	}
	while(pa!=La.head){
		p=new DuLNode;
		p->data=pa->data;
		pc->next=p;
		p->prior=pc;
		pc=p;
		pa=pa->next;
	}
	while(pb!=Lb.head){
		p=new DuLNode;
		p->data=pb->data;
		pc->next=p;
		p->prior=pc;
		pc=p;
		pb=pb->next;
	}
	tail=pc;
	tail->next=head;
	len=La.len+Lb.len;
	La.ClearList_L();
	Lb.ClearList_L();
}

void Print(){
	if(len==0){
		cout<<"当前链表为空"<<endl;
	}
	else{
		cout<<"当前链表为：";
	    DuLNode *p=head;
	    for(int i=0;i<len;i++){
		    p=p->next;
		    cout<<p->data<<" ";
	    }
	    cout<<endl;
	}
}

void mainpp(){
	cout<<"\t1. 建立一个双向链表   2. 输出一个双向链表\n";
	cout<<"\t3. 销毁双向链表       4. 清空双向链表\n";
	cout<<"\t5. 按位置查找         6. 按值查找\n";
	cout<<"\t7. 按位置删除一个结点 8. 按位置插入一个结点\n";
	cout<<"\t9. 合并两个有序链表   10.返回链表长度\n";
	cout<<"\t0. 退出\n";
	cout<<"请输入0-10：";
}
};

int main(){
	int a;
	while(1){
		cout<<"请选择要测试的链表：\n1.单链表 2.循环链表 3.双链表 0.退出"<<endl;
	    cin>>a;
		if(a==0)break;
		else if(a==1){
			LinkList L,*p,L1,L2,L3;
			int input,e,i;
	        p=&L;
			while(1){
				p->mainpp();
				cin>>input;
				if(input==0)break;
				switch(input){
				case 1:
					int c;
				    cout<<"请选择建立方式：1.头插法 2.尾插法"<<endl;
				    cin>>c;
				    cout<<"请输入要建立的单链表的元素个数：";
				    int n;
				    cin>>n;
				    cout<<"请连续输入"<<n<<"个整数，以空格或回车间隔"<<endl;
				    if(c==1)p->Create_L(n);
				    else if(c==2)p->Create2_L(n);
				    else break;
				    p->Print();
					break;

			    case 2:
			    	p->Print();
			    	break;

			    case 3:
			    	p->~LinkList();
			    	L1.~LinkList();
			    	L2.~LinkList();
			    	L3.~LinkList();
			    	cout<<"所有链表已销毁"<<endl;
				    break;

			    case 4:
				    if(p->ListEmpty()==NULL){
				    	cout<<"当前链表为空"<<endl;
				    	break;
				    }
			    	p->ClearList_L();
			    	cout<<"链表已清空"<<endl;
				    break;

			    case 5:
			    	if(p->ListEmpty()==NULL){
				    	cout<<"当前链表为空"<<endl;
				    	break;
				    }
				    cout<<"请输入要查找元素位置：";
				    cin>>i;
				    if(p->GetElem_L(i,e)==OK){
					    cout<<"第"<<i<<"个元素为"<<e<<endl;
					    break;
				    }
				    else cout<<"输入位置不合法"<<endl;
				    break;

			    case 6:
				    if(p->ListEmpty()==NULL){
				    	cout<<"当前链表为空"<<endl;
				    	break;
			    	}
				    int e;
			        cout<<"请输入要查找的整数：";
			        cin>>e;
			    	i=p->LocateElem_L(e);
			        if(i== ERROR){
				        cout<<"未找到"<<e<<endl;
				        break;
			        }
			        cout<<e<<"是表中第"<<i<<"个元素"<<endl;
			        break;

			    case 7:
			    	if(p->ListEmpty()==NULL){
				    	cout<<"当前链表为空"<<endl;
				    	break;
				    }
				    cout<<"请输入要删除元素的位置："<<endl;
	    		    cin>>i;
		    		if(p->ListDelete_L(i,e)==OK){
			    		cout<<"你删除的元素是"<<e<<endl;
				    	p->Print();
				    }
				    else cout<<"输入的值不合法"<<endl;
				    break;

			    case 8:
				    if(p->ListEmpty()==NULL){
				    	cout<<"当前链表为空"<<endl;
				    	break;
				    }
				    cout<<"请输入插入元素的位置和整数值，以空格间隔：";
			        cin>>i>>e;
			    	if(p->ListInsert_L(i,e)==OK){
			    	cout<<"插入成功"<<endl;
			    	p->Print();
			    	}
			        else cout<<"输入的值不合法"<<endl;
			        break;

		    	case 9:
				    if(p->ListEmpty()==NULL){
				    	cout<<"当前链表为空"<<endl;
				    	break;
				    }
				    p->ReverseList_L();
				    p->Print();
			    	break;

			    case 10:
				    L3.ClearList_L();
				    int n1,n2;
				    cout<<"建立第1个有序表（尾插法）：请输入一组整数，第一个为元素个数："<<endl;
			        cin>>n1;
			    	L1.Create2_L(n1);
			    	cout<<"建立第2个有序表（尾插法）：请输入一组整数，第一个为元素个数："<<endl;
			    	cin>>n2;
			    	L2.Create2_L(n2);
			    	L3.MergeList_L(L1,L2);
			    	L3.Print();
				    break;

			    case 11:
			    	cout<<"当前链表长度为"<<p->GetLen()<<endl;
				    break;
				
			    default:
					break;
					}
					}
					}
        else if(a==2){
			int input,e,i;
			LinkList1 L_1,*q,La,Lb,Lc;
			q=&L_1;
    	    while(1){
	    	    q->mainpp();
	            cin>>input;
	    	    if(input==0)break;
	            switch(input){
			    case 1:
				cout<<"请输入要建立的单链表的元素个数：";
				int n;
				cin>>n;
				cout<<"请连续输入"<<n<<"个整数，以空格或回车间隔"<<endl;
				q->Create_L(n);
				q->Print();
				break;
				
			    case 2:
				q->Print();
				break;
			
                case 3:
				q->~LinkList1();
				La.~LinkList1();
				Lb.~LinkList1();
				Lc.~LinkList1();
				cout<<"所有链表已销毁"<<endl;
				break;

		    	case 4:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				q->ClearList_L();
				cout<<"链表已清空"<<endl;
				break;

			    case 5:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				cout<<"请输入要查找元素位置：";
				cin>>i;
				if(q->GetElem_L(i,e)==OK){
					cout<<"第"<<i<<"个元素为"<<e<<endl;
					break;
				}
				else cout<<"输入位置不合法"<<endl;
				break;

		    	case 6:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
			  	int e;
			    cout<<"请输入要查找的整数：";
			    cin>>e;
				i=q->LocateElem_L(e);
			    if(i== ERROR){
				    cout<<"未找到"<<e<<endl;
				    break;
			    }
			    cout<<e<<"是表中第"<<i<<"个元素"<<endl;
			    break;

			    case 7:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				cout<<"请输入要删除元素的位置："<<endl;
			    cin>>i;
				if(q->ListDelete_L(i,e)==OK){
					cout<<"你删除的元素是"<<e<<endl;
					q->Print();
				}
				else cout<<"输入的值不合法"<<endl;
				break;

			    case 8:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				cout<<"请输入插入元素的位置和整数值，以空格间隔：";
			    cin>>i>>e;
				if(q->ListInsert_L(i,e)==OK){
				cout<<"插入成功"<<endl;
				q->Print();
				}
			    else cout<<"输入的值不合法"<<endl;
			    break;
				
			    case 9:
				Lc.ClearList_L();
				int n1,n2;
				cout<<"建立第1个有序表：请输入一组整数，第一个为元素个数："<<endl;
			    cin>>n1;
				La.Create_L(n1);
				cout<<"建立第2个有序表：请输入一组整数，第一个为元素个数："<<endl;
				cin>>n2;
				Lb.Create_L(n2);
				Lc.MergeList_L(La,Lb);
				Lc.Print();
				break;

			    case 10:
				cout<<"当前链表长度为"<<q->GetLen()<<endl;
				break;
				
			default:
				break;
				}
				}
				}
    	if(a==3){
		    LinkList2 L_2,*q,LA,LB,LC;
			int input,e,i;
	        q=&L_2;
	        while(1){
		    q->mainpp();
	        cin>>input;
		    if(input==0)break;
	        switch(input){
			case 1:
				cout<<"请输入要建立的单链表的元素个数：";
				int n;
				cin>>n;
				cout<<"请连续输入"<<n<<"个整数，以空格或回车间隔"<<endl;
				q->Create_L(n);
				q->Print();
				break;
				
			case 2:
				q->Print();
				break;
			
            case 3:
				q->~LinkList2();
				LA.~LinkList2();
				LB.~LinkList2();
				LC.~LinkList2();
				cout<<"所有链表已销毁"<<endl;
				break;
			
			case 4:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				q->ClearList_L();
				cout<<"链表已清空"<<endl;
				break;

			case 5:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				cout<<"请输入要查找元素位置：";
				cin>>i;
				if(q->GetElem_L(i,e)==OK){
					cout<<"第"<<i<<"个元素为"<<e<<endl;
					break;
				}
				else cout<<"输入位置不合法"<<endl;
				break;

			case 6:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				int e;
			    cout<<"请输入要查找的整数：";
			    cin>>e;
				i=q->LocateElem_L(e);
			    if(i== ERROR){
				    cout<<"未找到"<<e<<endl;
				    break;
			    }
			    cout<<e<<"是表中第"<<i<<"个元素"<<endl;
			    break;

			case 7:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				cout<<"请输入要删除元素的位置："<<endl;
			    cin>>i;
				if(q->ListDelete_L(i,e)==OK){
					cout<<"你删除的元素是"<<e<<endl;
					q->Print();
				}
				else cout<<"输入的值不合法"<<endl;
				break;

			case 8:
				if(q->ListEmpty()==NULL){
					cout<<"当前链表为空"<<endl;
					break;
				}
				cout<<"请输入插入元素的位置和整数值，以空格间隔：";
			    cin>>i>>e;
				if(q->ListInsert_L(i,e)==OK){
				cout<<"插入成功"<<endl;
				q->Print();
				}
			    else cout<<"输入的值不合法"<<endl;
			    break;
				
			case 9:
				LC.ClearList_L();
				int n1,n2;
				cout<<"建立第1个有序表：请输入一组整数，第一个为元素个数："<<endl;
			    cin>>n1;
				LA.Create_L(n1);
				cout<<"建立第2个有序表：请输入一组整数，第一个为元素个数："<<endl;
				cin>>n2;
				LB.Create_L(n2);
				LC.MergeList_L(LA,LB);
				LC.Print();
				break;

			case 10:
				cout<<"当前链表长度为"<<q->GetLen()<<endl;
				break;

			default:
				break;
		}
		}
		}
		}
		return 0;
}
