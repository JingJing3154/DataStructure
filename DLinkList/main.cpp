#define _CRT_SECURE_NO_WARNINGS
#include <corecrt_malloc.h>
#include <stdio.h>

typedef int ElemType;
typedef struct DNode {
	ElemType data;
	DNode* prior, * next;
}DNode,*DLinkList;
void PrintDList(DLinkList DL) {
	DL = DL->next;
	while (DL != NULL) {
		printf("�ڵ��ֵΪ %d", DL->data);
		DL = DL->next;
	}
}
DLinkList Dlist_head_insert(DLinkList &DL) {
	//�������ͷ�ڵ�
	int x;
	DNode* p;
	DL = (DLinkList)malloc(sizeof(DLinkList));
	DL->next = NULL;
	DL->prior = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		p = (DLinkList)malloc(sizeof(DLinkList));
		p->data = x;
		p->next = DL->next;
		if (DL->next != NULL) {
			DL->next->prior = p;
		}
		p->prior = DL;
		DL->next = p;
		scanf("%d", &x);
	}
	return DL;
}
DLinkList Dlist_tail_insert(DLinkList& DL) {
	int x;
	DNode* p, * q;
	DL = (DLinkList)malloc(sizeof(DLinkList));
	DL->next = NULL;
	DL->prior = NULL;
	q = DL;
	scanf("%d", &x);
	while (x != 9999) {
		p = (DLinkList)malloc(sizeof(DLinkList));
		p->data = x;
		p->next = NULL;
		q->next = p;
		q->next->prior = q; // ==== p.prior = q;
		q = q->next;
		scanf("%d", &x);
	}
	q->next = NULL;
	return DL;
}
DNode* GetElem(DLinkList DL, int i) {
	DL = DL->next;//��λ����һ���ڵ�
	int k = 1;
	if (i <= 0) {
		return NULL;
	}
	while (k < i) {
		DL = DL->next;
		k++;
	}
	return DL;
}
bool Dlist_insert(DLinkList& DL,int i,ElemType x) {
	DNode* p = GetElem(DL, i - 1);//��λ��ǰһ��Ԫ��
	if (p == NULL) {
		return false;
	}
	DNode* q = (DNode*)malloc(sizeof(DNode));//Ϊ�½ڵ�����ռ�
	q->data = x;
	q->next = p->next;
	q->next->prior = q;
	q->prior = p;
	p->next = q;
	return true;

}
bool Dlist_Delete(DLinkList DL, int i) {
	DNode* p = GetElem(DL,i-1);//�ҵ�ǰһ���ڵ�
	if (p == NULL) {
		return false;
	}
	DLinkList q;
	q= p->next;
	if (q == NULL) {
		return false;
	}
	p->next = q->next;
	if (q->next != NULL) {//q->nextΪNUllɾ���������һ���ڵ�
		q->next->prior = p;
	}
	//free(q);//�ͷſռ�
	return true;
}
int main() {
	DLinkList DL;
	//Dlist_head_insert(DL);//ͷ��
	Dlist_tail_insert(DL);//β��
	DNode* search;
	search = GetElem(DL, 2);
	if (search != NULL) {
		printf(" �鵽�ڶ���Ԫ��Ϊ%d", search->data);
	}
	Dlist_insert(DL, 2, 3399);
	Dlist_Delete(DL, 3);
	PrintDList(DL);
	return 0;
}