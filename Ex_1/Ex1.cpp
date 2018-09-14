#include<iostream>
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ERROR -1
#define OK 0
typedef int ElemType;
class SqList{
public:
	SqList(){
		elem=new ElemType[LIST_INIT_SIZE];
		if(!elem)exit(1);
		length=0;
		listsize=LIST_INIT_SIZE;
	}
	~SqList(){}
	int SqList_Length(){
		return length;
	}
	int *get_elem(){return elem;}
	int SqList_Create(int n);
	int ListInsert_Sq(int i,ElemType e);
	int ListDelete_Sq(int i,ElemType &e);
	int LocateElem_Sq(ElemType e);
	int Delete_Sq(ElemType x);
	int DeleteAll_Sq(ElemType x);
	void MergeList_Sq(SqList L1, SqList L2);
	void OutputList_Sq();
	void ClearList_Sq();
private:
	ElemType *elem;
	int length;
	int listsize;
};
int SqList::SqList_Create(int n){
	int i,*p;
	p=elem;
	for(i=0; i<n; i++)cin>>*p++;
	length = n;
	return OK;
}//SqList_Create;

int SqList::ListInsert_Sq(int i,ElemType e){
	//i的合法值为1≤i≤Length+1
	int *newbase,*p,*q;
	if(i<1||i>length+1) return ERROR;   //i值不合法
	if(length >= listsize){
		newbase=new ElemType[LISTINCREMENT];
		if(!newbase)exit(1);
		elem=newbase;
		listsize+=LISTINCREMENT;
	}
	q = &(elem[i-1]);
	for(p = &(elem[length -1]);p >= q;--p) *(p+1) = *p;
	*q = e;
	++(length);
	return OK;   //成功插入元素，返回0
}//ListInsert_Sq;

int SqList::ListDelete_Sq(int i,ElemType &e){
	//i的合法值为1≤i≤Length
	int *p,*q;
	if((i<1)||(i>length)) return ERROR;   //i值不合法
	p = &(elem[i-1]);
	e = *p;
	q = elem+length-1;
	for(++p; p <= q; ++p) *(p-1) = *p;
	--(length);
	return OK;
}//ListDelete_Sq;

int SqList::LocateElem_Sq(ElemType e){
	//若找到，则返回其在L中的位序，否则返回ERROR
	int i = 1,*p;
	p = elem;
	while(i <= length&&*p++ != e) ++i;
	if(i <= length) return i;
	else return ERROR;
}//LocatElem_Sq;

void SqList::OutputList_Sq(){
	int i,*p;
	p = elem;
	if(length==0){
				cout<<"当前顺序表为空"<<endl;
	}
	else{
	    cout<<"当前顺序表内容为：";
	    for(i = 0; i < length; i++){
		    cout<<*p++<<" ";
	    }
	cout<<endl;
	}
}//OutputList_Sq;

void SqList::ClearList_Sq(){
	length=0;
	cout<<"已清空线性表"<<endl;
}

int SqList::Delete_Sq(ElemType x){
	int i,e;
	i = LocateElem_Sq(x);
	if(i==ERROR) return ERROR;
	if(ListDelete_Sq(i,e)==OK) return OK;
	return ERROR;
}

int SqList::DeleteAll_Sq(ElemType x){
	int i,e,q,*p;
	p=elem;
	for(i=1; i<=length; i++)
		if(*p++ == x){
			q=ListDelete_Sq(i,e);
			--i;
			--p;
		}
	if(q==OK&&e==x) return OK;
	else 
		return ERROR;
}

void mainpp(){
	cout<<"\t*   1.建立一个顺序表    *\n";
	cout<<"\t*   2.输出一个顺序表    *\n";
	cout<<"\t*   3.查找              *\n";
	cout<<"\t*   4.按位置插入一个元素*\n";
	cout<<"\t*   5.按位置删除一个元素*\n";
	cout<<"\t*   6.清空顺序表        *\n";
	cout<<"\t*   7.合并两个有序表    *\n";
	cout<<"\t*   8.按值删除某一个元素*\n";
	cout<<"\t*   9.删除所有x         *\n";
	cout<<"\t*   0.退出              *\n";
}

