#include <stdio.h>
#include <conio.h>
#define MaxLength 100
typedef int ElementType;
typedef struct {
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
	return ((Q.Rear - Q.Front + 1) == MaxLength);
}

//Them phan tu vao cuoi hang doi
/* 
	Co 2 truong hop:
	 	- TRUONG HOP BINH THUONG: 
	 	 	+ Them phan tu vao cuoi hang
	 	- TRUONG HOP HANG BI TRAN:
	 		+ Doi tat ca phan tu len Front vi tri, xac dinh lai Front va Rear moi
	 
*/
void EnQueue(ElementType X, Queue *Q){
	if(!FullQueue(*Q)){
		if(EmptyQueue(*Q))
			Q->Front = 0;
		 // Truong hop bi tran
		if(Q->Rear==MaxLength - 1){
			for(int i=Q->Front;i<=Q->Rear;i++){
				Q->Element[i-Q->Front] = Q->Element[i];
			}
			Q->Rear = Q->Rear - Q->Front;
			Q->Front = 0;
		}
		//Tang Rear de luu gia tri moi
		Q->Rear = Q->Rear+1;
		Q->Element[Q->Rear] = X;
	}
	else
		printf("\n Loi, hang day!!");
}

//Xoa phan tu dau hang doi
void DeQueue(Queue *Q){
	if(!EmptyQueue(*Q)){
		if(Q->Front == Q->Rear)
			MakeNullQueue(Q);
		else 
			Q->Front++;
	}
	else
		printf("\n Loi, hang rong");
}

//Lay noi dung dau cua hang doi
ElementType Front(Queue Q){
	return Q.Element[Q.Front];
}


void ReadQueue(Queue *Q){
	MakeNullQueue(Q);
	ElementType X;
	int i;
	printf("\n Nhap danh sach hang doi vao, nhan -1 de ket thuc:\n");
	do{
		i++;
		printf("\n -x%d = ",i);
		scanf("%d",&X);
		if(X!=-1)
			EnQueue(X,Q);
	}
	while(X!=-1 && !FullQueue(*Q));
}

void PrintQueue(Queue *Q){
	printf("\n Danh sach hang doi:\n");
	while(!EmptyQueue(*Q)){
		printf("%5d",Front(*Q));
		DeQueue(Q);
	}
}

//Test

//int main(){
//	Queue Q;
//	ReadQueue(&Q);
//	printf("\n Xoa 3 phan tu khoi hang: ");
//	DeQueue(&Q);
//	DeQueue(&Q);
//	DeQueue(&Q);
//	PrintQueue(&Q);
//	printf("\n Them 11,12,13,14 vao hang:");
//	for(int i=11;i<=14;i++)
//		EnQueue(i,&Q);
//	PrintQueue(&Q);
//}

