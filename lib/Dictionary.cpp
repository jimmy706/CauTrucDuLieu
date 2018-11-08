#include <stdio.h>
#include <conio.h>
#define MaxLength 100
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Data[MaxLength];
	Position Last;
}Dict;

void MakeNullDict(Dict &D){
	D.Last = 0;
}

int EmptyDict(Dict D){
	return D.Last == 0;
}

int FullDict(Dict D){
	return D.Last == MaxLength;
}

int Member(ElementType X, Dict D){
	Position P = 1;
	int Found = 0;
	while((P<=D.Last)&&(!Found)){
		if(D.Data[P-1]==X)
			Found = 1;
		else
			P++;
	}
	return Found;
}

void InsertDict(ElementType X, Dict &D){
	if (!Member(X , D)) {
		D.Last++;
		D.Data[D.Last-1]=X;
	}else
	printf("\nPhan tu da ton tai trong tu dien");
}

void DeleteDict(ElementType X, Dict &D){
	Position P;
	int Found = 0;
	while((P<=MaxLength)&&(!Found)){
		if(D.Data[P-1]==X)
			Found = 1;
		else
			P++;
	}
	
	if(Found){
		D.Data[P-1] = D.Data[D.Last - 1];
		D.Last--;
	}
	else
		printf("\n khong tim thay phan tu");
}

void ReadDict(Dict &D){
	ElementType X;
	printf("Nhap cac phan tu trong tu dien, -1 de ket thuc: ");
	do{
		printf("\n -x =  ");
		fflush(stdin);
		scanf("%d",&X);
		if(X != -1)
			InsertDict(X,D);
	}
	while(X!=-1);
}

void PrintDict(Dict D){
	Position P = 1;
	while(P <= D.Last){
		printf("%3d",D.Data[P-1]);
		P++;
	}
		
}


int main(){
	Dict D;
	ElementType x;
	MakeNullDict(D);	
	ReadDict(D);
	printf("\n Tu dien sau khi duoc them: ");
	PrintDict(D);
	printf("\n Phan tu can xoa: ");
	scanf("%d",&x);
	DeleteDict(x,D);
	printf("\n Sau khi xoa phan tu: ");
	PrintDict(D);
	getch();
	return 0;
}
