//#include"btree.cpp"
//int main() {
//	BTNode* b, * p, * lp, * rp;
//	printf(":\n");
//	CreateBTree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,(G(,I)))");
//	DispBTree(b);
//	printf("\n");
//	printf("H节点:");
//	p = FindNode(b, 'H');
//	if (p != NULL) {
//		lp = LchildNode(p);
//		if (lp != NULL)
//			printf("left %c", lp->data);
//		else printf("no left");
//		rp = RchildNode(p);
//		if (lp != NULL)
//			printf("right %c", rp->data);
//		else printf("no right");
//	}
//	printf("\n");
//	printf("HEIGHT:%d\n", BTHeight(b));
//	printf("\n");
//	DestroyBTree(b);
//	return 0;
//}