#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#define Buckets 5

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	struct Node* Next;
};

typedef Node* Position;
typedef Position Dict[Buckets];

int Hash(ElementType X){
	return X%Buckets;
}

void MakeNullSet(Dict &D){
	for(int i = 0; i < Buckets; i++){
		D[i] = NULL;
	}
}

int Member(ElementType X, Dict D){
	Position P;
	int Found = 0;
	P = D[Hash(X)];
	while((P!=NULL)&&(!Found)){
		if(P->Data == X)
			Found = 1;
		else
			P = P->Next;		
	}
	return Found;
}

void InsertSet(ElementType X, Dict &D){
	int Bucket;
	Position P;
	if(!Member(X,D)){
		Bucket = Hash(X);
		P = D[Bucket];
		D[Bucket]=(Node*)malloc(sizeof(Node));
		D[Bucket]->Data = X;
		D[Bucket]->Next = P;
	}
}

void DeleteSet(ElementType X, Dict &D){
	int Bucket, Done;
	Position P,Q;
	Bucket = Hash(X);
	
	if(D[Bucket]->Data == X){
	/*if x is in the header of the list*/
		Q = D[Bucket];
		D[Bucket]->Next = Q->Next;
		free(Q);
	}
	else{
	/*Find X*/
		Done = 0;
		P = D[Bucket];
		while((P->Next!=NULL)&&(!Done))
			if(P->Next->Data == X) Done = 1;
			else P = P->Next;
		
		if(Done){
			/*delete p->next*/
			Q = P->Next;
			P->Next = Q->Next;
			free(Q);
		}
	}
}

void ReadSet(Dict &D){
	ElementType X;
	MakeNullSet(D);
	printf("Enter a list of integer numbers. -1 to stop.\n");
	do{
		printf("\n -x = ");
		scanf("%d",&X);
		if(X!=-1)
			InsertSet(X,D);
	}while(X!=-1);
}

void PrintSet(Dict D){
	Position P;
	for(int i = 0; i < Buckets; i++){
		P = D[i];
		printf("\n -row %d:",i);
		while(P!=NULL){
			printf("%3d",P->Data);
			P = P->Next;
		}
	}
}


int main(){
	Dict D;
	int x;
	ReadSet(D);
	PrintSet(D);
//	printf("Enter a number to find it\n");
//	printf("x=");scanf("%d",&x);
//	if(Member(x,D))
//	printf("%d is already in the dictionary.",x);
//	else printf("%d has not been in the dictionary.",x);
	
	getch();
	return 0;
}
