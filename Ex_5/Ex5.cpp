#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100
class List{
public:
    List(); 				// ���캯��  
    List(int size); 			// ���ι��캯�� - ������󳤶�Ϊ size �ľ�̬���� 
    int Size() const; 		// ��������ĳ��� 
    bool IsFull() const; 		// ���������Ƿ�����  
    bool IsEmpty() const; 	// ���������Ƿ��ѿ�  
    void Clear(); 			// ������� 
	void Print();           // �������
    int Retrieve( int position, string &x ); 		// ��ȡ����� position λ�õ�Ԫ�ص� x ���ɹ����� 0 �����򷵻� -1 
    int Replace( int position, const string &x ); 	// ������� position λ�õ�Ԫ�ػ�Ϊ x ���ɹ����� 0 �����򷵻� -1 
    int Remove( int position, string &x ); 		// ��ȡ��ɾ������� position λ�õ�Ԫ�أ��ɹ����� 0 �����򷵻� -1 
    int Insert( int position, const string &x ); 	// ��Ԫ�� x ���뵽����� position λ�ã��ɹ����� 0 �����򷵻� -1 
    int Append(const string &x); 			// ��Ԫ�� x ׷�ӵ�����β�����ɹ����� 0 �����򷵻� -1
private:
	struct LNode{
		string data;
		int cur;
	};
	LNode *sls;
	int maxlen;
};

List::List(){
	int i;
	sls=new LNode[MAXSIZE+2];
	sls[0].cur=sls[1].cur=-1;
	sls[0].data="N/A";
	for(i=1;i<MAXSIZE+2;i++){
		sls[i].cur=i+1;
		sls[i].data="N/A";
	}
	sls[MAXSIZE+1].cur=-1;
	maxlen=MAXSIZE;
}

List::List(int size){
	int i;
	sls=new LNode[size+2];
	sls[0].cur=sls[1].cur=-1;
	sls[0].data="N/A";
	for(i=1;i<size+2;i++){
		sls[i].cur=i+1;
		sls[i].data="N/A";
	}
	sls[size+1].cur=-1;
	maxlen=size;
}

int List::Size()const{
	int i,j=0;
	for(i=sls[0].cur;i<maxlen+2&&sls[i].data!="N/A";i=sls[i].cur){
		++j;
	}
	return j; 
}

bool List::IsFull()const{
	if(sls[1].cur==-1)return 1;
	else return 0;
}

bool List::IsEmpty()const{
	if(sls[0].cur==-1)return 1;
	else return 0;
}

void List::Clear(){
	sls[0].cur=sls[1].cur=-1;
	sls[0].data="N/A";
	for(int i=1;i<maxlen+2;i++){
		sls[i].cur=i+1;
		sls[i].data="N/A";
	}
	sls[maxlen+1].cur=-1;
}

void List::Print(){
	int i,j=0;
	for(i=0;i<maxlen+2;i++){
		cout<<i<<" : "<<sls[i].data<<" : "<<sls[i].cur<<'\t';
		++j;
		if(j%3==0)cout<<endl;
	}
	cout<<"��ǰ����Ϊ:";
	for(i=0;sls[i].cur!=-1;){
		i=sls[i].cur;
		cout<<sls[i].data<<' ';
	}
	cout<<endl;
}

int List::Retrieve(int position,string &x){
	if(sls[position+1].data=="N/A"||position>maxlen||position<1)return -1;
	x=sls[position+1].data;
	return 0;
}

int List::Replace(int position,const string &x){
	if(sls[position+1].data=="N/A"||position>maxlen||position<1)return -1;
	else{
		sls[position+1].data=x;return 0;
	}
}

int List::Remove(int position,string &x){
	int i;
	if(sls[position+1].data=="N/A"||position>maxlen||position<1)return -1;
	else{
		for(i=0;sls[i].cur!=position+1;i=sls[i].cur);
		sls[i].cur=sls[position+1].cur;
		x=sls[position+1].data;
		sls[position+1].data="N/A";
		for(i=1;sls[i].cur!=-1&&sls[i].cur<position+1;)i=sls[i].cur;
		if(sls[i].cur==-1){
			sls[i].cur=position+1;
			sls[position+1].cur=-1;
		}
		else{
			sls[position+1].cur=sls[i].cur;
			sls[i].cur=position+1;
		}
		return 0;
	}
}

int List::Insert(int position,const string &x){
	int i,j;
	if(sls[position+1].data=="N/A"||position>maxlen||position<1||sls[1].cur==-1)return -1;
	else{
		i=sls[1].cur;sls[1].cur=sls[i].cur;
		sls[i].data=x;
		for(j=0;sls[j].cur!=position+1;j=sls[j].cur);
		sls[i].cur=sls[j].cur;
		sls[j].cur=i;
		return 0;
	}
}

int List::Append(const string &x){
	int i,j;
	if(IsFull()==1)return -1;
	else{
		for(i=0;sls[i].cur!=-1;i=sls[i].cur);
	    j=sls[1].cur;sls[1].cur=sls[j].cur;
		sls[j].data=x;
		sls[j].cur=-1;
		sls[i].cur=j;
	}
}

int main(){
	List L(7);
	cout<<"��1�����������У�Jan��Feb��Mar��Apr��May������ʼ����"<<endl;
	L.Append("Jan");
	L.Append("Feb");
	L.Append("Mar");
	L.Append("Apr");
	L.Append("May");
	L.Print();
	cout<<"��2���� Feb ֮ǰ��May ֮���Ⱥ���� Jun��Oct "<<endl;
	int i;string x;
	for(i=0;i<9;i++){
		if(L.Retrieve(i,x)==0&&x=="Feb")
			if(!L.Insert(i,"Jun"))break;
	}
	L.Append("Oct");
	L.Print();
	cout<<"��3���Ⱥ�ɾ�� Mar �� Jan"<<endl;
	for(i=0;i<9;i++){    
	    if(L.Retrieve(i,x)==0&&x=="Mar"){
		    L.Remove(i,x);
			break;
		}
	}
	for(i=0;i<9;i++){
    	if(L.Retrieve(i,x)==0&&x=="Jan"){
	    	L.Remove(i,x);
			break;
		}
	}
	L.Print();
	cout<<"��4���� Apr ֮ǰ���� Dec"<<endl;
	for(i=0;i<9;i++){
		if(L.Retrieve(i,x)==0&&x=="Apr")
			if(!L.Insert(i,"Dec"))break;
	}
	L.Print();
	return 0;
}