// BINARY SEARCH TREE LIBRARY
// Create date: October 29, 2018
// Creator : DANG QUOC DUNG
// Version: 1.0

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int KeyType;
typedef struct Node{
	KeyType Key;
	Node* Left;
	Node* Right;
};

typedef Node* BST;

void MakeNullTree(BST &T){
	T = NULL;
}

int EmptyTree(BST T){
	return T == NULL;
}

BST LeftChild(BST T){
	if(!EmptyTree(T))
		return T->Left;
	else
		return NULL;
}

BST RightChild(BST T){
	if(!EmptyTree(T))
		return T->Right;
	else
		return NULL;
}

int isLeaf(BST T){
	return ((EmptyTree(T)) && (LeftChild(T) == NULL) && (RightChild(T) == NULL));
}

BST Search(KeyType K, BST root){
	if(!EmptyTree(root)){
		if(K == root->Key)
			return root;//Neu key = gia tri cua root thi tra ve root do
		else if(K > root->Key)
			return Search(K, root->Left);//Neu key < gia tri cua root thi search ben trai
		else
			return Search(K, root->Right);//Nguoc lai
	}
	else
		return NULL;
}

void InsertNode(KeyType K, BST &root){
	if(root == NULL){
		//Neu chua ton tai nut goc thi tao nut moi
		root = (Node*)malloc(sizeof(Node));
		root->Key = K;
		root->Left = NULL;
		root->Right = NULL;
	}
	//Neu K be hon nut goc thi insert ben trai
	else if(K < root->Key){
		InsertNode(K,root->Left);
	}
	//Neu K lon hon nut goc thi insert ben phai
	else if(K > root->Key){
		InsertNode(K, root->Right);
	}
}

KeyType DeleteMin(BST &root){
	KeyType K;
	if(root->Left == NULL){
		K = root->Key;
		root = root->Right;
		return K;
	}
	else
		return DeleteMin(root->Left);
}

KeyType DeleteMax(BST &root){
	KeyType k;
	if(root->Right == NULL){
		k = root->Key;
		root = root->Left;
		return k;
	}
	else
		return DeleteMax(root->Right);
}

void DeleteNode(KeyType K, BST &root){
	if(!EmptyTree(root)){
		if(K < root->Key)
			DeleteNode(K, root->Left);
		else if (K > root->Key)
			DeleteNode(K, root->Right);
			else if(isLeaf(root))
				root = NULL; //Neu nut la` la' thi xoa nut di
			else if(root->Left == NULL)
			//Neu nut co 1 cay con thi thay nut nay boi cay do
				root = root->Right; 
			else if(root->Right == NULL)
				root = root->Left;
			else 
				//Neu nut co 2 cay con thi thay nut do boi cay con nho nhat ben phai
				root->Key = DeleteMin(root->Right);
	}
}

void PreOrder(BST T){
	if(!EmptyTree(T)){
		printf("%3d",T->Key);
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
} 

void InOrder(BST T){
	if(!EmptyTree(T)){
		InOrder(T->Left);
		printf("%3d", T->Key);
		InOrder(T->Right);
	}
}

void PosOrder(BST T){
	if(!EmptyTree(T)){
		PosOrder(T->Left);
		PosOrder(T->Right);
		printf("%3d",T->Key);
	}
}

int main(){
	BST T;
	MakeNullTree(T);
	InsertNode(27,T);
	InsertNode(12,T);
	InsertNode(4,T);
	InsertNode(20,T);
	InsertNode(27,T);
	InsertNode(40,T);
	InsertNode(34,T);
	InsertNode(30,T);
	InsertNode(50,T);
	
	printf("Danh sach duyet tien tu: \n");
	PreOrder(T);
	
	printf("\nDanh sach duyet trung tu: \n");
	InOrder(T);
	
	printf("\nDanh sach duyet hau tu: \n");
	PosOrder(T);
}











