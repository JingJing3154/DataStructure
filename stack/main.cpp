#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX_SIZE 50
typedef int ElemType;
typedef struct {
	ElemType data[MAX_SIZE];
	int top;
}SqStack;
//初始化
void InitSqstack(SqStack &S) {
	for (int i = 0; i < MAX_SIZE; i++) {
		S.data[i] = 0;
	}
	S.top = -1;//判断空栈条件
}
//释放不作考虑
//判断栈的情况
bool SqStackEmpty(SqStack s) {
	if (s.top == -1) {
		return false;
	}
	return true;
}
bool GetTop(SqStack s, ElemType& res) {
	//获取栈顶元素
	if (s.top == -1) {
		return false;
	}
	res = s.data[s.top];
	return true;
}
bool SqStackPop(SqStack &s,ElemType &res) {
	if (s.top == -1) {
		return false;
	}
	res = s.data[s.top];
	s.top--;
	return true;
}
bool SqStackPush(SqStack& s, ElemType res) {
	s.top++;
	if (s.top >= MAX_SIZE) {
		return false;
	}
	s.data[s.top] = res;
	return true;
}
int main() {
	SqStack s;
	bool flag;
	ElemType res;
	InitSqstack(s);
	SqStackPush(s, 2);
	SqStackPush(s, 2);
	flag = SqStackPush(s, 1);
	if (flag) {
		printf("push succeed \n");
	}
	else {
		printf("push wrong \n");
	}
	SqStackPop(s,res);
	if (flag) {
		printf("pop succeed %d\n", res);
	}
	SqStackPop(s, res);
	if (flag) {
		printf("pop succeed %d\n", res);
	}
}