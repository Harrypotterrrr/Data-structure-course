#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;
#define SIZE 10000
typedef int KeyType;
typedef char InfoType;
struct RedType{
	KeyType key;
	InfoType otherinfo;
};

int static i_cmp,i_mov;
int static sel_cmp,sel_mov;
int static b_cmp,b_mov;
int static q_cmp,q_mov;
int static s_cmp,s_mov;
int static h_cmp,h_mov;
int static m_cmp,m_mov;

class maxHeap{
public:
	RedType elem[SIZE];
	int n;
	void createMinHeap(RedType arr[],int len){
		for(int i=1;i<=len;i++){h_mov++;elem[i-1]=arr[i];}
		n=len;
		int i=(n-2)/2;
		while(i>=0){
			siftDown(i,n-1);i--;
		}
	}
	void siftDown(int start,int m){
		int i=start;
		int j=2*i+1;
		RedType temp=elem[i];h_mov++;
		while(j<=m){
			h_cmp+=2;
			if(j<m&&elem[j].key<elem[j+1].key)
				j++;
			if(temp.key>elem[j].key)break;
			else{
				h_mov++;
				elem[i]=elem[j];i=j;j=2*j+1;
			}
		}
		elem[i]=temp;h_mov++;
	}
	void Swap(int i,int j){
		RedType temp;
		temp=elem[i];
		elem[i]=elem[j];
		elem[j]=temp;
	}
	void display(){
		int j=0;
		for(int i=0;i<n;i++){
			j++;
			cout<<elem[i].key<<' ';
			if(j%10==0)cout<<endl;
		}
		cout<<endl;
	}
};

class SqList{
private:
	RedType r[SIZE+1];
	int length;
public:
    void InitSqList(){
	    srand((unsigned)time(NULL));
	    int i;
	    for(i=1;i<=SIZE;i++)
	    	r[i].key=rand()%SIZE;
		length=SIZE;
    };
	void display(){
		int i,j=0;
		for(i=1;i<=length;i++){
			cout<<r[i].key<<' ';
			j++;
			if(j%10==0)cout<<endl;
		}
		cout<<endl;
	}
	
	//÷±Ω”≤Â»Î≈≈–Ú
	void InsertSort(){
		int i,j;
		i_cmp+=length-1;
		for(i=2;i<=length;i++)
			if(r[i].key<r[i-1].key){
				r[0]=r[i];
				r[i]=r[i-1];
				i_mov+=2;i_cmp++;
				for(j=i-2;r[0].key<r[j].key;--j){
					r[j+1]=r[j];
					i_mov++;i_cmp++;
				}
				r[j+1]=r[0];i_mov++;
			}
	}

	//÷±Ω”—°‘Ò≈≈–Ú
	void SelectSort(){
		int i,j,k;
		for(i=1;i<length;i++){
			k=i;
			for(j=i+1;j<=length;j++){
				if(r[j].key<r[k].key)k=j;
				sel_cmp++;
			}
			if(k!=i){
				r[0]=r[k];r[k]=r[i];r[i]=r[0];sel_mov+=2;
			}
		}
	}

	//√∞≈›≈≈–Ú
	void BubbleSort(){
		int exchange,i,j;
		for(i=1;i<length;i++){
			exchange=0;
			for(j=length;j>=i+1;j--){
				if(r[j-1].key>r[j].key){
					r[0]=r[j-1];r[j-1]=r[j];r[j]=r[0];
					b_mov+=2;
					exchange=1;
				}
				b_cmp++;
			}
			if(!exchange)return;
		}
	}

	//øÏÀŸ≈≈–Ú
	void QuickSort(int left,int right){
		if(left<right){
			int pivotpos=Partition(left,right);
			QuickSort(left,pivotpos-1);
			QuickSort(pivotpos+1,right);
		}
	}
	int Partition(int low,int high){
		int i,k=low;
		RedType pivot=r[low];
		for(i=low+1;i<=high;i++){
			q_cmp++;
			if(r[i].key<pivot.key){
				k++;
				if(k!=i){
					r[0]=r[i];r[i]=r[k];r[k]=r[0];
					q_mov+=2;
				}
			}
		}
		r[low]=r[k];r[k]=pivot;
		return k;
		}
	
	//Shell≈≈–Ú
	void ShellSort(int d[],int m){
		int i;
		for(i=0;i<m&&d[i]<SIZE;i++);
		for(;i<m&&i>=0;i--)
			insertSort(d[i]);
	}
	void insertSort(int gap){
		int i,j;
		for(i=1+gap;i<=length;i+=gap){
			s_cmp++;
			if(r[i-gap].key>r[i].key){
				r[0]=r[i];j=i;s_mov++;
				for(j=i-gap;j>0&&r[0].key<r[j].key;j-=gap){
					r[j+gap]=r[j];
					s_mov++;s_cmp++;
				}
				r[j+gap]=r[0];s_mov++;
			}
		}
	}

