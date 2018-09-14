#include <iostream>
using namespace std;
typedef int QElemType;
#define MAXQSIZE 100
#define OK 1
#define ERROR -1
struct QNode{
	QElemType data;
	QNode *next;
};
class LinkQueue{
public:
	LinkQueue(){
		front=rear=new QNode;
		front->next=NULL;
	}
	~LinkQueue(){
		while(front){
			rear=front->next;
			free(front);
			front=rear;
		}
	}
	int ClearQueue(){
		QElemType e;
		while(!QueueEmpty())
			DeQueue(e);
		return OK;
	}
	bool QueueEmpty(){
		if(front==rear)return 1;
		else return 0;
	}
	int QueueLength(){
		int length=0;
		QNode *p=front;
		while(p->next){
			++length;
			p=p->next;
		}
		return length;
	}
	int GetHead(QElemType &e);
	int EnQueue(QElemType e);
	int DeQueue(QElemType &e);
	void display();
private:
	QNode *front;
	QNode *rear;
};
int LinkQueue::GetHead(QElemType &e){
	if(QueueEmpty())return ERROR;
	else e=front->next->data;
	return OK;
}
int LinkQueue::EnQueue(QElemType e){
	QNode *p;
	p=new QNode;
	if(!p)return ERROR;
	p->data=e;p->next=NULL;
	rear->next=p;
	rear=p;
	return OK;
}
int LinkQueue::DeQueue(QElemType &e){
	if(QueueEmpty())return ERROR;
	QNode *p=front->next;
	e=p->data;
	front->next=p->next;
	if(rear==p)rear=front;
	free(p);
	return OK;
}
void LinkQueue::display(){
	if(QueueEmpty())
		cout<<"��ǰ����Ϊ��"<<endl;
	else{
		cout<<"��ǰ����Ϊ��";
		QNode *p=front->next;
		while(p){
			cout<<p->data<<' ';
			p=p->next;
		}
		cout<<endl;
	}
}
class LinkQueue1{
public:
	LinkQueue1(){
		base=new QElemType[MAXQSIZE];
		if(!base)exit(1);
		front=rear=0;}
	~LinkQueue1(){rear=front=0;}
	int ClearQueue(){
		QElemType e;
		while(!QueueEmpty())
			DeQueue(e);
		return OK;
	}
	int QueueLength(){
		return (rear-front+MAXQSIZE)%MAXQSIZE;}
	bool QueueFull(){
		if((rear+1)%MAXQSIZE==front)
			return 1;
		else return 0;
	}
	bool QueueEmpty(){
		if(rear==front)return 1;
		else return 0;
	}
	int EnQueue(QElemType e);
	int DeQueue(QElemType &e);
	void display()const;
private:
	QElemType *base;
	int front;
	int rear;
};
int LinkQueue1::EnQueue(QElemType e){
	if((rear+1)%MAXQSIZE==front){
		cout<<"��������"<<endl;
		return ERROR;
	}
	base[rear]=e;
	rear=(rear+1)%MAXQSIZE;
	return OK;
}
int LinkQueue1::DeQueue(QElemType &e){
	if(front==rear){
		cout<<"����Ϊ��"<<endl;
		return ERROR;
	}
	e=base[front];
	front=(front+1)%MAXQSIZE;
	return OK;
}
void LinkQueue1::display() const {
	if(rear==front)
		cout<<"����Ϊ��"<<endl;
    else{
		int length=(rear-front+MAXQSIZE)%MAXQSIZE;
        cout<<"�Ӷ�β����ͷ��";
        while(length--){
            cout<<base[front+length]<<' ';
		}
        cout<<endl;
	}
}
void mainpp(){
	cout<<"\t*   1.����һ������ *\n";
	cout<<"\t*   2.������ǰ���� *\n";
	cout<<"\t*   3.Ԫ�����     *\n";
	cout<<"\t*   4.Ԫ�س���     *\n";
	cout<<"\t*   5.���ض��г��� *\n";
	cout<<"\t*   6.���ض�ͷԪ�� *\n";
	cout<<"\t*   7.��ն���     *\n";
	cout<<"\t*   8.���ٶ���     *\n";
	cout<<"\t*   0.�˳�         *\n";
	cout<<"������0-8��";
}
void mainpp1(){
	cout<<"\t*   1.����һ������ *\n";
	cout<<"\t*   2.������ǰ���� *\n";
	cout<<"\t*   3.Ԫ�����     *\n";
	cout<<"\t*   4.Ԫ�س���     *\n";
	cout<<"\t*   5.���ض��г��� *\n";
	cout<<"\t*   6.��ն���     *\n";
	cout<<"\t*   7.���ٶ���     *\n";
	cout<<"\t*   0.�˳�         *\n";
	cout<<"������0-7��";
}
int main(){
	int a;
	cout<<"1.����������"<<endl;
	cout<<"2.����ѭ������"<<endl;
	cin>>a;
	if(a==1){
		LinkQueue Q,*p;
		p=&Q;
		int input,n,e;
		while(1){
			mainpp();
			cin>>input;
			if(input==0)break;
			switch(input){
			case 1:
				cout<<"������Ҫ���Ԫ�صĸ���"<<endl;
			    cin>>n;
			    cout<<"����������"<<n<<"���������Կո��س����"<<endl;
			    for(int i=0;i<n;i++){
					cin>>e;
					if((p->EnQueue(e))==ERROR)break;
				}
				p->display();
			    break;
			case 2:
				p->display();
				break;
			case 3:
				cout<<"������Ҫ��ӵ�Ԫ�أ�";
				cin>>e;
				if((p->EnQueue(e))==OK)cout<<"��ӳɹ�"<<endl;
				p->display();
				break;
			case 4:
				if(p->QueueEmpty()){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				else{
					if((p->DeQueue(e))==OK){
						cout<<"Ԫ��"<<e<<"�ѳ���"<<endl;
						p->display();
					}
				}
			    break;
			case 5:
				cout<<"��ǰ���г���Ϊ��"<<p->QueueLength()<<endl;
				break;
			case 6:
				if(p->QueueEmpty()){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				else{
					if((p->GetHead(e))==OK)
					    cout<<"��ͷԪ��Ϊ��"<<e<<endl;
				}
				break;
			case 7:
				if(p->QueueEmpty()){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				else{
					if((p->ClearQueue())==OK)
						cout<<"���������"<<endl;
				}
				break;
			case 8:
				p->~LinkQueue();
				cout<<"����������"<<endl;
				break;
			default:break;
			}
		}
	}
	if(a==2){
		LinkQueue1 Q,*p;
		p=&Q;
		int input,n,e;
		while(1){
			mainpp1();
			cin>>input;
			if(input==0)break;
			switch(input){
			case 1:
				cout<<"������Ҫ���Ԫ�صĸ���"<<endl;
			    cin>>n;
			    cout<<"����������"<<n<<"���������Կո��س����"<<endl;
			    for(int i=0;i<n;i++){
					cin>>e;
					if((p->EnQueue(e))==ERROR)break;
				}
				p->display();
			    break;
			case 2:
				p->display();
				break;
			case 3:
				cout<<"������Ҫ��ӵ�Ԫ�أ�";
				cin>>e;
				if((p->EnQueue(e))==OK)cout<<"��ӳɹ�"<<endl;
				p->display();
				break;
			case 4:
				if(p->QueueEmpty()){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				else{
					if((p->DeQueue(e))==OK){
						cout<<"Ԫ��"<<e<<"�ѳ���"<<endl;
						p->display();
					}
				}
			    break;
			case 5:
				cout<<"��ǰ���г���Ϊ��"<<p->QueueLength()<<endl;
				break;
			case 6:
				if(p->QueueEmpty()){
					cout<<"��ǰ����Ϊ��"<<endl;
					break;
				}
				else{
					if((p->ClearQueue())==OK)
						cout<<"���������"<<endl;
				}
				break;
			case 7:
				p->~LinkQueue1();
				cout<<"����������"<<endl;
				break;
			default:break;
			}
		}
	}
	return 0;
}