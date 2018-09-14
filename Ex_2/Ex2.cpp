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
    //������������
LinkList(){head=new LNode;head->next=NULL;tail=head;len=0;}//���캯��

~LinkList(){if(len)ClearList_L();head=tail=NULL;}//��������
	
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
}//ͷ�巨��������Ϊn�ĵ�����

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
}//β�巨��������Ϊn�ĵ�����

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
		cout<<"��ǰ����Ϊ��"<<endl;
	}
	else{
		cout<<"��ǰ����Ϊ��";
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
	cout<<"\t1. ����һ��������     2. ���һ��������\n";
	cout<<"\t3. ���ٵ�����         4. ��յ�����\n";
	cout<<"\t5. ��λ�ò���         6. ��ֵ����\n";
	cout<<"\t7. ��λ��ɾ��һ����� 8. ��λ�ò���һ�����\n";
	cout<<"\t9. ���õ�����         10.�ϲ�������������\n";
	cout<<"\t11.����������       0. �˳�\n";
	cout<<"������0-11��";
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
    //������������
LinkList1(){head=new LNode;head->next=NULL;tail=head;tail->next=head;len=0;}//���캯��

~LinkList1(){if(len)ClearList_L();head=tail=NULL;}//��������

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
}//β�巨��������Ϊn�ĵ�����

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
		cout<<"��ǰ����Ϊ��"<<endl;
	}
	else{
		cout<<"��ǰ����Ϊ��";
	    LNode *p=head;
	    for(int i=0;i<len;i++){
		    p=p->next;
		    cout<<p->data<<" ";
	    }
	    cout<<endl;
	}
}

void mainpp(){
	cout<<"\t1. ����һ��ѭ������   2. ���һ��ѭ������\n";
	cout<<"\t3. ����ѭ������       4. ���ѭ������\n";
	cout<<"\t5. ��λ�ò���         6. ��ֵ����\n";
	cout<<"\t7. ��λ��ɾ��һ����� 8. ��λ�ò���һ�����\n";
	cout<<"\t9. �ϲ�������������   10.����������\n";
	cout<<"\t0. �˳�\n";
	cout<<"������0-10��";
}
};

class LinkList2
{
private:
    DuLNode *head;
	DuLNode *tail;
	int len;
public:
    //˫������������
	LinkList2(){head=new DuLNode;head->next=head;head->prior=head;len=0;}//���캯��

~LinkList2(){if(len)ClearList_L();head=tail=NULL;}//��������
	
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
}//β�巨��������Ϊn�ĵ�����

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
		cout<<"��ǰ����Ϊ��"<<endl;
	}
	else{
		cout<<"��ǰ����Ϊ��";
	    DuLNode *p=head;
	    for(int i=0;i<len;i++){
		    p=p->next;
		    cout<<p->data<<" ";
	    }
	    cout<<endl;
	}
}

void mainpp(){
	cout<<"\t1. ����һ��˫������   2. ���һ��˫������\n";
	cout<<"\t3. ����˫������       4. ���˫������\n";
	cout<<"\t5. ��λ�ò���         6. ��ֵ����\n";
	cout<<"\t7. ��λ��ɾ��һ����� 8. ��λ�ò���һ�����\n";
	cout<<"\t9. �ϲ�������������   10.����������\n";
	cout<<"\t0. �˳�\n";
	cout<<"������0-10��";
}
};

