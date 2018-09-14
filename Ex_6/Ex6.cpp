#include <iostream>
using namespace std;
typedef int SElemType;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR -1
#define OK 1
class SqStack{
public:
	SqStack(){
		base=new SElemType[STACK_INIT_SIZE];
		top=base;
		stacksize=STACK_INIT_SIZE;
	}
	~SqStack(){ClearStack();}
	int ClearStack(){
		top=base;
		return OK;
	}
	int GetTop(SElemType &e){
		if(top==base)return ERROR;
		e=*(top-1);
		return OK;
	}
	int Push(SElemType e){
		if(top-base>=stacksize){
			base=new SElemType[STACKINCREMENT];
		    if(!base)exit(1);
		    top=base+stacksize;
		    stacksize+=STACKINCREMENT;
		}
		*top++=e;
		return OK;
	}
	int Pop(SElemType &e){
		if(top==base)return ERROR;
		e=*--top;
		return OK;
	}
	bool StackEmpty(){
		if(top==base)return 1;
		else return 0;
	}
	int StackLength(){
		int len=top-base;
		return len;
	}
	int InitStack(int n){
		SElemType e;
		for(int i=0;i<n;i++){
			cin>>e;
			if(Push(e)==ERROR)return ERROR;
		}
		return OK;
	}
	void Output(){
		SElemType e,*p=top;
		if(StackEmpty())cout<<"��ǰջΪ��"<<endl;
		else{
			while(p!=base){
				e=*--p;
				cout<<e<<' ';
			}
			cout<<endl;
		}
	}
	void Conversion(int d,SElemType e){
		char a;
		cout<<e<<"��"<<d<<"������ʽΪ";
		while(e){
			Push(e%d);
			e=e/d;
		}
		while(!StackEmpty()){
			Pop(e);
			if(e>9){a='A'+e-10;cout<<a;}
			else cout<<e;
		}
		cout<<endl;
	}
	void mainpp(){
		cout<<"\t*   1.����һ��˳��ջ *\n";
	    cout<<"\t*   2.����˳��ջ     *\n";
	    cout<<"\t*   3.���˳��ջ     *\n";
	    cout<<"\t*   4.��ջһ��Ԫ��   *\n";
    	cout<<"\t*   5.��ջһ��Ԫ��   *\n";
    	cout<<"\t*   6.����ջ�ĳ���   *\n";
	    cout<<"\t*   7.����ջ��Ԫ��   *\n";
	    cout<<"\t*   8.����ת��       *\n";
		cout<<"\t*   9.��ʾջ��Ԫ��   *\n";
	    cout<<"\t*   0.�˳�           *\n";	
	}
private:
	SElemType *base;
	SElemType *top;
	int stacksize;
};
struct LNode{
	SElemType data;
	LNode *next;
};
class SqStack_{
public:
	SqStack_(){
		base=new LNode;
		base->next=NULL;
		top=base;
		len=0;
	}
	~SqStack_(){ClearStack();base=NULL;}
	int ClearStack(){
        LNode *p=top;
		while(len){
			top=p->next;
			delete p;
			--len;
			p=top;
		}
		return OK;
	}
	int GetTop(SElemType &e){
		if(top==base)return ERROR;
		e=top->data;
		return OK;
	}
	int Push(SElemType e){
		LNode *p;
		p=new LNode;
		p->data=e;
		p->next=top;
		top=p;
		++len;
		return OK;
	}
	int Pop(SElemType &e){
		if(top==base)return ERROR;
		e=top->data;
		top=top->next;
		--len;
		return OK;
	}
	bool StackEmpty(){
		if(top==base)return 1;
		else return 0;
	}
	int StackLength(){
		return len;
	}
	int InitStack(int n){
		SElemType e;
		for(int i=0;i<n;i++){
			cin>>e;
			if(Push(e)==ERROR)return ERROR;
		}
		return OK;
	}
	void Output(){
		SElemType e;
		LNode *p=top;
		if(StackEmpty())cout<<"��ǰջΪ��"<<endl;
		else{
			while(p!=base){
				e=p->data;
				p=p->next;
				cout<<e<<' ';
			}
			cout<<endl;
		}
	}
	void Conversion(int d,SElemType e){
		char a;
		cout<<e<<"��"<<d<<"������ʽΪ";
		while(e){
			Push(e%d);
			e=e/d;
		}
		while(!StackEmpty()){
			Pop(e);
			if(e>9){a='A'+e-10;cout<<a;}
			else cout<<e;
		}
		cout<<endl;
	}
	void mainpp(){
		cout<<"\t*   1.����һ����ջ  *\n";
	    cout<<"\t*   2.������ջ      *\n";
	    cout<<"\t*   3.�����ջ      *\n";
	    cout<<"\t*   4.��ջһ��Ԫ��  *\n";
    	cout<<"\t*   5.��ջһ��Ԫ��  *\n";
    	cout<<"\t*   6.����ջ�ĳ���  *\n";
	    cout<<"\t*   7.����ջ��Ԫ��  *\n";
	    cout<<"\t*   8.����ת��      *\n";
		cout<<"\t*   9.��ʾջ��Ԫ��  *\n";
	    cout<<"\t*   0.�˳�          *\n";	
	}
private:
	LNode *top;
	LNode *base;
	int len;
};
int main(){
	SElemType e;
	cout<<"1.����˳��ջ  2.������ջ"<<endl;
	cout<<"������1��2"<<endl;
	int a;cin>>a;
	if(a==1){
		SqStack S,*p;p=&S;
		SqStack S1,*q;q=&S1;
		int input,n;
		while(1){
			p->mainpp();
			cin>>input;
			if(input==0)break;
			switch(input){
			case 1:
				cout<<"������Ҫ��ջ��Ԫ�ظ���"<<endl;
				cin>>n;
				cout<<"�밴��ջ˳����������"<<n<<"��Ԫ�أ��Կո��س����"<<endl;
				p->InitStack(n);
				p->Output();
				break;
			case 2:
				p->~SqStack();
				q->~SqStack();
				cout<<"˳��ջ������"<<endl;
				break;
			case 3:
				if(p->ClearStack()==OK)cout<<"��ǰջ�����"<<endl;
				break;
			case 4:
				cout<<"������Ҫ��ջ��Ԫ��"<<endl;
				cin>>e;
				if(p->Push(e)==OK)cout<<"��ջ�ɹ�"<<endl;
				p->Output();
				break;
			case 5:
				if(p->StackEmpty()){
					cout<<"��ǰջΪ��"<<endl;
					break;}
				if(p->Pop(e)==OK)cout<<"��ջ�ɹ�"<<endl;
				cout<<"��ջԪ��Ϊ"<<e<<endl;
				p->Output();
				break;
			case 6:
				cout<<"��ǰջ�ĳ���Ϊ"<<p->StackLength()<<endl;
				break;
			case 7:
				p->GetTop(e);
				cout<<"ջ��Ԫ��Ϊ"<<e<<endl;
				break;
			case 8:
				int d;
				cout<<"������һ��ʮ��������Ҫת���Ľ�����"<<endl;
				cin>>e>>d;
				q->Conversion(d,e);
				break;
			case 9:
				p->Output();
				break;
			default:break;
			}
		}
	}
	if(a==2){
		SqStack_ S,*p;p=&S;
		SqStack_ S1,*q;q=&S1;
		int input,n;
		while(1){
			p->mainpp();
			cin>>input;
			if(input==0)break;
			switch(input){
			case 1:
				cout<<"������Ҫ��ջ��Ԫ�ظ���"<<endl;
				cin>>n;
				cout<<"�밴��ջ˳����������"<<n<<"��Ԫ�أ��Կո��س����"<<endl;
				p->InitStack(n);
				p->Output();
				break;
			case 2:
				p->~SqStack_();
				q->~SqStack_();
				cout<<"��ջ������"<<endl;
				break;
			case 3:
				if(p->ClearStack()==OK)cout<<"��ǰջ�����"<<endl;
				break;
			case 4:
				cout<<"������Ҫ��ջ��Ԫ��"<<endl;
				cin>>e;
				if(p->Push(e)==OK)cout<<"��ջ�ɹ�"<<endl;
				p->Output();
				break;
			case 5:
				if(p->StackEmpty()){
					cout<<"��ǰջΪ��"<<endl;
					break;}
				if(p->Pop(e)==OK)cout<<"��ջ�ɹ�"<<endl;
				cout<<"��ջԪ��Ϊ"<<e<<endl;
				p->Output();
				break;
			case 6:
				cout<<"��ǰջ�ĳ���Ϊ"<<p->StackLength()<<endl;
				break;
			case 7:
				p->GetTop(e);
				cout<<"ջ��Ԫ��Ϊ"<<e<<endl;
				break;
			case 8:
				int d;
				cout<<"������һ��ʮ��������Ҫת���Ľ�����"<<endl;
				cin>>e>>d;
				q->Conversion(d,e);
				break;
			case 9:
				p->Output();
				break;
			default:break;
			}
		}
	}
	return 1;
}