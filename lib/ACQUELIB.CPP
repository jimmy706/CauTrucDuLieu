#include <stdio.h>
#include <conio.h>
#define MaxLength 100
typedef int ElementType;
typedef struct{
	ElementType Element[MaxLength];
	int Front, Rear;
}Queue;

void MakeNullQueue(Queue *Q){
	Q->Front = -1;
	Q->Rear = -1;
}

int EmptyQueue(Queue Q){
	return Q.Front == -1;
}

int FullQueue(Queue Q){
	return (Q.Rear - Q.Front + 1) % MaxLength == 0;
}

ElementType Front(Queue Q){
	return Q.Element[Q.Front];
}

void DeQueue(Queue *Q){
	if(!EmptyQueue(*Q)){
		if(Q->Front == Q->Rear)
			MakeNullQueue(Q);
		else
			Q->Front = (Q->Front + 1)%MaxLength;
	}
	else
		printf("\n Loi! Hang rong");
}

void EnQueue(ElementType X,Queue *Q){
	if(!FullQueue(*Q)){
		if(EmptyQueue(*Q))
			Q->Front = 0;
		Q->Rear=(Q->Rear+1)%MaxLength;
		Q->Element[Q->Rear]=X;
	}
	else
		printf("\n Loi, hang doi day");
}

void ReadQueue(Queue *Q){
	MakeNullQueue(Q);
	int n;
	ElementType X;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Phan tu thu %d: ",i+1);
		scanf("%d",&X);
		EnQueue(X,Q);
	}
}

void PrintQueue(Queue *Q){
	while(!EmptyQueue(*Q)){
		printf("%5d",Front(*Q));
		DeQueue(Q);
	}
}

int main(){
	Queue Q;
	ReadQueue(&Q);
	printf("\n Xoa 3 phan tu khoi hang: ");
	DeQueue(&Q);
	DeQueue(&Q);
	DeQueue(&Q);
	PrintQueue(&Q);
	printf("\n Them 11,12,13,14 vao hang:");
	for(int i=11;i<=14;i++)
		EnQueue(i,&Q);
	PrintQueue(&Q);
}