	//∂—≈≈–Ú
	void HeapSort(){
		maxHeap H;
		int i;
		H.createMinHeap(r,length);
		for(i=H.n-2/2;i>=0;i--)
			H.siftDown(i,H.n-1);
		for(i=H.n-1;i>0;i--){
			h_mov+=2;
			H.Swap(0,i);H.siftDown(0,i-1);
		}
		//H.display();
	}
	friend void Merge(SqList &L,int left,int mid,int right);
};

	//πÈ≤¢≈≈–Ú
	void MergeSort(SqList &L,int left,int right){
		if(left<right){
			int mid=(left+right)/2;
			MergeSort(L,left,mid);
			MergeSort(L,mid+1,right);
			Merge(L,left,mid,right);
		}
	}
	void Merge(SqList &L,int left,int mid,int right){
		int i=left,j=mid+1,k=0,s=right-left+1;
		RedType *L2=new RedType[s];
		if(!L2){cout<<"¥Ê¥¢∑÷≈‰ ß∞‹"<<endl;exit(1);}
		while(i<=mid&&j<=right){
			m_cmp++;
			if(L.r[i].key<L.r[j].key){
				L2[k++]=L.r[i++];
				m_mov++;
			}
			else{
				L2[k++]=L.r[j++];
				m_mov++;
			}
		}
		while(i<=mid){m_mov++;L2[k++]=L.r[i++];}
		while(j<=right){m_mov++;L2[k++]=L.r[j++];}
		for(i=0;i<s;i++){m_mov++;L.r[left+i]=L2[i];}
		delete []L2;	
	}

int main(){
	SqList L;
	cout<<"N="<<SIZE<<endl;
	L.InitSqList();
	cout<<"‘≠–Ú¡–£∫"<<endl;
	//L.display();
	cout<<"÷±Ω”≤Â»Î≈≈–Ú"<<endl;
	SqList L1=L;L1.InsertSort();//L1.display();
	cout<<"÷±Ω”—°‘Ò≈≈–Ú"<<endl;
	SqList L2=L;L2.SelectSort();//L2.display();
	cout<<"√∞≈›≈≈–Ú"<<endl;
	SqList L3=L;L3.BubbleSort();//L3.display();
	cout<<"shell≈≈–Ú"<<endl;
	SqList L4=L;
	int d[SIZE];
	int i,j=1;
	for(i=0;i<SIZE;i++)
		d[i]=pow(2,i+1)-1;
	L4.ShellSort(d,SIZE);
	//L4.display();
	cout<<"øÏÀŸ≈≈–Ú"<<endl;
	SqList L5=L;L5.QuickSort(1,SIZE);//L5.display();
	cout<<"∂—≈≈–Ú"<<endl;
	SqList L6=L;L6.HeapSort();
	cout<<"πÈ≤¢≈≈–Ú"<<endl;
	MergeSort(L,1,SIZE);
	//L.display();
	cout<<"N="<<SIZE<<endl;
	cout<<setw(30)<<"±»Ωœ¥Œ ˝"<<setw(15)<<"“∆∂Ø¥Œ ˝"<<endl;
	cout<<setw(15)<<"÷±Ω”≤Â»Î≈≈–Ú"<<setw(15)<<i_cmp<<setw(15)<<i_mov<<endl;
	cout<<setw(15)<<"÷±Ω”—°‘Ò≈≈–Ú"<<setw(15)<<sel_cmp<<setw(15)<<sel_mov<<endl;
	cout<<setw(15)<<"√∞≈›≈≈–Ú"<<setw(15)<<b_cmp<<setw(15)<<b_mov<<endl;
	cout<<setw(15)<<"shell≈≈–Ú"<<setw(15)<<s_cmp<<setw(15)<<s_mov<<endl;
	cout<<setw(15)<<"øÏÀŸ≈≈–Ú"<<setw(15)<<q_cmp<<setw(15)<<q_mov<<endl;
	cout<<setw(15)<<"∂—≈≈–Ú"<<setw(15)<<h_cmp<<setw(15)<<h_mov<<endl;
	cout<<setw(15)<<"πÈ≤¢≈≈–Ú"<<setw(15)<<m_cmp<<setw(15)<<m_mov<<endl;
	return 0;
}