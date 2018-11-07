/* 
 - Hieu chinh de ngan xep co the luu cac gia tri hex
 - viet ham cho phep nhap 1 so nguyen duong ( neu nhap so am thi phai nhap lai)
 - write function change form decimal to heximal
 - viet ham in ngan xep ra man hinh
*/

#include <stdio.h>
#include <conio.h>
#define MaxLength 30

typedef char ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int TopIndex;
}Stack;

void MakeNullStack(Stack &S){
	S.TopIndex = MaxLength;
}

int FullStack(Stack S){
	return S.TopIndex == 0;
}

int EmptyStack(Stack S){
	return S.TopIndex == MaxLength;
}

void Pop(Stack &s){
	if(!EmptyStack(s))
		s.TopIndex++;
}

void Push(ElementType X,Stack &s){
	if(!FullStack(s)){
		s.TopIndex--;
		s.Elements[s.TopIndex] = X;		
	}	
}

char DecimalToHex(int n){
	switch(n){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
	}
}

// Ham in ngan xep ra man hinh
void PrintStack(Stack &S){
	while(!EmptyStack(S)){
		printf("%3c",S.Elements[S.TopIndex]);
		Pop(S);
	}
}

void PrintHex(int n){
	Stack S;
	MakeNullStack(S);
	ElementType X;
	while(n!=0){
		X = DecimalToHex(n%16);
		Push(X,S);
		n = n/16;
	}
	PrintStack(S);
}

int main(){
	int n;
	do{
		printf("Nhap vao so nguyen khong am: ");
		scanf("%d",&n);		
	}
	while(n<0);
	
	printf("\nChuyen %d tu thap phan sang thap luc phan: ",n);
	PrintHex(n);
}
