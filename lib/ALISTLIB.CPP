#include<stdio.h>
#include<conio.h>
#define Maxlength 30

typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlength];
	Position Last;
}List;

// Create empty list
void MakeNullList (List *L) {
	L->Last = 0; 
}

//Test empty lsit
int EmptyList(List L){
	return (L.Last == 0);
}

//Test full list
int FullList(List L){
	return (L.Last == Maxlength);
}

// return the first position in list
Position FirstList(List L){
	return 1;
}

//return the last position in list
Position EndList(List L){
	return L.Last+1;
}

//return the next position of P in list L
Position Next(Position P, List L){
	return P + 1;
}

//return the previous position of P in list L
Position Previous(Position P, List L){
	return P - 1;
}

//return index at position P in list L
ElementType Retrieve(Position P, List L){
	return L.Elements[P-1];
}

//Add elment X at position P in list L
void InsertList(ElementType X, Position P, List *L){
	if(L->Last == Maxlength){
		printf("\n List is full now!!");
	}
	else if( (P<1) || (P>L->Last+1 ) ){
		printf("\n Wrong position!!");
	}
	else{
		for(int i = L->Last; i>=P;i--){
			L->Elements[i] = L->Elements[i-1];
		}
			L->Last++;
			L->Elements[P-1] = X;
	}
}

//Delete element at position P in list L
void DeleteList(Position P, List *L){
	if((P>L->Last) || (P<1))
		printf("\n Wrong position!!");
	else 
		if(EmptyList(*L))
			printf("\n Empty list!!");
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
	printf("\nPrinting...: \n\n");
	while(P != EndList(L)){
		printf(" %d",Retrieve(P,L));
		P = Next(P,L);
	}
	printf("\n\nPrint success!");
}

// Type list form screen
void ReadList(List *L){
	int N=0;
	ElementType X;
	MakeNullList(L);
	while(N>Maxlength || N<1){
		printf("\nType the number of element in list: ");
		scanf("%d",&N); 
	}
	fflush(stdin);
	for(int i=1;i<=N;i++){
		printf("\n Elment number %d: ",i);
		scanf("\t%d",&X);
		fflush(stdin);
		InsertList(X,EndList(*L),L);
	}
}

//Return the first position of element that match X in list L, if not,return EndList
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

