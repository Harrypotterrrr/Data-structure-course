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
	double num;						//操作数
	char op;							//操作符
	bool flag;							//true 表示 操作数，false 表示 操作符
};

string str;							//输入的表达式
stack<node> s;						//操作符栈
queue<node> q;						//后缀表达式序列
map<char,int> op;					//字典

void Change(){						//将中缀表达式转换为后缀表达式
	double num;
	node temp;
	for(int i=0 ; i<str.length(); ){
		if(str[i] >= '0' && str[i] <= '9'){
			temp.flag = true;			//flag 标记
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
			//只要操作符栈的栈顶元素比该操作符优先级高
			//就把操作符栈栈顶元素弹出后到后缀表达式的队列中
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i ++;
		}
	}
	//如果操作符栈还有操作符，就把它弹出到后缀表达式队列中
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

double Cal(){						//计算后缀表达式
	double temp1,temp2;
	node cur,temp;
	while(!q.empty()){
		cur = q.front();				//记录首元素
		q.pop();
		if(cur.flag == true)
			s.push(cur);
		else{							//如果是操作符
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
			s.push(temp); 			//把操作数压入栈d
		}
	}
	return s.top().num;
}

int main(){
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	op['('] = 3; 						//设定操作符的优先级
	while(getline(cin,str),str != "0"){
		for(string::iterator it = str.end() ; it != str.begin() ; it --)
			if(*it == ' ')
				str.erase(it);		//把表达式中的空格全部去掉
		while(!s.empty())
			s.pop();	// 初始化栈
		Change();	//将中缀表达式转换为后缀表达式
		printf("%.2f\n",Cal());		//计算后缀表达式
	}
		return 0;
}

