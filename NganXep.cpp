#include <D:\STACKLIB.CPP>
#include <stdio.h>
#include <conio.h>
#include <string.h>

//Chuyen tu nhi phan sang thap phan
void PrintBinary(int n){
	Stack S;
	MakeNullStack(&S);
	printf("\n Gia tri cua %d khi chuyen qua he nhi phan la: ",n);
	if(n==0){
		printf("0");
	}
	else{
		while(n!=0){
			Push(n%2,&S);
			n = n/2;
		}
		while(!EmptyStack(S)){
			printf("%3d",Top(S));
			Pop(&S);
		}	
	}
}


//Chuong trinh kiem tra chuoi dau ngoac
/* 
	- Nhap vao 1 chuoi ngoac mo va dong
	- Khoi tao ngan xep rong va bien finish = 0
	- While(Chuoi chua ket thuc) va not finish
	IF(ky tu la ngoac mo){
		dua vao ngan xep
	}
	ELSE IF(la ngoac dong){
		Xoa phan tu khoi ngan xep
	}
	- Neu chuoi ket thuc ma ngan xep rong thi ta co chuoi dung
	- Neu key thuc ma van con phan tu thi chuoi nhoac sai do thieu dau ngoac dong
*/
void BracketTest(){
	char *chuoi;
	Stack S;
	MakeNullStack(&S);
	printf("\nNhap vao chuoi ngoac de kiem tra");
	scanf("%s",chuoi);
	fflush(stdin);
	int i = 0, finish = 0;
	while((i<strlen(chuoi)) && (!finish)){
		if(chuoi[i] == '(')
			Push(1,&S);
		else{
			if(!EmptyStack(S))
				Pop(&S);
			else
				finish = 1;
		}
		i++;	
	}
	if(finish)
		printf("\n\n Chuoi dau ngoac thieu dau ngoac mo");
	else {
		if(EmptyStack(S))
			printf("\n\n Chuoi dau ngoac dung");
		else
			printf("\n\n Chuoi dau ngoac thieu dau ngoac dong");
	}
}

int main(){
	/*
	TODO: Test chuong trinh chuyen tu thap phan sang nhi phan
	
	int n;
	printf("Nhap vao 1 so nguyen ko am: ");
	do{
		scanf("%d",&n);
	}while(n<0);
	
	PrintBinary(n);
	*/
	
	BracketTest();
	
	
	getch();
}
