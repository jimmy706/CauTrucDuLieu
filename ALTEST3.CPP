#include<stdio.h>
#include<conio.h>
#include<D:\ALISTLIB.CPP>

int main(){
	List L;
	ElementType X;
	Position P;
	MakeNullList(&L);
	printf("\n\n Nhap danh sach tu ban phim:\n");
	ReadList(&L);
	printf("\n\n Danh sach vua nhap la: \n\n");
	PrintList(L);
	printf("\n Nhap vao phan tu can tim kiem: ");
	scanf("%d",&X);
	P = Locate(X,L);
	if(P==EndList(L))
		printf("\n Khong ton tai phan tu co noi dung %d trong danh sach",X);
	else 
		printf("\nVi tri phan tu dau tien co noi dung %d trong danh sach la: %d",X,P);
}
