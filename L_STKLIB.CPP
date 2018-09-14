#include <D:\ALISTLIB.CPP>
typedef List Stack;

void MakeNull_Stack(Stack *S){
	MakeNull_List(S);
}

int Empty_Stack(Stack S){
	return Empty_List(S);
}

int Full_Stack(Stack S){
	return Full_List(S);
}

//Return element at top of stack
ElementType Top(Stack S){
	return Retrieve(First(S),S);
}

//push element into stack
void Push(ElementType X, Stack *S){
	Insert_List(X,First(*S),S);
}

//Delete 1 element form top
void Pop(Stack *S){
	Delete_List(First(*S),S);
}

//Chuyen tu thap phan sang nhi phan
void PrintBinary(int n){
	if(n <0){
		printf("\n Gia tri ko hop le");
	}
	else if(n==0){
		printf("\n0");
	}
	else {
		Stack S;
		MakeNull_Stack(&S);
		while(n!=0){
			Push((n%2),&S);
			n = n/2;
		}
		while(!Empty_Stack(S)){
			printf("\%4d",Top(S));
			Pop(&S);
		}
	}
}


int main(){
	
	/*
	TODO: test chuong trinh chuyen tu thap phan sang nhi phan
	
	int n;
	printf("\nNhap vao 1 so nguyen ko am: ");
	scanf("%d",&n); fflush(stdin);
	PrintBinary(n);
	*/
	getch();
}
