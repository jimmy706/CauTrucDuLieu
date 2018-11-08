/* 
 - Su dung thu vien danh sach dac voi cac phan tu thuoc kieu so nguyen
 - viet ham int Xoa5(List *L) xoa cac phan tu chia het cho 5 trong danh sach
 - viet ham tangdan(List L) tra ve true neu danh sach tang dan
 - viet chuong trinh nhap danh sach so nguyen tu ban phim, in ra danh sach
*/
#include <stdio.h>
#include <conio.h>
#define MaxLength 100

typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MaxLength];
	Position Last;
}List;

void MakeNullList(List &L){
	L.Last = 0;
}

int EmptyList(List L){
	return L.Last == 0;
}

Position EndList(List L){
	return L.Last + 1;
}

ElementType Retrieve(Position P, List L){
	return L.Elements[P-1];
}

Position Locate(ElementType X, List L){
	if(!EmptyList(L)){
		Position P;
		int Found = 0;
		while((P!=EndList(L))&&(!Found)){
			if(Retrieve(P,L) == X)
				Found = 1;
			else
				P++;
		}
		return P;
	}
}

void InsertList(ElementType X, Position P, List &L){
	if(!(L.Last == MaxLength)){
		for(Position i = L.Last; i >= P; i--){
			L.Elements[i] = L.Elements[i-1];
		}
		L.Last++;
		L.Elements[P-1] = X;
	}
	else
		printf("\nDanh sach day");
}

void DeleteList(Position P, List &L){
	if(!EmptyList(L)){
		for(Position i = P; i < L.Last; i++){
			L.Elements[i-1] = L.Elements[i];
		}
		L.Last--;
	}
}

void Xoa5(List &L){	
	for(Position P = L.Last; P >= 0; P--){
		if(L.Elements[P-1]%5 == 0){
			DeleteList(P,L);
		}
	}
}

int isIncreaseList(List L) {
	int isIncrease = 1;
	Position P = 1;
	
	while((P!=EndList(L))&&(isIncrease)){
		if(L.Elements[P] < L.Elements[P-1])
			isIncrease = 0;
		else
			P++;
	}
	return isIncrease;
}

void ReadList(List &L){
	MakeNullList(L);
	ElementType X;
	printf("\nNhap danh sach, nhan -1 neu muon dung: \n");
	do{
		printf("\n -x%d = ",L.Last);
		scanf("%d",&X);
		if(X!=-1)
			InsertList(X,EndList(L),L);
	}
	while(X!=-1);
}

void PrintList(List L){
	for(Position P = 1; P != EndList(L); P++){
		printf("%3d",Retrieve(P,L));
	}
}



int main(){
	List L;
	ReadList(L);
	printf("\nDanh sach sau khi them cac phan tu: ");
	PrintList(L);
	Xoa5(L);
	printf("\nDanh sach sau xoa cac phan tu chia het cho 5: ");
	PrintList(L);
	
	if(isIncreaseList(L))
		printf("\nDay la danh sach tang dan");
}



