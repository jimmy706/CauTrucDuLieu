//PRACTICE SET UP ARRAY LIST BY POINTER
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void MakeNullList(List &L){
	L = (Node*)malloc(sizeof(Node));
	L->Next = NULL;
}

int EmptyList(List L){
	return L->Next == NULL;
}

void InsertList(ElementType X, Position P, List &L){
	Position Temp;
	Temp = (Node*)malloc(sizeof(Node));
	Temp->Data = X;
	Temp->Next = P->Next;
	P->Next = Temp;
}


void DeleteList(Position P, List &L){
	Position Temp;
	if(P->Next!=NULL){
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}


Position Position_n(int n, List L){
	int i =1;	
	Position P = L;
	while(P->Next != NULL && i < n){
		P = P->Next;
		i++;
	}
	return P;
}

ElementType Retrieve(Position P, List L){
	if(P->Next!=NULL)
		return P->Next->Data;
}

Position First(List L){
	return L;
}

Position EndList(List L){
	Position P = First(L);
	while(P->Next!=NULL)
		P=P->Next;
	return P;
}

Position Locate(ElementType X, List L){
	Position P = First(L);
	int Found = 0;
	while((P->Next != NULL) && !Found){
		if(P->Next->Data==X)
			Found = 1;
		else
			P = P->Next;
	}
	return P;
}

void SortIncrease(List &L){
	Position P, Q;
	ElementType Temp;
	P = L->Next;
	while(P->Next!=NULL){
		Q=P->Next;
		while(Q->Next!=NULL){
			if(P->Data > Q->Data){
				Temp = P->Data;
				P->Data = Q->Data;
				Q->Data = Temp;
			}
			Q = Q->Next;
		}
		P = P->Next;
	}
}

void ReadList(List &L){
	ElementType X;
	printf("Nhap vao 1 danh sach cac so nguyen, -1 de dung\n");
	MakeNullList(L);
	do{
		printf("\n -x = ");
		scanf("%d",&X);
			InsertList(X,EndList(L),L);
	}
	while(X!=-1);
}

void PrintList(List L){
	Position P = L->Next;
	while(P->Next!=NULL){
		printf("%3d",P->Data);
		P = P->Next;
	}
}


int main(){
	ElementType x;
	int n;
	List L;
	Position P;
	ReadList(L);
	PrintList(L);
	printf("\nNhap vao 1 phan tu de them vao ds, x=");
	scanf("%d",&x);
	printf("Vi tri can them, n=");scanf("%d",&n);
	P=Position_n(n,L);
	InsertList(x,P,L);
	printf("\nDanh sach sau khi them %d la:\n",x);
	PrintList(L);
	printf("\nNhap vao 1 phan tu de xoa, x=");scanf("%d",&x);
	P=Locate(x,L);
	DeleteList(P,L);
	printf("\nDanh sach sau khi xoa %d la:\n",x);
	PrintList(L);
	SortIncrease(L);
	printf("\nDanh sach sau khi duoc sap xep:\n",x);
	PrintList(L);
	getch();
}
