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
	printf("\n\n Nhap noi dung phan tu can xoa: ");
	scanf("%d",&X);
	P = Locate(X,L);
	if(P == EndList(L)){
		printf("\n\n Ko co phan tu %d trong danh sach",X);
	}
	else{
		DeleteList(P,&L);
	}
	printf("\n\n Dnh sach sau khi xoa phan tu dau tien co noi dung %d la: \n\n",X);
	PrintList(L);
	getch();
}
