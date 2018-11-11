/* 
	Tao danh sach dac chua cac ky tu
	Viet ham nhap danh sach tu ban phim
	Ham sap xep danh sach theo mau tu alphabet ( ko phan biet hoa, thuong)
	Xac danh so phan tu co noi dung X
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MaxLength 100

typedef char ElementType;
typedef int Position;
typedef struct {
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

void Sort(List &L){
	ElementType temp;
	for(int i = 0; i < L.Last; i++){
		for(int j = i + 1; j < L.Last; j++){
			if(tolower(L.Elements[i]) > tolower(L.Elements[j])){
				temp = L.Elements[i];
				L.Elements[i] = L.Elements[j];
				L.Elements[j] = temp;
			}
		}
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

void ReadList(List &L){
	MakeNullList(L);
	ElementType X;
	int n;
	do{
		printf("\nSo phan tu trong danh sach: ");
		scanf("%d",&n);
	}
	while(n<=0);
	
	for(int i = 0; i < n; i++){
		printf("\n -x%d = ",L.Last);
		fflush(stdin);
		scanf("%c",&X);
		InsertList(X,EndList(L),L);
	}
}

void PrintList(List L){
	Position P = 1;
	while(P!=EndList(L)){
		printf("%3c",Retrieve(P,L));
		P++;
	}
}





int main(){
	List L;
	ReadList(L);
	printf("\n Cac phan tu trong danh sach: ");
	PrintList(L);
	
	Sort(L);
	printf("\n Sau khi duoc sap xep: ");
	PrintList(L);
	
 	return 0;
}






