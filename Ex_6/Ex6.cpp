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
		if(StackEmpty())cout<<"当前栈为空"<<endl;
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
		cout<<e<<"的"<<d<<"进制形式为";
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
		cout<<"\t*   1.建立一个顺序栈 *\n";
	    cout<<"\t*   2.销毁顺序栈     *\n";
	    cout<<"\t*   3.清空顺序栈     *\n";
	    cout<<"\t*   4.入栈一个元素   *\n";
    	cout<<"\t*   5.出栈一个元素   *\n";
    	cout<<"\t*   6.返回栈的长度   *\n";
	    cout<<"\t*   7.返回栈顶元素   *\n";
	    cout<<"\t*   8.进制转换       *\n";
		cout<<"\t*   9.显示栈中元素   *\n";
	    cout<<"\t*   0.退出           *\n";	
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
		if(StackEmpty())cout<<"当前栈为空"<<endl;
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
		cout<<e<<"的"<<d<<"进制形式为";
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
		cout<<"\t*   1.建立一个链栈  *\n";
	    cout<<"\t*   2.销毁链栈      *\n";
	    cout<<"\t*   3.清空链栈      *\n";
	    cout<<"\t*   4.入栈一个元素  *\n";
    	cout<<"\t*   5.出栈一个元素  *\n";
    	cout<<"\t*   6.返回栈的长度  *\n";
	    cout<<"\t*   7.返回栈顶元素  *\n";
	    cout<<"\t*   8.进制转换      *\n";
		cout<<"\t*   9.显示栈中元素  *\n";
	    cout<<"\t*   0.退出          *\n";	
	}
private:
	LNode *top;
	LNode *base;
	int len;
};
int main(){
	SElemType e;
	cout<<"1.测试顺序栈  2.测试链栈"<<endl;
	cout<<"请输入1或2"<<endl;
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
				cout<<"请输入要入栈的元素个数"<<endl;
				cin>>n;
				cout<<"请按入栈顺序依次输入"<<n<<"个元素，以空格或回车间隔"<<endl;
				p->InitStack(n);
				p->Output();
				break;
			case 2:
				p->~SqStack();
				q->~SqStack();
				cout<<"顺序栈已销毁"<<endl;
				break;
			case 3:
				if(p->ClearStack()==OK)cout<<"当前栈已清空"<<endl;
				break;
			case 4:
				cout<<"请输入要入栈的元素"<<endl;
				cin>>e;
				if(p->Push(e)==OK)cout<<"入栈成功"<<endl;
				p->Output();
				break;
			case 5:
				if(p->StackEmpty()){
					cout<<"当前栈为空"<<endl;
					break;}
				if(p->Pop(e)==OK)cout<<"出栈成功"<<endl;
				cout<<"出栈元素为"<<e<<endl;
				p->Output();
				break;
			case 6:
				cout<<"当前栈的长度为"<<p->StackLength()<<endl;
				break;
			case 7:
				p->GetTop(e);
				cout<<"栈顶元素为"<<e<<endl;
				break;
			case 8:
				int d;
				cout<<"请输入一个十进制数和要转换的进制数"<<endl;
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
				cout<<"请输入要入栈的元素个数"<<endl;
				cin>>n;
				cout<<"请按入栈顺序依次输入"<<n<<"个元素，以空格或回车间隔"<<endl;
				p->InitStack(n);
				p->Output();
				break;
			case 2:
				p->~SqStack_();
				q->~SqStack_();
				cout<<"链栈已销毁"<<endl;
				break;
			case 3:
				if(p->ClearStack()==OK)cout<<"当前栈已清空"<<endl;
				break;
			case 4:
				cout<<"请输入要入栈的元素"<<endl;
				cin>>e;
				if(p->Push(e)==OK)cout<<"入栈成功"<<endl;
				p->Output();
				break;
			case 5:
				if(p->StackEmpty()){
					cout<<"当前栈为空"<<endl;
					break;}
				if(p->Pop(e)==OK)cout<<"出栈成功"<<endl;
				cout<<"出栈元素为"<<e<<endl;
				p->Output();
				break;
			case 6:
				cout<<"当前栈的长度为"<<p->StackLength()<<endl;
				break;
			case 7:
				p->GetTop(e);
				cout<<"栈顶元素为"<<e<<endl;
				break;
			case 8:
				int d;
				cout<<"请输入一个十进制数和要转换的进制数"<<endl;
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