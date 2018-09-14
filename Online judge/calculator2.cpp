 #include <stack>
#include <queue>
#include <string>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct node{
	double num;						//������
	char op;							//������
	bool flag;							//true ��ʾ ��������false ��ʾ ������
};

string str;							//����ı��ʽ
stack<node> s;						//������ջ
queue<node> q;						//��׺���ʽ����
map<char,int> op;					//�ֵ�

void Change(){						//����׺���ʽת��Ϊ��׺���ʽ
	double num;
	node temp;
	for(int i=0 ; i<str.length(); ){
		if(str[i] >= '0' && str[i] <= '9'){
			temp.flag = true;			//flag ���
			temp.num = str[i++] - '0';
			while(i<str.length() && str[i] >= '0' && str[i] <= '9'){
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!s.empty() && op[str[i]] <= op[s.top().op]){
			//ֻҪ������ջ��ջ��Ԫ�رȸò��������ȼ���
			//�ͰѲ�����ջջ��Ԫ�ص����󵽺�׺���ʽ�Ķ�����
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i ++;
		}
	}
	//���������ջ���в��������Ͱ�����������׺���ʽ������
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

double Cal(){						//�����׺���ʽ
	double temp1,temp2;
	node cur,temp;
	while(!q.empty()){
		cur = q.front();				//��¼��Ԫ��
		q.pop();
		if(cur.flag == true)
			s.push(cur);
		else{							//����ǲ�����
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if(cur.op == '+')
				temp.num = temp1 + temp2;
			else if(cur.op == '-')
				temp.num = temp1 - temp2;
			else if(cur.op == '*')
				temp.num = temp1 * temp2;
			else
				temp.num = temp1 / temp2;
			s.push(temp); 			//�Ѳ�����ѹ��ջd
		}
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	op['('] = 3; 						//�趨�����������ȼ�
	while(getline(cin,str),str != "0"){
		for(string::iterator it = str.end() ; it != str.begin() ; it --)
			if(*it == ' ')
				str.erase(it);		//�ѱ��ʽ�еĿո�ȫ��ȥ��
		while(!s.empty())
			s.pop();	// ��ʼ��ջ
		Change();	//����׺���ʽת��Ϊ��׺���ʽ
		printf("%.2f\n",Cal());		//�����׺���ʽ
	}
		return 0;
}

