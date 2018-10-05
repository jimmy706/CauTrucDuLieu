#include <conio.h>
#include <stdio.h>
#include <malloc.h>

typedef char DataType;
typedef struct Node{
	DataType Data;
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


Tree LeftChild(Tree n){
	return n->Left;
}

Tree RightChild(Tree n){
	return n->Right;
}

int IsLeaf(Tree n){
	return (LeftChild(n) == NULL && RightChild(n) == NULL);
}

void PreOrder(Tree T){
	printf("%5c",T->Data);
	if(LeftChild(T)!=NULL)
		PreOrder(LeftChild(T));
	if(RightChild(T)!=NULL)
		PreOrder(RightChild(T));
}


void InOrder(Tree T){
	if(LeftChild(T)!=NULL)
		InOrder(LeftChild(T));
	printf("%5c",T->Data);
	if(RightChild(T)!=NULL)
		InOrder(RightChild(T));
}

void PosOrder(Tree T){
	if(LeftChild(T)!=NULL)
		PosOrder(LeftChild(T));
	if(RightChild(T)!=NULL)
		PosOrder(RightChild(T));
	printf("%5c",T->Data);
}

Tree Create2(DataType v,Tree left,Tree right){
	Tree N;
	N=(Node*)malloc(sizeof(Node));
	N->Data = v;
	N->Left = left;
	N->Right = right;
	return N;
}



int main(){
	getch();
	return 0;
}







