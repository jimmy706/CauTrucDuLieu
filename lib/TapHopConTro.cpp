// THU VIEN TAP HOP TAO BANG CON TRO
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Node{
	ElementType Data;
	Node* Next;
};

typedef Node* Position;
typedef Position Set;

void MakeNullSet(Set &S){
	S = (Node*)malloc(sizeof(Node));
	S->Next = NULL;
}

int EmptySet(Set S){
	return S->Next == NULL;
}

int Member(ElementType X, Set S){
	Position P = S;
	int Found = 0;
	while((P->Next != NULL) && !Found){
		if(P->Next->Data == X)	Found = 1;
		else P = P->Next;
	}
	return Found;
}

void InsertSet(ElementType X, Set &S){
	Position T, P = S;
	int Finish=0, Found=0;
	
	while((P->Next != NULL) && !Finish && !Found){
		if(P->Next->Data == X)	Found = 1; //Neu ton tai X trong danh sach thi found = 1
		else if(P->Next->Data < X)	P = P->Next; // Neu chua co thi cho position -> next
		else Finish = 1; 
	}
	
	//Neu khong ton tai X thi moi gan vao cuoi hang cua tap hop
	if(!Found){
		T = (Node*)malloc(sizeof(Node));
		T->Data = X;
		T->Next = P->Next; // P dang giu vi tri de chen phan tu X
		P->Next = T;
	}
}

//Xoa phan tu X ra khoi tap hop
void DeleteSet(ElementType X, Set &S){
	Position P = S, T;
	int Found = 0;
	//Tim vi tri cua X
	while((P->Next != NULL) && !Found){
		if(P->Next->Data == X) Found = 1;
		else P = P->Next;
	}
	
	//Neu tim thay thi giai phong T
	if(Found){
		T = P->Next;
		P->Next = T->Next;
		free(T);
	}
}

void Union(Set A, Set B, Set &C){
	Position P = A;
	MakeNullSet(C);
	
	//Them tat ca phan tu cua A vao C
	while(P->Next != NULL){
		InsertSet(P->Next->Data, C);
		P = P->Next;
	}
	
	P = B;
	//Kiem tra xem co phan tu cua B trung voi A khong, neu khong trung thi them phan tu do vao C
	while(P->Next != NULL){
		if(!Member(P->Next->Data, A)) //Neu co phan tu KHONG trung voi A thi them vao C
			InsertSet(P->Next->Data, C);
		P = P->Next;
	}
}

void Intersection(Set A, Set B, Set &C){
	Position P = A;
	MakeNullSet(C);
	
	//Kiem tra xem co phan nao cua A thuoc B ko, neu co thi them vao C
	while(P->Next != NULL){
		if(Member(P->Next->Data, B)) 
			InsertSet(P->Next->Data, C);
		P = P->Next;
	}
}

void Difference(Set A, Set B, Set &C){
	Position P = A;
	MakeNullSet(C);
	
	//Kiem tra xem co phan nao cua A thuoc B ko, neu khong thi them vao C
	while(P->Next != NULL){
		if(!Member(P->Next->Data, B)) 
			InsertSet(P->Next->Data, C);
		P = P->Next;
	}
}

void ReadSet(Set &S){
	MakeNullSet(S);
	ElementType X;
	int n;
	do{
		printf("\nSo phan tu co trong tap hop: ");
		scanf("%d",&n);
	}
	while(n < 0);
	
	for(int i = 0; i < n;i++){
		printf("\n Phan tu thu %d la: ", i+1);
		scanf("%d",&X);
		if(!Member(X,S))			
			InsertSet(X,S);
		
		else
			printf("\n Phan tu da ton tai");
	}
}

void PrintSet(Set S){
	Position P = S;
	while(P->Next != NULL){
		printf("\t%d",P->Next->Data);
		P = P->Next;
	}
}

int main(){
	Set A, B, C;
	MakeNullSet(A);
	
	printf("\nNhap ham A: ");
	ReadSet(A);
	printf("\n Phan tu trong A: ");
	PrintSet(A);
	
	printf("\n\nNhap ham B: ");
	ReadSet(B);
	printf("\n Phan tu trong B: ");
	PrintSet(B);
	
	printf("\n Hop cua A va B la: \n");
	Union(A,B,C);
	PrintSet(C);
	
	printf("\n Giao cua A va B la: \n");
	Intersection(A,B,C);
	PrintSet(C);
	
	printf("\n Hop cua A va B la: \n");
	Difference(A,B,C);
	PrintSet(C);
	
}





