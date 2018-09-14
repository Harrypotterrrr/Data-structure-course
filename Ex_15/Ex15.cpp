#include <iostream>
using namespace std;
#define N 50
typedef int KeyType;
typedef struct{
	int key;
}Elemtype;
class SSTable{
private:
     Elemtype *elem;
     int length;
public:
	void Create_SST(Elemtype array[]){
		int n,i;
	    cout<<"������˳����ȣ�"<<endl;
	    cin>>n;
	    cout<<"�밴˳������"<<n<<"��Ԫ��"<<endl;
	    elem=array;
		length=n;
	    for(i=1;i<=n;i++){
	    	cin>>elem[i].key;
    	}
	}
	int Search_Bin(KeyType key){
//�۰����
	    int low,high,mid;
        low=1;high=length;
        while(low<=high){
	    	mid=(low+high)/2;
			cout<<mid<<' '<<key<<' '<<elem[mid].key<<endl;
	    	if(key>elem[mid].key)
	    		low=mid+1;
	    	else if(key<elem[mid].key)
	    		high=mid-1;
	    	else return mid;
         }
     return 0;
    }
};

typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *lchild,*rchild;
}*BSTree;

BSTNode *Search(BSTree BT,KeyType x,BSTNode *&father){
	BSTNode *p=BT;father=NULL;
	while(p!=NULL&&p->data.key!=x){
		father=p;
		if(x<p->data.key)p=p->lchild;
		else p=p->rchild;
	}
	return p;
}
int Insert(BSTree &BT,KeyType x){
	BSTNode *s,*p,*f;
	p=Search(BT,x,f);
	if(p!=NULL)return 0;
	s=new BSTNode;
	if(s==NULL){cout<<"�洢����ʧ��"<<endl;exit(1);}
	s->data.key=x;s->lchild=s->rchild=NULL;
	if(f==NULL)BT=s;
	else if(x<f->data.key)
		f->lchild=s;
	else f->rchild=s;
	return 1;
}
void CreateBST(BSTree &BT,Elemtype finish){
	Elemtype x;BT=NULL;
	cin>>x.key;
	while(x.key!=finish.key){
		Insert(BT,x.key);cin>>x.key;
	}
}
int Remove(BSTree &BT,KeyType x){
	BSTNode *s,*p,*f;
	p=Search(BT,x,f);
	if(p==NULL)return 0;
	if(p->lchild!=NULL&&p->rchild!=NULL){
		s=p->lchild;
		while(s->rchild!=NULL){
			f=s;s=s->rchild;
		}
		p->data=s->data;p=s;
	}
	if(p->lchild!=NULL)
		s=p->lchild;
	else s=p->rchild;
	if(p==BT)BT=s;
	else{
		if(s->data.key<f->data.key)f->lchild=s;
	    else f->rchild=s;
	}
	delete p;
	return 1;
}
void InOrder(BSTNode *T){
	if(T!=NULL){
		InOrder(T->lchild);
		cout<<T->data.key<<' ';
		InOrder(T->rchild);
	}
};

int main(){
	cout<<"1.�۰����"<<endl;
	cout<<"2.�����������Ľ��������Һ�ɾ��"<<endl;
	int input;
	cin>>input;
	if(input==1){
		SSTable ST;
		Elemtype a[N];
		ST.Create_SST(a);
    	int key;
    	cout<<"������Ҫ���ҵĹؼ��֣�"<<endl;
    	cin>>key;
    	if(ST.Search_Bin(key))
    		cout<<key<<"��λ��Ϊ��"<<ST.Search_Bin(key)<<endl;
    	else
	    	cout<<"����ʧ��"<<endl;
	}
	else if(input==2){
		BSTree BT;
		Elemtype finish;
		cout<<"��������ֵֹ��"<<endl;
		cin>>finish.key;
		cout<<"���������У���"<<finish.key<<"����"<<endl;
		CreateBST(BT,finish);
		cout<<"�����������ѽ���"<<endl;
		InOrder(BT);cout<<endl;
		cout<<"������Ҫ���ҵĹؼ��֣�"<<endl;
		KeyType key;
		cin>>key;
		if(!Insert(BT,key))
			cout<<"���ҳɹ���������"<<endl;
		else cout<<"�Ѳ���"<<endl;
		InOrder(BT);cout<<endl;
		cout<<"������Ҫɾ����Ԫ�أ�"<<endl;
		cin>>key;
		if(Remove(BT,key))
			cout<<"��ɾ��"<<endl;
		else
			cout<<"����ʧ�ܣ�����ɾ��"<<endl;
		InOrder(BT);cout<<endl;
	}
	    return 0;
}
