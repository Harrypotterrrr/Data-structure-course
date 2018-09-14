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
	//i�ĺϷ�ֵΪ1��i��Length+1
	int *newbase,*p,*q;
	if(i<1||i>length+1) return ERROR;   //iֵ���Ϸ�
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
	return OK;   //�ɹ�����Ԫ�أ�����0
}//ListInsert_Sq;

int SqList::ListDelete_Sq(int i,ElemType &e){
	//i�ĺϷ�ֵΪ1��i��Length
	int *p,*q;
	if((i<1)||(i>length)) return ERROR;   //iֵ���Ϸ�
	p = &(elem[i-1]);
	e = *p;
	q = elem+length-1;
	for(++p; p <= q; ++p) *(p-1) = *p;
	--(length);
	return OK;
}//ListDelete_Sq;

int SqList::LocateElem_Sq(ElemType e){
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�ERROR
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
				cout<<"��ǰ˳���Ϊ��"<<endl;
	}
	else{
	    cout<<"��ǰ˳�������Ϊ��";
	    for(i = 0; i < length; i++){
		    cout<<*p++<<" ";
	    }
	cout<<endl;
	}
}//OutputList_Sq;

void SqList::ClearList_Sq(){
	length=0;
	cout<<"��������Ա�"<<endl;
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
	cout<<"\t*   1.����һ��˳���    *\n";
	cout<<"\t*   2.���һ��˳���    *\n";
	cout<<"\t*   3.����              *\n";
	cout<<"\t*   4.��λ�ò���һ��Ԫ��*\n";
	cout<<"\t*   5.��λ��ɾ��һ��Ԫ��*\n";
	cout<<"\t*   6.���˳���        *\n";
	cout<<"\t*   7.�ϲ����������    *\n";
	cout<<"\t*   8.��ֵɾ��ĳһ��Ԫ��*\n";
	cout<<"\t*   9.ɾ������x         *\n";
	cout<<"\t*   0.�˳�              *\n";
}

void SqList::MergeList_Sq(SqList L1, SqList L2){
	//��֪˳�����Ա�L1��L2��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢L1��L2�õ��µ�˳�����Ա�L3��L3��Ԫ��Ҳ��ֵ�ǵݼ�����
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
		cout<<"������0-9��   ";
		cin>>input;
		if(input==0)break;
		switch(input){

		case 1:{
			cout<<"������˳���Ԫ�صĸ���"<<endl;
			cin>>n;
			cout<<"����������"<<n<<"���������Կո��س����"<<endl;
			if(p->SqList_Create(n)==OK)cout<<"������˳���"<<endl;
			p->OutputList_Sq();
			   }
			   break;
		
		case 2:{
			if(p->SqList_Length()==0){
				cout<<"��ǰ˳���Ϊ�գ����Ƚ���˳���"<<endl;
				break;
			}
			p->OutputList_Sq();
			}
			break;

		case 3:{
			if(p->SqList_Length()==0){
				cout<<"��ǰ˳���Ϊ�գ����Ƚ���˳���"<<endl;
				break;
			}
			cout<<"������Ҫ���ҵ�������";
			cin>>e;
			i=p->LocateElem_Sq(e);
			if(i== ERROR){
				cout<<"δ�ҵ�"<<e<<endl;
				break;
			}
			cout<<e<<"�Ǳ��е�"<<i<<"��Ԫ��"<<endl;
			   }
			   break;
			   
		case 4:{
			if(p->SqList_Length()==0){
				cout<<"��ǰ˳���Ϊ�գ����Ƚ���˳���"<<endl;
				break;
			}
			cout<<"���������Ԫ�ص�λ�ú�����ֵ���Կո�����";
			cin>>i>>e;
			if(p->ListInsert_Sq(i,e) == OK){
				cout<<"����ɹ�"<<endl;
				p->OutputList_Sq();
			}
			else cout<<"�����ֵ���Ϸ�"<<endl;
			   }
			break;

		case 5:{
			if(p->SqList_Length()==0){
				cout<<"��ǰ˳���Ϊ�գ����Ƚ���˳���"<<endl;
				break;
			}
			cout<<"������Ҫɾ��Ԫ�ص�λ�ã�"<<endl;
			cin>>i;
			if(p->ListDelete_Sq(i,e) == OK){
				cout<<"��ɾ����Ԫ����"<<e<<endl;
				p->OutputList_Sq();
			}
			else cout<<"�����ֵ���Ϸ�"<<endl;
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
			cout<<"������1�������������һ����������һ��ΪԪ�ظ�����"<<endl;
			int n1;
			cin>>n1;
			if(L1.SqList_Create(n1)==OK)cout<<"�����ɵ�һ�������"<<endl;
			L1.OutputList_Sq();
			cout<<"������2�������������һ����������һ��ΪԪ�ظ�����"<<endl;
			int n2;
			cin>>n2;
			if(L2.SqList_Create(n2)==OK)cout<<"�����ɵڶ��������";
			L2.OutputList_Sq();
			//SqList L3;
			L3.MergeList_Sq(L1,L2);
			L3.OutputList_Sq();
			   }
			   break;

		case 8:{
			if(p->SqList_Length()==0){
				cout<<"��ǰ˳���Ϊ�գ����Ƚ���˳���"<<endl;
				break;
			}
			cout<<"������Ҫɾ��������ֵ����ֻɾ���ҵ��ĵ�һ��Ԫ�أ�"<<endl;
			cin>>e;
			if(L.Delete_Sq(e) == ERROR){
				cout<<"δ�ҵ�"<<endl;
				break;
			}
			cout<<"��ɾ��"<<endl;
			L.OutputList_Sq();
			   }
			break;

		case 9:{
			if(p->SqList_Length()==0){
				cout<<"��ǰ˳���Ϊ�գ����Ƚ���˳���"<<endl;
				break;
			}
			cout<<"������Ҫɾ��������ֵ��"<<endl;
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