int main(){
	int a;
	while(1){
		cout<<"��ѡ��Ҫ���Ե�����\n1.������ 2.ѭ������ 3.˫���� 0.�˳�"<<endl;
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
				    cout<<"��ѡ������ʽ��1.ͷ�巨 2.β�巨"<<endl;
				    cin>>c;
				    cout<<"������Ҫ�����ĵ������Ԫ�ظ�����";
				    int n;
				    cin>>n;
				    cout<<"����������"<<n<<"���������Կո��س����"<<endl;
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
			    	cout<<"��������������"<<endl;
				    break;

			    case 4:
				    if(p->ListEmpty()==NULL){
				    	cout<<"��ǰ����Ϊ��"<<endl;
				    	break;
				    }
			    	p->ClearList_L();
			    	cout<<"���������"<<endl;
				    break;

			    case 5:
			    	if(p->ListEmpty()==NULL){
				    	cout<<"��ǰ����Ϊ��"<<endl;
				    	break;
				    }
				    cout<<"������Ҫ����Ԫ��λ�ã�";
				    cin>>i;
				    if(p->GetElem_L(i,e)==OK){
					    cout<<"��"<<i<<"��Ԫ��Ϊ"<<e<<endl;
					    break;
				    }
				    else cout<<"����λ�ò��Ϸ�"<<endl;
				    break;

			    case 6:
				    if(p->ListEmpty()==NULL){
				    	cout<<"��ǰ����Ϊ��"<<endl;
				    	break;
			    	}
				    int e;
			        cout<<"������Ҫ���ҵ�������";
			        cin>>e;
			    	i=p->LocateElem_L(e);
			        if(i== ERROR){
				        cout<<"δ�ҵ�"<<e<<endl;
				        break;
			        }
			        cout<<e<<"�Ǳ��е�"<<i<<"��Ԫ��"<<endl;
			        break;

			    case 7:
			    	if(p->ListEmpty()==NULL){
				    	cout<<"��ǰ����Ϊ��"<<endl;
				    	break;
				    }
				    cout<<"������Ҫɾ��Ԫ�ص�λ�ã�"<<endl;
	    		    cin>>i;
		    		if(p->ListDelete_L(i,e)==OK){
			    		cout<<"��ɾ����Ԫ����"<<e<<endl;
				    	p->Print();
				    }
				    else cout<<"�����ֵ���Ϸ�"<<endl;
				    break;

			    case 8:
				    if(p->ListEmpty()==NULL){
				    	cout<<"��ǰ����Ϊ��"<<endl;
				    	break;
				    }
				    cout<<"���������Ԫ�ص�λ�ú�����ֵ���Կո�����";
			        cin>>i>>e;
			    	if(p->ListInsert_L(i,e)==OK){
			    	cout<<"����ɹ�"<<endl;
			    	p->Print();
			    	}
			        else cout<<"�����ֵ���Ϸ�"<<endl;
			        break;

		    	case 9:
				    if(p->ListEmpty()==NULL){
				    	cout<<"��ǰ����Ϊ��"<<endl;
				    	break;
				    }
				    p->ReverseList_L();
				    p->Print();
			    	break;

			    case 10:
				    L3.ClearList_L();
				    int n1,n2;
				    cout<<"������1�������β�巨����������һ����������һ��ΪԪ�ظ�����"<<endl;
			        cin>>n1;
			    	L1.Create2_L(n1);
			    	cout<<"������2�������β�巨����������һ����������һ��ΪԪ�ظ�����"<<endl;
			    	cin>>n2;
			    	L2.Create2_L(n2);
			    	L3.MergeList_L(L1,L2);
			    	L3.Print();
				    break;

			    case 11:
			    	cout<<"��ǰ������Ϊ"<<p->GetLen()<<endl;
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
				cout<<"������Ҫ�����ĵ������Ԫ�ظ�����";
				int n;
				cin>>n;
				cout<<"����������"<<n<<"���������Կո��س����"<<endl;
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
				cout<<"��������������"<<endl;
				break;

		    	case 4:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				q->ClearList_L();
				cout<<"���������"<<endl;
				break;

			    case 5:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				cout<<"������Ҫ����Ԫ��λ�ã�";
				cin>>i;
				if(q->GetElem_L(i,e)==OK){
					cout<<"��"<<i<<"��Ԫ��Ϊ"<<e<<endl;
					break;
				}
				else cout<<"����λ�ò��Ϸ�"<<endl;
				break;

		    	case 6:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
			  	int e;
			    cout<<"������Ҫ���ҵ�������";
			    cin>>e;
				i=q->LocateElem_L(e);
			    if(i== ERROR){
				    cout<<"δ�ҵ�"<<e<<endl;
				    break;
			    }
			    cout<<e<<"�Ǳ��е�"<<i<<"��Ԫ��"<<endl;
			    break;

			    case 7:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				cout<<"������Ҫɾ��Ԫ�ص�λ�ã�"<<endl;
			    cin>>i;
				if(q->ListDelete_L(i,e)==OK){
					cout<<"��ɾ����Ԫ����"<<e<<endl;
					q->Print();
				}
				else cout<<"�����ֵ���Ϸ�"<<endl;
				break;

			    case 8:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				cout<<"���������Ԫ�ص�λ�ú�����ֵ���Կո�����";
			    cin>>i>>e;
				if(q->ListInsert_L(i,e)==OK){
				cout<<"����ɹ�"<<endl;
				q->Print();
				}
			    else cout<<"�����ֵ���Ϸ�"<<endl;
			    break;
				
			    case 9:
				Lc.ClearList_L();
				int n1,n2;
				cout<<"������1�������������һ����������һ��ΪԪ�ظ�����"<<endl;
			    cin>>n1;
				La.Create_L(n1);
				cout<<"������2�������������һ����������һ��ΪԪ�ظ�����"<<endl;
				cin>>n2;
				Lb.Create_L(n2);
				Lc.MergeList_L(La,Lb);
				Lc.Print();
				break;

			    case 10:
				cout<<"��ǰ������Ϊ"<<q->GetLen()<<endl;
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
				cout<<"������Ҫ�����ĵ������Ԫ�ظ�����";
				int n;
				cin>>n;
				cout<<"����������"<<n<<"���������Կո��س����"<<endl;
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
				cout<<"��������������"<<endl;
				break;
			
			case 4:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				q->ClearList_L();
				cout<<"���������"<<endl;
				break;

			case 5:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				cout<<"������Ҫ����Ԫ��λ�ã�";
				cin>>i;
				if(q->GetElem_L(i,e)==OK){
					cout<<"��"<<i<<"��Ԫ��Ϊ"<<e<<endl;
					break;
				}
				else cout<<"����λ�ò��Ϸ�"<<endl;
				break;

			case 6:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				int e;
			    cout<<"������Ҫ���ҵ�������";
			    cin>>e;
				i=q->LocateElem_L(e);
			    if(i== ERROR){
				    cout<<"δ�ҵ�"<<e<<endl;
				    break;
			    }
			    cout<<e<<"�Ǳ��е�"<<i<<"��Ԫ��"<<endl;
			    break;

			case 7:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				cout<<"������Ҫɾ��Ԫ�ص�λ�ã�"<<endl;
			    cin>>i;
				if(q->ListDelete_L(i,e)==OK){
					cout<<"��ɾ����Ԫ����"<<e<<endl;
					q->Print();
				}
				else cout<<"�����ֵ���Ϸ�"<<endl;
				break;

			case 8:
				if(q->ListEmpty()==NULL){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				cout<<"���������Ԫ�ص�λ�ú�����ֵ���Կո�����";
			    cin>>i>>e;
				if(q->ListInsert_L(i,e)==OK){
				cout<<"����ɹ�"<<endl;
				q->Print();
				}
			    else cout<<"�����ֵ���Ϸ�"<<endl;
			    break;
				
			case 9:
				LC.ClearList_L();
				int n1,n2;
				cout<<"������1�������������һ����������һ��ΪԪ�ظ�����"<<endl;
			    cin>>n1;
				LA.Create_L(n1);
				cout<<"������2�������������һ����������һ��ΪԪ�ظ�����"<<endl;
				cin>>n2;
				LB.Create_L(n2);
				LC.MergeList_L(LA,LB);
				LC.Print();
				break;

			case 10:
				cout<<"��ǰ������Ϊ"<<q->GetLen()<<endl;
				break;

			default:
				break;
		}
		}
		}
		}
		return 0;
}
