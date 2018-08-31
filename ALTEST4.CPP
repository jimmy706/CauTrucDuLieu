#include <stdio.h>
#include <conio.h>
#include <D:\ALISTLIB.CPP>

int main(){
	List L;
	ElementType X;
	Position P;
	MakeNullList(&L);
	ReadList(&L);
	printf("\n Danh sach vua nhap vao la: \n");
	PrintList(L);
	printf("\n Nhap vao noi dung can them: ");
	scanf("%d",&X);
	printf("\n Nhap vao vi tri can them: ");
	scanf("%d",&P);
	InsertList(X,P,&L);
	printf("\n\n Danh sach sau khi them phan tu %d vao vi tri %d la: \n\n",X,P);
	PrintList(L);
	printf("\n Nhap vao vi tri can xoa: ");
	scanf("%d",&P);
	DeleteList(P,&L);
	printf("\n Danh sach sau khi xoa phan tu o vi tri o vi tri %d la: \n",P);
	PrintList(L);
	getch();
}
