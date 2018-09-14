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
	    cout<<"请输入顺序表长度："<<endl;
	    cin>>n;
	    cout<<"请按顺序输入"<<n<<"个元素"<<endl;
	    elem=array;
		length=n;
	    for(i=1;i<=n;i++){
	    	cin>>elem[i].key;
    	}
	}
	int Search_Bin(KeyType key){
//折半查找
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
	if(s==NULL){cout<<"存储分配失败"<<endl;exit(1);}
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
	cout<<"1.折半查找"<<endl;
	cout<<"2.二叉排序树的建立、查找和删除"<<endl;
	int input;
	cin>>input;
	if(input==1){
		SSTable ST;
		Elemtype a[N];
		ST.Create_SST(a);
    	int key;
    	cout<<"请输入要查找的关键字："<<endl;
    	cin>>key;
    	if(ST.Search_Bin(key))
    		cout<<key<<"的位置为："<<ST.Search_Bin(key)<<endl;
    	else
	    	cout<<"查找失败"<<endl;
	}
	else if(input==2){
		BSTree BT;
		Elemtype finish;
		cout<<"请输入终止值："<<endl;
		cin>>finish.key;
		cout<<"请输入序列，以"<<finish.key<<"结束"<<endl;
		CreateBST(BT,finish);
		cout<<"二叉排序树已建立"<<endl;
		InOrder(BT);cout<<endl;
		cout<<"请输入要查找的关键字："<<endl;
		KeyType key;
		cin>>key;
		if(!Insert(BT,key))
			cout<<"查找成功，不插入"<<endl;
		else cout<<"已插入"<<endl;
		InOrder(BT);cout<<endl;
		cout<<"请输入要删除的元素："<<endl;
		cin>>key;
		if(Remove(BT,key))
			cout<<"已删除"<<endl;
		else
			cout<<"查找失败，不作删除"<<endl;
		InOrder(BT);cout<<endl;
	}
	    return 0;
}
