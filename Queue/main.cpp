#define _CRT_SECURE_NO_WARNINGS
#include <corecrt_malloc.h>
#include <stdio.h>
#define MAX_SIZE 5
typedef int ElemType;
typedef struct{
	ElemType data[MAX_SIZE];//数组，存储MaxSize-1个元素
	int front, rear;
}SqQueue;
void InitQueue(SqQueue &q) {
	q.front = q.rear = 0;
}
bool QueueEmpty(SqQueue& q) {
	if (q.rear == q.front) {
		return true;
	}
	return false;
}
bool EnQueue(SqQueue& q, ElemType i) {
	//入队列
	if ((q.rear + 1) % MAX_SIZE == q.front) {
		return false;
	}
	q.data[q.rear] = i;
	q.rear = (q.rear + 1) % MAX_SIZE;
	return true;
}
bool DeQueue(SqQueue& q, ElemType& x) {
	//出队列
	if (q.front == q.rear) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MAX_SIZE;
	return true;
}
int main() {
	ElemType res;
	bool flag;
	SqQueue q;
	InitQueue(q);
	EnQueue(q, 10);
	DeQueue(q, res);
}