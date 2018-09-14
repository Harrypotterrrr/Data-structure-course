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
		cout<<"当前队列为空"<<endl;
	else{
		cout<<"当前队列为：";
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
		cout<<"队列已满"<<endl;
		return ERROR;
	}
	base[rear]=e;
	rear=(rear+1)%MAXQSIZE;
	return OK;
}
int LinkQueue1::DeQueue(QElemType &e){
	if(front==rear){
		cout<<"队列为空"<<endl;
		return ERROR;
	}
	e=base[front];
	front=(front+1)%MAXQSIZE;
	return OK;
}
void LinkQueue1::display() const {
	if(rear==front)
		cout<<"队列为空"<<endl;
    else{
		int length=(rear-front+MAXQSIZE)%MAXQSIZE;
        cout<<"从队尾到队头：";
        while(length--){
            cout<<base[front+length]<<' ';
		}
        cout<<endl;
	}
}
void mainpp(){
	cout<<"\t*   1.建立一个队列 *\n";
	cout<<"\t*   2.遍历当前队列 *\n";
	cout<<"\t*   3.元素入队     *\n";
	cout<<"\t*   4.元素出队     *\n";
	cout<<"\t*   5.返回队列长度 *\n";
	cout<<"\t*   6.返回队头元素 *\n";
	cout<<"\t*   7.清空队列     *\n";
	cout<<"\t*   8.销毁队列     *\n";
	cout<<"\t*   0.退出         *\n";
	cout<<"请输入0-8：";
}
void mainpp1(){
	cout<<"\t*   1.建立一个队列 *\n";
	cout<<"\t*   2.遍历当前队列 *\n";
	cout<<"\t*   3.元素入队     *\n";
	cout<<"\t*   4.元素出队     *\n";
	cout<<"\t*   5.返回队列长度 *\n";
	cout<<"\t*   6.清空队列     *\n";
	cout<<"\t*   7.销毁队列     *\n";
	cout<<"\t*   0.退出         *\n";
	cout<<"请输入0-7：";
}
int main(){
	int a;
	cout<<"1.测试链队列"<<endl;
	cout<<"2.测试循环队列"<<endl;
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
				cout<<"请输入要入队元素的个数"<<endl;
			    cin>>n;
			    cout<<"请连续输入"<<n<<"个整数，以空格或回车间隔"<<endl;
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
				cout<<"请输入要入队的元素：";
				cin>>e;
				if((p->EnQueue(e))==OK)cout<<"入队成功"<<endl;
				p->display();
				break;
			case 4:
				if(p->QueueEmpty()){
					cout<<"当前队列为空"<<endl;
					break;
				}
				else{
					if((p->DeQueue(e))==OK){
						cout<<"元素"<<e<<"已出队"<<endl;
						p->display();
					}
				}
			    break;
			case 5:
				cout<<"当前队列长度为："<<p->QueueLength()<<endl;
				break;
			case 6:
				if(p->QueueEmpty()){
					cout<<"当前队列为空"<<endl;
					break;
				}
				else{
					if((p->GetHead(e))==OK)
					    cout<<"队头元素为："<<e<<endl;
				}
				break;
			case 7:
				if(p->QueueEmpty()){
					cout<<"当前队列为空"<<endl;
					break;
				}
				else{
					if((p->ClearQueue())==OK)
						cout<<"队列已清空"<<endl;
				}
				break;
			case 8:
				p->~LinkQueue();
				cout<<"队列已销毁"<<endl;
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
				cout<<"请输入要入队元素的个数"<<endl;
			    cin>>n;
			    cout<<"请连续输入"<<n<<"个整数，以空格或回车间隔"<<endl;
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
				cout<<"请输入要入队的元素：";
				cin>>e;
				if((p->EnQueue(e))==OK)cout<<"入队成功"<<endl;
				p->display();
				break;
			case 4:
				if(p->QueueEmpty()){
					cout<<"当前队列为空"<<endl;
					break;
				}
				else{
					if((p->DeQueue(e))==OK){
						cout<<"元素"<<e<<"已出队"<<endl;
						p->display();
					}
				}
			    break;
			case 5:
				cout<<"当前队列长度为："<<p->QueueLength()<<endl;
				break;
			case 6:
				if(p->QueueEmpty()){
					cout<<"当前队列为空"<<endl;
					break;
				}
				else{
					if((p->ClearQueue())==OK)
						cout<<"队列已清空"<<endl;
				}
				break;
			case 7:
				p->~LinkQueue1();
				cout<<"队列已销毁"<<endl;
				break;
			default:break;
			}
		}
	}
	return 0;
}