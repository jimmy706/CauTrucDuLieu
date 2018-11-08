#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	Node* Left;
	Node* Right;
};
typedef Node* Tree;

void MakeNullTree(Tree &T){
	T = NULL;
}

int EmptyTree(Tree T){
	return T == NULL;
}

int isLeaf(Tree T){
	return (T->Left == NULL && T->Right == NULL);
}

void InsertTree(ElementType X, Tree &T){
	if(EmptyTree(T)){
		T = (Node*)malloc(sizeof(Node));
		T->Data = X;
		T->Left = NULL;
		T->Right = NULL;
	}
	else if(X > T->Data)
		InsertTree(X,T->Right);
	else if(X < T->Data)
		InsertTree(X,T->Left);
	else
		printf("\nDa ton tai nut nay");
}

void ReadTree(Tree &T){
	MakeNullTree(T);
	ElementType X;
	printf("\nNhap vao cac nut, -1 de ket thuc ");
	do{
		printf("\n - x = ");
		fflush(stdin);
		scanf("%d",&X);
		if(X!=-1)
			InsertTree(X,T);
	}
	while(X!=-1);
}

int TreeHeight(Tree root){
	if(EmptyTree(root) || isLeaf(root))
		return 0;
	else
		return (1 + TreeHeight(root->Left) + TreeHeight(root->Right));
}

int numberOfNode(Tree root){
	if(!EmptyTree(root))
		return (1+numberOfNode(root->Right) + numberOfNode(root->Left));
	else
		return 0;
}

Tree Search(ElementType X, Tree root){
	if(EmptyTree(root))
		return NULL;
	else if(root->Data == X)
		return root;
	else if (X < root->Data)
		return Search(X,root->Left);
	else
		return Search(X,root->Right);
}

void PreOrder(Tree T){
	printf("%3d", T->Data);
	if(T->Left != NULL)
		PreOrder(T->Left);		
	if(T->Right != NULL)
		PreOrder(T->Right);
}

void InOrder(Tree T){
	if(T->Left != NULL)
		InOrder(T->Left);
	printf("%3d",T->Data);
	if(T->Right != NULL)
		InOrder(T->Right);
}

void PosOrder(Tree T){
	if(T->Left != NULL)
		PosOrder(T->Left);
	if(T->Right != NULL)
		PosOrder(T->Right);
	printf("%3d",T->Data);
}

int main(){
	Tree T;
	ReadTree(T);
	printf("So nut cua cay la:%d",numberOfNode(T));
	printf("\nChieu cao cua cay la:%d",TreeHeight(T));
	printf("\nTien tu:");PreOrder(T);
	printf("\nTrung tu:");InOrder(T);
	printf("\nHau tu:");PosOrder(T);
	getch();
	return 0;
}







