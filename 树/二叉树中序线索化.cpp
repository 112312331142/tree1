//#include<stdio.h>
//#include<malloc.h>
//#define MaxSize 100
//typedef char ElemType;
//typedef struct node {
//	ElemType data;
//	int ltag, rtag;
//	struct node* lchild;
//	struct node* rchild;
//}TBTNode;
//
//void CreateTBTree(TBTNode*& b,const char* str) {
//	TBTNode* St[MaxSize], * p=NULL;
//	int top = -1, k, j = 0;
//	char ch = str[j];
//	b = NULL;
//	while (ch != '\0') {
//		switch (ch) {
//		case'(':top++; St[top] = p; k = 1; break;
//		case')':top--; break;
//		case',':k = 2; break;
//		default:p = (TBTNode*)malloc(sizeof(TBTNode));
//			p->data = ch;
//			p->lchild = p->rchild = NULL;
//			if (b == NULL)
//				b = p;
//			else {
//				switch (k) {
//				case 1: St[top]->lchild = p; break;
//				case 2: St[top]->rchild = p; break;
//				}
//			}
//		}
//		j++;
//		ch = str[j];
//	}
//}
//
//void DispTBTree(TBTNode* b) {
//	if (b != NULL) {
//		printf("%c", b->data);
//		if (b->lchild != NULL || b->rchild != NULL) {
//			printf("(");
//			DispTBTree(b->lchild);
//			if (b->rchild != NULL)
//				printf(",");
//			DispTBTree(b->rchild);
//			printf(")");
//		}
//	}
//}
//
//TBTNode* pre;
//void Thread(TBTNode*& p) {
//	if (p != NULL) {
//		Thread(p->lchild);
//		if (p->lchild == NULL) {
//			p->lchild = pre;
//			p->ltag = 1;
//		}
//		else
//			p->ltag = 0;
//		if (pre->rchild == NULL) {
//			pre->rchild = p;
//			pre->rtag = 1;
//		}
//		else
//			p->rtag = 0;
//		pre = p;
//		Thread(p->rchild);
//	}
//}
//
//TBTNode* CreateThread(TBTNode* b) {
//	TBTNode* root;
//	root = (TBTNode*)malloc(sizeof(TBTNode));
//	root->ltag = 0;
//	root->rtag = 1;
//	root->rchild = b;
//	if (b == NULL)
//		root->lchild = root;
//	else {
//		root->lchild = b;
//		pre = root;
//		Thread(b);
//		pre->rchild = root;
//		pre->rtag = 1;
//		root->rchild = pre;
//	}
//	return root;
//}
//
//void InOrder(TBTNode* tb) {
//	if (tb->lchild != NULL && tb->ltag == 0)
//		InOrder(tb->lchild);
//	printf("%c", tb->data);
//	if (tb->rchild != NULL && tb->rtag == 0)
//		InOrder(tb->rchild);
//}
//
//void ThInOrder(TBTNode* tb) {
//	InOrder(tb->lchild);
//}
//
//void ThInOrder1(TBTNode*& tb) {
//	TBTNode* p = tb->lchild;
//	while (p != tb) {
//		while (p->ltag == 0)
//			p = p->lchild;
//		printf("%c", p->data);
//		while (p->rtag == 1 && p->rchild != tb) {
//			p = p->rchild;
//			printf("%c", p->data);
//		}
//		p = p->rchild;
//	}
//}
//
//void DestroyTBTree1(TBTNode* tb) {
//	if (tb != NULL) {
//		if (tb->lchild != NULL && tb->ltag == 0)
//			DestroyTBTree1(tb->lchild);
//		if (tb->rchild != NULL && tb->rtag == 0)
//			DestroyTBTree1(tb->rchild);
//		free(tb);
//	}
//}
//
//void DestroyTBTree(TBTNode* tb) {
//	DestroyTBTree1(tb->lchild);
//	free(tb);
//}
//
//int main() {
//	TBTNode* b, * tb;
//	CreateTBTree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
//	printf("二叉树："); DispTBTree(b); printf("\n");
//	tb = CreateThread(b);
//	printf("线索中序序列:\n");
//	printf("递归算法："); ThInOrder(tb); printf("\n");
//	printf("非递归算法:"); ThInOrder1(tb); printf("\n");
//	DestroyTBTree(tb);
//	return 1;
//}