#include <stdio.h>
#include <stdlib.h>
//顺序表的增删查
#define MaxSize 50
#define Locate 30
typedef int ElemType;
//静态分配
typedef struct {
	ElemType data[MaxSize];//定义的数组，用来存储元素
	int length;
}SqList;
//i代表插入的位置，从1开始，e代表需要插入的元素
bool ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	if (L.length >= MaxSize) {
		return false;
	}//通过判断位置 增强代码的健壮性
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];//移动顺序表中的元素，每一个往后移动
	}
	L.data[i - 1] = e;//数组下标从0开始，插入到前一个位置
	L.length++;
	return true;
}
//删除顺序表中的元素 i 代表位置
bool ListDelete(SqList& L, int i, ElemType& del) {
	if (i > L.length || i<0 ) {
		return false;
	}
	del = L.data[i - 1];//放在整个数组中需要多考虑下 循环的起、尾
	for (int j = i; j < L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}
//打印顺序表
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("L.data[%d]=%d  ", i, L.data[i]);
	}
	printf("\n");
}
//返回元素位置
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
//按值查找位置
//按位置查找元素较为简单不写了
int main() {
	SqList L;//定义顺序表,顺序表名称:L
	bool ret;//查看返回值
	ElemType del;//用来存储用于删除的元素
	//手动赋值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("插入成功\n");
		//PrintList(L);
	}
	else {
		printf("插入失败\n");
	}
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("删除成功, 删除的值为%d\n",del);
		//PrintList(L);
	}
	else {
		printf("删除失败\n");
	}
	if (LocateSearch(L, Locate) == -1) {
		printf("没有找到这个数字");
	}
	else {
		printf("查到了这个数字 在顺序表的第%d位\n",LocateSearch(L,Locate));
	}
	return 0;
}