#include <stdio.h>
#include <intrin.h>
typedef char BiElemetype;
typedef struct BiTNode {
	BiElemetype data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;
typedef struct tag {
	BiTree p;
	struct tag* pnext;
}tag_t,*ptag_t;

int main() {
	BiTree pnew;
	int i, j, pos;
	char data;
	BiTree tree = NULL;//���ڵ�
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur;

	while (scanf("%c", &data) != EOF) {
		if (data == '\n'){
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = data;//�������� 
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//�½����нڵ㣬�����ڵ������нڵ���
		if (tree == NULL) {
			tree = pnew;
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;
		}
		else {
			ptail->pnext = listpnew;//�½ڵ�����б�ͨ��β�巨
			ptail = listpnew;
		}
		if (NULL == pcur->p->lchild) {
			//��������NULL
			pcur->p->lchild = pnew;
		}
		//pcur��ʼ��ָ��Ҫ����������Ŀ�����ڵ�
		else if (NULL == pcur->p->rchild) {
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;//���½ڵ���뵽�ڵ���ұߣ����ָ����һ���ڵ�
		}
	}

};