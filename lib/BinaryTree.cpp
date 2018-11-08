// BINARY TREE LIBRARY
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef char DataType;
typedef struct Node{
	DataType Data;
	Node* Left;
	Node* Right;
};

typedef Node* B_Tree;

void MakeNullTree(B_Tree &T){
	T = NULL;
}

int EmptyTree(B_Tree T){
	return T == NULL;
}

B_Tree LeftChild(B_Tree T){
	if(!EmptyTree(T))
		return T->Left;
	else
		return NULL;
}

B_Tree RightChild(B_Tree T){
	if(!EmptyTree(T))
		return T->Right;
	else
		return NULL;
}

int isLeaf(B_Tree T){
	return (EmptyTree(T) && (LeftChild(T) == NULL) && (RightChild(T) == NULL));
}

B_Tree Create2(DataType data, B_Tree LeftNode, B_Tree RightNode){
	B_Tree NewTree; //Khai bao cay moi
	NewTree = (Node*)malloc(sizeof(Node));
	
	NewTree->Data = data;
	NewTree->Left = LeftNode;
	NewTree->Right = RightNode;
	return NewTree;
}

//Duyet tien tu 
void PreOrder(B_Tree T){
	if(!EmptyTree(T)){
		printf("%3c",T->Data);
		PreOrder(LeftChild(T));
		PreOrder(RightChild(T));
	}
}

//Duyet trung tu
void InOrder(B_Tree T){
	if(!EmptyTree(T)){
		InOrder(LeftChild(T));
		printf("%3c",T->Data);
		InOrder(RightChild(T));
	}
}

//Duyet hau tu
void PosOrder(B_Tree T){
	if(!EmptyTree(T)){
		PosOrder(LeftChild(T));
		PosOrder(RightChild(T));
		printf("%3c",T->Data);
	}
}

int NumberNode(B_Tree T){
	if(EmptyTree(T)) return 0;
	else{
		return 1 + NumberNode(LeftChild(T)) + NumberNode(RightChild(T));
	}
}

int NumberLeaf(B_Tree T){
	int leaf = 0;
	if(!EmptyTree(T)){
		if(isLeaf(T))
			leaf++;
		else
			leaf = NumberLeaf(LeftChild(T)) + NumberLeaf(RightChild(T));
	}
	return leaf;
}



int main(){
	B_Tree T,TreeLeft,TreeRight;
	
	TreeLeft = 
	Create2('B', 
		Create2('D',
			Create2('H',NULL,NULL),Create2('I',NULL,NULL)), 
		Create2 ('E',
			Create2('J',NULL,NULL),NULL));
			
	TreeRight = 
	Create2('C', 
		Create2('F',
			Create2('K',NULL,NULL),Create2('L',NULL,NULL)), 
		Create2 ('G',
			Create2('M',NULL,NULL),NULL));
	
	T = Create2('A',TreeLeft,TreeRight);
	
	printf("Danh sach duyet tien tu: \n");
	PreOrder(T);
	
	printf("\nDanh sach duyet trung tu: \n");
	InOrder(T);
	
	printf("\nDanh sach duyet hau tu: \n");
	PosOrder(T);
	
	printf("\n So nut tren cay: %d", NumberNode(T));
	printf("\n So la tren cay: %d", NumberLeaf(T));
}

