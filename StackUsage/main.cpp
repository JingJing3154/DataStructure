#include<iostream>
#include<string>
#include<stack>

using namespace std;

//该函数是用来给运算符排优先级
int prio(char op) {
	int priority;
	if (op == '*' || op == '/') {
		priority = 2;
	}
	if (op == '+' || op == '-') {
		priority = 1;
	}
	if (op == '(') {
		priority = 0;
	}
	return priority;
}
/*
用来进行中缀到后缀的改变
核心思想：
1、从左到右开始扫描中缀表达式
2、遇到数字直接输出，遇到运算符
	a、若为“（”直接入栈
	b、若为“）”将符号栈中的元素一次出栈并输出，直到“（”，“（”只出栈不输出
	c、若为其他符号，将符号栈中的元素依次出栈并输出，直到遇到比当前符号优先级更低的符号或者“（”，将该符号压栈
3、扫描完后，将栈中剩余符号依次输出
*/
bool Trans(string& str, string& str1) {
	stack<char> a;
	int i;
	for (i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z') {
			str1 += str[i];//遇到数字直接加到后缀表达式中
		}
		else {//不是数字
			if (a.empty())//栈空则入栈
				a.push(str[i]);
			else if (str[i] == '(')
				a.push(str[i]);
			else if (str[i] == ')')
			{
				while (a.top() != '(') {
					str1 += a.top();
					a.pop();
				}
				a.pop();//弹出左括号，但不输出
			}
			else {
				while (prio(str[i]) <= prio(a.top())){ //栈顶优先级大于等于当前运算符，则输出
					str1 += a.top();
					a.pop();
					if (a.empty())
						break;
				}
				a.push(str[i]);
			}
		}
	}
	while (!a.empty()) {
		str1 += a.top();
		a.pop();
	}
	return true;
}
/*1. 遍历字符串，遇到操作数压入栈中，遇到操作数，则把 * *前两个 * *操作数取出，进行运算，再将结果压入栈中
2. 最后将栈中最后的元素进行输出*/
bool suffixCalculate(string str, int& res) {
	int front, second,third=0;
	stack<char> a;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			a.push(str[i]-'0');
		}
		else {
			if (a.empty()) {
				return false;
			}
			//后缀中不会出现括号所以只需要考虑运算符即可
			second = a.top();
			a.pop();
			front = a.top();
			a.pop();
			switch (str[i]) {
			case '+':
				third = front + second;
				break;
			case '-':
				third = front - second;
				break;
			case '*':
				third = front * second;
				break;
			case '/':
				third = front / second;
				break;
			default:break;
			}
			a.push(third);
			front = second = third = 0;
		}
	}
	res = a.top();
	a.pop();
	return true;
}
int main() {
	int res;
	string infix;
	string postfix;
	cout << "输入中缀表达式:" << infix << endl;
	cin >> infix;
	Trans(infix, postfix);
	cout << "后缀表达式:" << postfix << endl;
	suffixCalculate(postfix, res);
	cout << "后缀表达式计算的结果是:" << res << endl;
	return 1;
}