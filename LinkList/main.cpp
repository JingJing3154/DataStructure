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
		printf("节点元素为%d \n", L->data);
		L = L->next;
	}
}
void ListPrint(LinkList L) {
	while (L != NULL) {
		printf("节点元素为%d \n", L->data);
		L = L->next;
	}
}
LinkList CreatListTail(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s; int x;
	LNode* r = L;//指向尾部节点的指针
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
	L = (LinkList)malloc(sizeof(LNode));//带头节点的列表
	L->next = NULL;
	scanf("%d",&x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;//将读取到的数字赋值给LNode
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
LNode* GetElement(int locate, LinkList L) {
	LNode* p = L->next;//过滤头节点
	int j = 1;//
	if (locate == 0) {
		return L;
	}
	if (locate <1) {
		return NULL;
	}
	while (p&&j < locate) {
		p = p->next;//指向下一个节点
		j++;
	}
	return p;
}
LNode* LocateEle(int value, LinkList L) {
	LNode* p = L->next;
	while (p!=NULL && p->data!=value) // => p！=null && i<count
	{
		p = p->next;
	}
	return p;
}
bool ListFrontInsert(LinkList& L, int i, ElemType j) {
	//LNode* p = L->next;//定位到第一个元素
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	newNode->data = j;
	//int k = 1;//统计到了第几个元素
	//while (k < i-1) {//i代表插入元素的位置,所以这时要定位到前一个元素
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
	//寻找到目标节点的前一个结点
	//p代表将要删除的节点
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
	LNode* p = GetElement(i-1,L);//找到前一个节点
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;//目标节点
	p->next = q->next;
	free(q);
	q = NULL;//避免野指针
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
		//printf("该位置的元素为%d",search->data);
	}
	ListPrintHead(L);
	return 0;
}