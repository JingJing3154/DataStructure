#include<iostream>
#include<string>
#include<stack>

using namespace std;

//�ú���������������������ȼ�
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
����������׺����׺�ĸı�
����˼�룺
1�������ҿ�ʼɨ����׺���ʽ
2����������ֱ����������������
	a����Ϊ������ֱ����ջ
	b����Ϊ������������ջ�е�Ԫ��һ�γ�ջ�������ֱ����������������ֻ��ջ�����
	c����Ϊ�������ţ�������ջ�е�Ԫ�����γ�ջ�������ֱ�������ȵ�ǰ�������ȼ����͵ķ��Ż��ߡ����������÷���ѹջ
3��ɨ����󣬽�ջ��ʣ������������
*/
bool Trans(string& str, string& str1) {
	stack<char> a;
	int i;
	for (i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z') {
			str1 += str[i];//��������ֱ�Ӽӵ���׺���ʽ��
		}
		else {//��������
			if (a.empty())//ջ������ջ
				a.push(str[i]);
			else if (str[i] == '(')
				a.push(str[i]);
			else if (str[i] == ')')
			{
				while (a.top() != '(') {
					str1 += a.top();
					a.pop();
				}
				a.pop();//���������ţ��������
			}
			else {
				while (prio(str[i]) <= prio(a.top())){ //ջ�����ȼ����ڵ��ڵ�ǰ������������
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
/*1. �����ַ���������������ѹ��ջ�У���������������� * *ǰ���� * *������ȡ�����������㣬�ٽ����ѹ��ջ��
2. ���ջ������Ԫ�ؽ������*/
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
			//��׺�в��������������ֻ��Ҫ�������������
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
	cout << "������׺���ʽ:" << infix << endl;
	cin >> infix;
	Trans(infix, postfix);
	cout << "��׺���ʽ:" << postfix << endl;
	suffixCalculate(postfix, res);
	cout << "��׺���ʽ����Ľ����:" << res << endl;
	return 1;
}