void SqList::MergeList_Sq(SqList L1, SqList L2){
	//已知顺序线性表L1和L2的元素按值非递减排列
	//归并L1和L2得到新的顺序线性表L3，L3的元素也按值非递减排列
	int *newbase;
	int *p1 = L1.get_elem();
	int *p2 = L2.get_elem();
	int *p3 = elem;
	length=L1.SqList_Length()+L2.SqList_Length();
	if(length >= listsize){
		newbase=new ElemType[LISTINCREMENT];
		if(!newbase)exit(1);
		elem=newbase;
		listsize+=LISTINCREMENT;
	}
	int *p1_last = p1 + L1.SqList_Length() - 1;
	int *p2_last = p2 + L2.SqList_Length() - 1;
	while(p1 <= p1_last&&p2 <= p2_last){
		if(*p1 <= *p2) *p3++ = *p1++;
		else *p3++ = *p2++;
	}
	while(p1 <= p1_last) *p3++ = *p1++;
	while(p2 <= p2_last) *p3++ = *p2++;
}//MergeList_Sq;

int main(){
	int input,n,i,e;
	SqList L,*p=&L;

	while(1){
		mainpp();
		cout<<"请输入0-9：   ";
		cin>>input;
		if(input==0)break;
		switch(input){

		case 1:{
			cout<<"请输入顺序表元素的个数"<<endl;
			cin>>n;
			cout<<"请连续输入"<<n<<"个整数，以空格或回车间隔"<<endl;
			if(p->SqList_Create(n)==OK)cout<<"已生成顺序表"<<endl;
			p->OutputList_Sq();
			   }
			   break;
		
		case 2:{
			if(p->SqList_Length()==0){
				cout<<"当前顺序表为空，请先建立顺序表"<<endl;
				break;
			}
			p->OutputList_Sq();
			}
			break;

		case 3:{
			if(p->SqList_Length()==0){
				cout<<"当前顺序表为空，请先建立顺序表"<<endl;
				break;
			}
			cout<<"请输入要查找的整数：";
			cin>>e;
			i=p->LocateElem_Sq(e);
			if(i== ERROR){
				cout<<"未找到"<<e<<endl;
				break;
			}
			cout<<e<<"是表中第"<<i<<"个元素"<<endl;
			   }
			   break;
			   
		case 4:{
			if(p->SqList_Length()==0){
				cout<<"当前顺序表为空，请先建立顺序表"<<endl;
				break;
			}
			cout<<"请输入插入元素的位置和整数值，以空格间隔：";
			cin>>i>>e;
			if(p->ListInsert_Sq(i,e) == OK){
				cout<<"插入成功"<<endl;
				p->OutputList_Sq();
			}
			else cout<<"输入的值不合法"<<endl;
			   }
			break;

		case 5:{
			if(p->SqList_Length()==0){
				cout<<"当前顺序表为空，请先建立顺序表"<<endl;
				break;
			}
			cout<<"请输入要删除元素的位置："<<endl;
			cin>>i;
			if(p->ListDelete_Sq(i,e) == OK){
				cout<<"你删除的元素是"<<e<<endl;
				p->OutputList_Sq();
			}
			else cout<<"输入的值不合法"<<endl;
			   }
			break;

		case 6:{
			p->ClearList_Sq();
			p->OutputList_Sq();
			   }
			break;

		case 7:{
		    //SqList L1,L2;
			SqList L1,L2,L3;
			cout<<"建立第1个有序表：请输入一组整数，第一个为元素个数："<<endl;
			int n1;
			cin>>n1;
			if(L1.SqList_Create(n1)==OK)cout<<"已生成第一个有序表"<<endl;
			L1.OutputList_Sq();
			cout<<"建立第2个有序表：请输入一组整数，第一个为元素个数："<<endl;
			int n2;
			cin>>n2;
			if(L2.SqList_Create(n2)==OK)cout<<"已生成第二个有序表";
			L2.OutputList_Sq();
			//SqList L3;
			L3.MergeList_Sq(L1,L2);
			L3.OutputList_Sq();
			   }
			   break;

		case 8:{
			if(p->SqList_Length()==0){
				cout<<"当前顺序表为空，请先建立顺序表"<<endl;
				break;
			}
			cout<<"请输入要删除的整数值：（只删除找到的第一个元素）"<<endl;
			cin>>e;
			if(L.Delete_Sq(e) == ERROR){
				cout<<"未找到"<<endl;
				break;
			}
			cout<<"已删除"<<endl;
			L.OutputList_Sq();
			   }
			break;

		case 9:{
			if(p->SqList_Length()==0){
				cout<<"当前顺序表为空，请先建立顺序表"<<endl;
				break;
			}
			cout<<"请输入要删除的整数值："<<endl;
			cin>>e;
			if(L.DeleteAll_Sq(e)==OK)
				L.OutputList_Sq();
			   }
			break;

		default:
			break;
		}
	}
	return 0;
}