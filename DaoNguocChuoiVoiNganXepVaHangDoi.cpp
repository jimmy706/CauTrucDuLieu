#include <stdio.h>
#include <conio.h>
#define MaxLength 30
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

void MakeNullQueue(Queue &Q){
	Q.Front = -1;
	Q.Rear = -1;
}

int EmptyQueue(Queue Q){
	return Q.Front == -1;
}

int FullQueue(Queue Q){
	return ((Q.Rear - Q.Front + 1) == MaxLength);
}

void DeQueue(Queue &Q){
	if(Q.Rear == Q.Front)
		MakeNullQueue(Q);
	else
		Q.Front++;
}
/*Them 1 phan tu vao hang*/
void EnQueue(ElementType x, Queue &Q){
	if(!FullQueue(Q)){
		if(EmptyQueue(Q))
			Q.Front = 0;
		if(Q.Rear == MaxLength - 1 ){
			for(int i = Q.Front; i <= Q.Rear; i++)
				Q.Elements[i-Q.Front] = Q.Elements[i];
			Q.Front = 0;
			Q.Rear = Q.Rear - Q.Front;
		}
		Q.Rear++;
		Q.Elements[Q.Rear] = x;
	}		
}

/*Tra ve phan tu dau hang*/
ElementType Front(Queue Q){
	if(!EmptyQueue(Q))
		return Q.Elements[Q.Front];
}


typedef struct{
	ElementType Elements[MaxLength];
	int Top;
}Stack;

void MakeNullStack(Stack &S){
	S.Top = MaxLength;
}

int EmptyStack(Stack S){
	return S.Top == MaxLength;
}

int FullStack(Stack S){
	return S.Top == 0;
}

ElementType TopStack(Stack S){
	if(!EmptyStack(S))
		return S.Elements[S.Top];
}

void Pop(Stack &S){
	if(!EmptyStack(S))
		S.Top++;
}

void Push(ElementType X, Stack &S){
	if(!FullStack(S)){
		S.Top--;
		S.Elements[S.Top] = X;
	}
}


int main(){
	Stack S;
	Queue Q;
	ElementType x;
	
	/*Tao 1 ngan xep*/
	printf("Nhap vao 1 danh sach so nguyen, -1 de dung:\n");
	MakeNullStack(S);
	do{
		printf("\n -x=");
		fflush(stdin);
		scanf("%d",&x);
		if(x != -1)
			Push(x,S);
	}while(x!=-1);

	MakeNullQueue(Q);
	while(!EmptyStack(S)){
		EnQueue(TopStack(S),Q);
		Pop(S);
	}
	
	while(!EmptyQueue(Q)){
		Push(Front(Q),S);
		DeQueue(Q);
	}
	
	printf("\n Sau khi dao nguoc: ");
	while(!EmptyStack(S)){
		printf("%3d",TopStack(S));
		Pop(S);
	}
	
	getch();
}





