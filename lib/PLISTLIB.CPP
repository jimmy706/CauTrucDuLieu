#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef int ElementType;
typedef struct Node{
	ElementType Element;
	Node* Next;
};
typedef Node* Position;
typedef Position List;

//Create a null list
void MakeNullList(List *Header){
	(*Header) = (Node*)malloc(sizeof(Node));
	(*Header)->Next = NULL;
}

//Check empty list
int EmptyList(List L){
	return (L->Next == NULL) ;
}

// return the first position in list
Position First(List L){
	return L;
} 

//return the last position in list
Position End(List L){
	Position P;
	P = First(L);
	while(P->Next != NULL)
		P = P->Next;
	return P;	
}

//retrieve 1 element at position P in list L
ElementType Retrieve(Position P,List L){
	return P->Next->Element;
}

//Insert element X at position P in list L
void InsertList(ElementType X,Position P,List *L){
	Position T;
	T = (Node*)malloc(sizeof(Node));
	T->Element = X;
	T->Next = P->Next;
	P->Next = T;
}
//Delete element at position P in lsit L
void DeleteList(Position P,List *L){
	Position T;
	if(EmptyList(*L)){
		printf("\nError! List is empty now");
	}
	else{
		T = P->Next;
		P->Next = T->Next;
		free(T);
	}
}
//Return the first position of element that match X in list L, if not,return End
Position Locate(ElementType X,List L){
	bool found = false;
	Position P;
	while ( (P->Next != NULL) && (!found) ){
		if(Retrieve(P,L) == X)
			found = true;
		else
			P = P->Next;
	}
	return P;
}

//Create list form screen
void ReadList(List *L){
	int N,T;
	ElementType X;
	Position P;
	P = First(*L);
	printf("\nNumber of element in list: ");
	scanf("%d",&N);
	for(int i = 1;i<=N;i++){
		printf("\n Element number %d: ",i);
		scanf("%d",&X);
		InsertList(X,End(*L),L);
	}
}

//Print list
void PrintList(List L){
	Position P;
	P = First(L);
	printf("\n Printing...:\n");
	while(P!=(End(L))){
		printf("\t%d",Retrieve(P,L));
		P = P->Next;
	}
}






