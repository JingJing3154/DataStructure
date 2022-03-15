#include <stdio.h>
#include <stdlib.h>
//˳������ɾ��
#define MaxSize 50
#define Locate 30
typedef int ElemType;
//��̬����
typedef struct {
	ElemType data[MaxSize];//��������飬�����洢Ԫ��
	int length;
}SqList;
//i��������λ�ã���1��ʼ��e������Ҫ�����Ԫ��
bool ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	if (L.length >= MaxSize) {
		return false;
	}//ͨ���ж�λ�� ��ǿ����Ľ�׳��
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];//�ƶ�˳����е�Ԫ�أ�ÿһ�������ƶ�
	}
	L.data[i - 1] = e;//�����±��0��ʼ�����뵽ǰһ��λ��
	L.length++;
	return true;
}
//ɾ��˳����е�Ԫ�� i ����λ��
bool ListDelete(SqList& L, int i, ElemType& del) {
	if (i > L.length || i<0 ) {
		return false;
	}
	del = L.data[i - 1];//����������������Ҫ�࿼���� ѭ������β
	for (int j = i; j < L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}
//��ӡ˳���
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("L.data[%d]=%d  ", i, L.data[i]);
	}
	printf("\n");
}
//����Ԫ��λ��
int LocateSearch(SqList L, ElemType j) {
	int res=-1;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == j) {
			res = i + 1;
			return res;
		}
	}
	return -1;
}
//��ֵ����λ��
//��λ�ò���Ԫ�ؽ�Ϊ�򵥲�д��
int main() {
	SqList L;//����˳���,˳�������:L
	bool ret;//�鿴����ֵ
	ElemType del;//�����洢����ɾ����Ԫ��
	//�ֶ���ֵ
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("����ɹ�\n");
		//PrintList(L);
	}
	else {
		printf("����ʧ��\n");
	}
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("ɾ���ɹ�, ɾ����ֵΪ%d\n",del);
		//PrintList(L);
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	if (LocateSearch(L, Locate) == -1) {
		printf("û���ҵ��������");
	}
	else {
		printf("�鵽��������� ��˳���ĵ�%dλ\n",LocateSearch(L,Locate));
	}
	return 0;
}