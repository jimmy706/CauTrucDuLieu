/*
 - Viet ham nhap cay nhi phan voi so nut cho truoc, trong do nhan cua cac nut la so nguyen duong
 - Viet ham xac dinh duong di tu nut goc den nut X ElementType 	
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node{
	ElementType Label;
	Node* Left;
	Node* Right;
};
typedef Node* Tree;

void MakeNullTree(Tree &T){
	T = NULL;
}

int EmptyTree(Tree T){
	return T==NULL;
}

int isLeaf(Tree T){
	return (T->Left == NULL && T->Right == NULL);
}

void InsertTree(ElementType X, Tree &T){
	if(EmptyTree(T)){
		T = (Node*)malloc(sizeof(Node));
		T->Label = X;
		T->Left = NULL;
		T->Right = NULL;
	}
	else if(X > T->Label)
		InsertTree(X,T->Right);
	else if(X < T->Label)
		InsertTree(X,T->Left);
	else
		printf("\n %d da ton tai tren cay",X);
}

void ReadTree(Tree &T){
	ElementType X;
	MakeNullTree(T);
	printf("\nNhap vao cac gia tri cho cay tim kiem, -1 de ket thuc: ");
	do{
		printf("\n x = ");
		fflush(stdin);
		scanf("%d",&X);	
		if(X!=-1)
			InsertTree(X,T);
	}
	while(X!=-1);
}

int numberOfNode(Tree root){
	if(!EmptyTree(root))
		return (1 + numberOfNode(root->Right) + numberOfNode(root->Left));
	else
		return 0;
}

int TreeHeigth(Tree T){
	if(EmptyTree(T) || isLeaf(T))
		return 0;
	else
		return (1 + TreeHeigth(T->Left) + TreeHeigth(T->Right));
}

Tree Search(ElementType X, Tree T){
	if(EmptyTree(T))
		return NULL;
	else if(X == T->Label)
		return T;
	else if(X > T->Label)
		return Search(X,T->Right);
	else
		return Search(X,T->Left);
}

void findRoad(ElementType X, Tree T){
	if(Search(X,T)!=NULL){
			printf("%3d",T->Label);
		if(X > T->Label)
			findRoad(X,T->Right);
		else
			findRoad(X,T->Left);
	}
}

void PreOrder(Tree T){
	printf("%3d",T->Label);
	if(T->Left != NULL)
		PreOrder(T->Left);
	if(T->Right != NULL)
		PreOrder(T->Right);
}

void InOrder(Tree T){
	if(T->Left!=NULL)
		InOrder(T->Left);
	printf("%3d",T->Label);
	if(T->Right != NULL)
		InOrder(T->Right);
}

void PosOrder(Tree T){
	if(T->Left != NULL)
		PosOrder(T->Left);
	if(T->Right != NULL)
		PosOrder(T->Right);
	printf("%3d",T->Label);
}


int main(){
	Tree T;
	ElementType X;
	ReadTree(T);
	printf("\nSo nut cua cay: %d", numberOfNode(T));
	printf("\nChieu cao cua cay: %d", TreeHeigth(T));
	printf("\nTien tu: ");
	PreOrder(T);
	printf("\nTrung tu: ");
	InOrder(T);
	printf("\nHau tu: ");
	PosOrder(T);
	printf("\nNhap nhan can tim duong di: ");
	scanf("%d",&X);
	printf("\nDuong di tu goc den %d: ",X);
	findRoad(X,T);
}






















