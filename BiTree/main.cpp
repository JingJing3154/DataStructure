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
	BiTree tree = NULL;//根节点
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur;

	while (scanf("%c", &data) != EOF) {
		if (data == '\n'){
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = data;//放入数据 
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//新建队列节点，将树节点放入队列节点中
		if (tree == NULL) {
			tree = pnew;
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;
		}
		else {
			ptail->pnext = listpnew;//新节点放入列表，通过尾插法
			ptail = listpnew;
		}
		if (NULL == pcur->p->lchild) {
			//左子树是NULL
			pcur->p->lchild = pnew;
		}
		//pcur是始终指向要插入子树的目标树节点
		else if (NULL == pcur->p->rchild) {
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;//将新节点插入到节点的右边，随后指向下一个节点
		}
	}

};