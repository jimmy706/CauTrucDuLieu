#include <stdio.h>
#include <conio.h>
#include <D:\ALISTLIB.CPP>

int main(){
	List L;
	MakeNullList(&L);
	printf("\n Nhap danh sach tu ban phim");
	ReadList(&L);
	printf("\n Danh sach vua nhap vao la: \n");
	PrintList(L);
	getch();
}
