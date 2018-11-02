#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define Buckets 10

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	Node* Next;
};
typedef Node* Position;
typedef Position Dictionary[Buckets];

//Thiet ke ham bam
int Hash(ElementType X){
	return X % Buckets;
}

void MakeNullDictionary(Dictionary &D){
	for(int i = 0; i < Buckets; i++){
		D[i]->Next = NULL;
	}
}

int EmptyDictionary(Dictionary D){
	int isEmpty = 1;
	for(int i = 0; i < Buckets; i++){
		if(D[i]->Next != NULL)
			isEmpty = 0;
	}	
	return isEmpty;
}

int FullDictionary(Dictionary D){
	int isFull = 1;
	for(int i = 0; i < Buckets; i++){
		if(D[i]->Next == NULL)
			isFull = 0;
	}	
	return isFull;
}

int Member(ElementType X, Dictionary D){
	Position P = D[Hash(X)];
	int Found = 0;
	while((P!=NULL) && (!Found)){
		if(P->Data == X)
			Found = 1;
		else
			P = P->Next;
	}
	return Found;
}

//Xen vao dau lo^
//void InsertDictionary(ElementType X, Dictionary &D){
//	int Bucket;
//	Position P;
//	if(!Member(X,D)){
//		Bucket = Hash(X);
//		P = D[Bucket];
//		D[Bucket] = (Node*)malloc(sizeof(Node));
//		D[Bucket]->Data = X;
//		D[Bucket]->Next = P;
//	}
//}

//Xen vao cuoi lo^
void InsertDictionary(ElementType X, Dictionary &D){
	Position P = D[Hash(X)], Temp;
	if(!Member(X,D)){
		Temp = (Node*)malloc(sizeof(Node));
		Temp->Data = X;
		Temp->Next = NULL;
		P->Next = Temp;
	}
	else{
		printf("Phan tu da ton tai");
	}
}

void DeleteDictionary(ElementType X, Dictionary &D){
	Position P = D[Hash(X)], Temp;
	if(Member(X,D)){
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

void ReadDictionary(Dictionary &D){
	int i,X,N;
	MakeNullDictionary(D);
	printf("So phan tu: ");
	scanf("%d",&N);
	for(int i = 1; i < N; i++){
		printf("Phan tu thu %d: ", i);
		scahnf("%d",&X);
		InsertDictionary(X,D);
	}
}

int main(){
	
}



