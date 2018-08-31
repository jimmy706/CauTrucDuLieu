#include <stdio.h>
#include <conio.h>

#include <D:\ALISTLIB.CPP>



int main(){
	List L;
	MakeNullList(&L);
	printf("\n Danh sach sau khi khoi tao rong la: \n");
	if(EmptyList(L))
		printf("\nDanh sach rong");
	else 
		printf("\nDanh sach ko rong");
	
	for(int i = 1; i<=5;i++)
		InsertList(i+10,EndList(L),&L);
	printf("\n Danh sach sau khi dua cac so tu 11-15 vao la: \n");
	PrintList(L);
	getch();
}
