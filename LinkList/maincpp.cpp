#define _CRT_SECURE_NO_WARNINGS
#include <corecrt_malloc.h>
#include <stdio.h>

#define ElemType int
typedef struct LNode{
	ElemType data;// type of data
	struct LNode* next; // point
}LNode, *LinkList;

void ListPrintHead(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("�ڵ�Ԫ��Ϊ%d \n", L->data);
		L = L->next;
	}
}
void ListPrint(LinkList L) {
	while (L != NULL) {
		printf("�ڵ�Ԫ��Ϊ%d \n", L->data);
		L = L->next;
	}
}
LinkList CreatListTail(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s; int x;
	LNode* r = L;//ָ��β���ڵ��ָ��
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
LinkList CreatListHead(LinkList &L) {
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));//��ͷ�ڵ���б�
	L->next = NULL;
	scanf("%d",&x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;//����ȡ�������ָ�ֵ��LNode
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
int main() {
	LinkList L;
	LinkList search;
	//CreatListHead(L);
	CreatListTail(L);
	ListPrintHead(L);
}