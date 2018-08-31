#include<stdio.h>
#include<conio.h>
#define Maxlenght 30

typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
}List;

// Tao danh sach rong
void MakeNullList (List *L) {
	L->Last = 0; 
}

//Kiem tra danh sach rong
int EmptyList(List L){
	return (L.Last == 0);
}

//Kiem tra danh sach day
int FullList(List L){
	return (L.Last == Maxlenght);
}

// Tra ve vi tri phan tu dau tien trong danh sach
Position FirstList(List L){
	return 1;
}

//return the last index of array
Position EndList(List L){
	return L.Last+1;
}

//return the next position of P in array L
Position Next(Position P, List L){
	return P + 1;
}

//return the previous position of P in array L
Position Previous(Position P, List L){
	return P - 1;
}

//return index at position P in array L
ElementType Retrieve(Position P, List L){
	return L.Elements[P-1];
}

//Them phan tu X vao vi tri P trong danh sach L
void InsertList(ElementType X, Position P, List *L){
	if(L->Last == Maxlenght){
		printf("\n Danh sach day !!");
	}
	else if( (P<1) || (P>L->Last+1 ) ){
		printf("\n Vi tri ko hop le");
	}
	else{
		for(int i = L->Last; i>=P;i--)
			L->Elements[i] = L->Elements[i-1];
			L->Last++;
			L->Elements[P-1] = X;
	}
}

//delete inedex at position P in array L
void DeleteList(Position P, List *L){
	if((P>L->Last) || (P<1))
		printf("Vi tri khong hop le");
	else 
		if(EmptyList(*L))
			printf("\n Danh sach rong");
	else {
		for(Position i = P; i<L->Last; i++){
			L->Elements[i-1] = L->Elements[i];
		}
		L->Last--;
	}
}

//Print list form screen
void PrintList(List L){
	Position P;
	P = FirstList(L);
	printf("\n Bat dau in danh sach: \n\n");
	while(P != EndList(L)){
		printf(" %d",Retrieve(P,L));
		P = Next(P,L);
	}
	printf("\n\n Ket thuc in danh sach! \n");
}

// Input list form screen
void ReadList(List *L){
	int N;
	ElementType X;
	MakeNullList(L);
	printf("\n Nhap vao so phan tu trong danh sach: ");
	scanf("%d",&N); 
	fflush(stdin);
	for(int i=1;i<=N;i++){
		printf("\n Phan tu thu %d la: ",i);
		scanf("%d",&X);
		fflush(stdin);
		InsertList(X,EndList(*L),L);
	}
}

//Tra ve vi tri dau tien co noi dung X trong danh sach, neu ko thay tra ve EndList
Position Locate(ElementType X, List L){
	Position P;
	int found = 0;
	P = FirstList(L);
	while ( (P!=EndList(L)) && (found ==0) ){
		if(Retrieve(P,L) == X){
			found = 1;
		} 
		else {
			P = Next(P,L);
		}
	} 
	return P;
}



