#include <stdio.h>
#include <conio.h>
#define MaxLength 30

typedef int ElementType;
typedef int Position;
typedef struct {
	Position Last;
	ElementType Elements[MaxLength];
}List;

void MakeNullList(List &L){
	L.Last = 0;
}

int EmptyList(List L){
	return L.Last == 0;
}

int FullList(List L){
	return L.Last == MaxLength;
}

Position Next(Position P, List L){
	return P + 1;
}

Position Previous(Position P, List L){
	return P -1;
}

Position EndList(List L){
	return L.Last + 1;
}

ElementType Retrieve(Position P, List L){
	if(!EmptyList(L))
		return L.Elements[P-1];
}

Position Locate(ElementType X, List L){
	Position P;
	for(P=1;P < EndList(L);P++){
		if(Retrieve(P,L) == X)
			return P;
	}
}


void InsertList(ElementType X, Position P, List &L){
	if(!FullList(L)){
		for(Position i = L.Last; i >= P; i--){
			L.Elements[i] = L.Elements[i-1];
		}
		L.Last++;
		L.Elements[P-1] = X;
	}
}

void DeleteList(Position P, List &L){
	if(!EmptyList(L)){
		for(int i = P; i < L.Last; i++){
			L.Elements[i-1] = L.Elements[i];
		}
		L.Last--;
	}
}

void ReadList(List &L){
	ElementType X;
	Position P = 1;
	printf("Nhap vao cac gia tri trong danh sach, nhap -1 de ket thuc: ");
	do{
		printf("\n - x = ");
		fflush(stdin);
		scanf("%d",&X);
		if(X!=-1){
			InsertList(X,P,L);
			P = Next(P,L);	
		}
	}
	while(X != -1 && P <= MaxLength);
}

void PrintList(List L){
	for(Position P = 1; P < EndList(L); P++){
		printf("%3d", Retrieve(P,L));
	}
}

int main(){
	List L;
	MakeNullList(L);
	ElementType X;
	Position P;
	ReadList(L);
	printf("\n Danh sach sau khi duoc nhap:\n");
	PrintList(L);
	printf("\nNhap vao phan tu can them: ");
	scanf("%d",&X);
	printf("\nNhap vao vi tri can them: ");
	scanf("%d",&P);
	InsertList(X,P,L);
	printf("\nDanh sach sau khi them %d: \n",X);
	PrintList(L);
	printf("\nNhap vao phan tu can xoa: ");
	scanf("%d",&X);
	fflush(stdin);
	P = Locate(X,L);
	if(P != EndList(L))
		DeleteList(P,L);
	else
		printf("\n Khong ton tai phan tu %d trong list",X);
		
	printf("\nDanh sach sau khi xoa la: \n");
	PrintList(L);
	getch();
}



