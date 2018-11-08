#include <stdio.h>

#define Maxlength 100

typedef int ElementType;
// typedef float ElementType
//typedef int ElementType;
typedef struct {
	ElementType Elements[Maxlength];
	int TopIndex;
}Stack;

//Create null stack
void MakeNullStack(Stack *S){
	 S->TopIndex = Maxlength;
}

//Check empty list
int EmptyStack(Stack S){
	return (S.TopIndex == Maxlength);
}

//Check full list
int FullStack(Stack S){
	return (S.TopIndex == 0);
}

//Return element at top of stack
ElementType Top(Stack S){
	if(EmptyStack(S)){
		printf("\nNgan xep rong!!");
		return NULL;	
	}
	else{
		return S.Elements[S.TopIndex];
	}
}

//Add element into stack
void Push(ElementType X,Stack *S){
	if(FullStack(*S)){
		printf("\nLoi!! Danh sach rong");
	}
	else{
		S->TopIndex--;
		S->Elements[S->TopIndex] = X;
	}
}

//Delete top element 
void Pop(Stack *S){
	if(EmptyStack(*S)){
		printf("\nNgan xep rong");
	}
	else{
		S->TopIndex++;
	}
}

void ReadStack(Stack *S){
	int i=0;
	ElementType X;
	MakeNullStack(S);
	printf("Nhap vao cac phan tu cho ngan xep, nhan -1 de ket thuc:\n");
	do{
		printf("\n -x%d = ",i+1);
		scanf("%d",&X);
		if(X!=-1)
			Push(X,S);
	}
	while(X!=-1 && !FullStack(*S));
}

void PrintStack(Stack *S){
	printf("\n Danh sach ngan xep: \n");
	while(!EmptyStack(*S)){
		printf("%5d",Top(*S));
		Pop(S);
	}	
}

//int main(){
//	Stack S;
//	ReadStack(&S);
//	PrintStack(&S);
//}

