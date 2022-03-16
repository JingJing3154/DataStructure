#define _CRT_SECURE_NO_WARNINGS
#include <corecrt_malloc.h>
#include <stdio.h>

typedef int ElemType;
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
LNode* GetElement(int locate, LinkList L) {
	LNode* p = L->next;//����ͷ�ڵ�
	int j = 1;//
	if (locate == 0) {
		return L;
	}
	if (locate <1) {
		return NULL;
	}
	while (p&&j < locate) {
		p = p->next;//ָ����һ���ڵ�
		j++;
	}
	return p;
}
LNode* LocateEle(int value, LinkList L) {
	LNode* p = L->next;
	while (p!=NULL && p->data!=value) // => p��=null && i<count
	{
		p = p->next;
	}
	return p;
}
bool ListFrontInsert(LinkList& L, int i, ElemType j) {
	//LNode* p = L->next;//��λ����һ��Ԫ��
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	newNode->data = j;
	//int k = 1;//ͳ�Ƶ��˵ڼ���Ԫ��
	//while (k < i-1) {//i�������Ԫ�ص�λ��,������ʱҪ��λ��ǰһ��Ԫ��
	//	p = p->next;
	//	k++;
	//}
	LNode* p = GetElement( i - 1,L);
	if (p == NULL) {
		return false;
	}
	newNode->next = p->next;
	p->next = newNode;
	return true;
}
bool ListDeleteOnValue(LinkList& L, LNode* p) {
	//Ѱ�ҵ�Ŀ��ڵ��ǰһ�����
	//p����Ҫɾ���Ľڵ�
	LNode* q = L;
	while (q != NULL && q->next->data != p->data) {
		q = q->next;
	}
	if (q == NULL) {
		return false;
	}
	p = q->next;
	q->next = q->next->next;
	free(p);
	return true;
}
bool ListDeleteOnLocate(LinkList& L, int i) {
	LNode* p = GetElement(i-1,L);//�ҵ�ǰһ���ڵ�
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;//Ŀ��ڵ�
	p->next = q->next;
	free(q);
	q = NULL;//����Ұָ��
	return true;
}
int main() {
	LinkList L;
	LinkList search;
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->data = 350;
	p->next = NULL;
	//CreatListHead(L);
	CreatListTail(L);
	//ListPrintHead(L);
	search = GetElement(2,L);
	search = LocateEle(6, L);
	//ListFrontInsert(L, 2, 99);
	//ListDeleteOnValue(L,p);
	ListDeleteOnLocate(L, 2);
	if (search != NULL) {
		//printf("��λ�õ�Ԫ��Ϊ%d",search->data);
	}
	ListPrintHead(L);
	return 0;
}