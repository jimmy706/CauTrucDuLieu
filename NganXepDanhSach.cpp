#include <stdio.h>
#include <conio.h>
#define MaxLength 100

typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Top;
}Stack;

void MakeNullStack(Stack &s){
	s.Top = MaxLength;
}

int EmptyStack(Stack s){
	return s.Top == MaxLength;
}

int FullStack(Stack s){
	return s.Top == 0;
}

ElementType TopStack(Stack s){
	return s.Elements[s.Top];
}

void Pop(Stack &s){
	if(!EmptyStack(s))
		s.Top++;
}

void Push(ElementType X,Stack &s){
	if(!FullStack(s)){
		s.Top--;
		s.Elements[s.Top] = X;		
	}	
}

void PrintStack(Stack &S){
	while(!EmptyStack(S)){
		printf("%3d",S.Elements[S.Top]);
		Pop(S);
	}
}

void PrintBinary(int n){
	Stack s;
	MakeNullStack(s);
	while(n!=0){
		Push(n%2,s);
		n = n/2;
	}
	PrintStack(s);
}



int main(){
	int n;
	printf("Nhap vao 1 so nguyen:");scanf("%d",&n);
	PrintBinary(n);
	getch();
}
