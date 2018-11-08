//THU VIEN TAP HOP TAO BANG VECTO BIT
#include <stdio.h>
#include <conio.h>
#define MaxLength 100

typedef int Set [MaxLength]; // Tao tap rong

void MakeNullSet(Set &a){
	for(int i = 0; i< MaxLength; i++) a[i] = 0;
}

int EmptySet(Set a){
	int isEmpty = 1, i;
	while(isEmpty && i<MaxLength){
		if( a[i] == 1 ) isEmpty = 0;
		else i++;
	}
	return isEmpty;
}

void Union(Set a, Set b, Set &c){
	for(int i = 0; i<MaxLength; i++)
		c[i] = ((a[i] == 1) || (b[i] == 1));
}

void Intersection(Set a, Set b, Set &c){
	for(int i = 0; i<MaxLength; i++)
		c[i] = ((a[i] == 1) && (b[i] == 1));
}

void Difference(Set a, Set b, Set &c){
	for(int i = 0; i<MaxLength; i++)
		c[i] = ((a[i] == 1) && (b[i] == 0));
}

int Member(int i, Set a){
	if((i<0) || i > MaxLength - 1)	
		return 0;
	else	
		return a[i] == 1;
}

void InsertSet(int i, Set &a){
	if( (i > MaxLength -1 ) || (i < 0))
		printf("\nKhong hop le!!");
	else
		a[i] = 1;
}

void ReadSet(Set &a){
	int n,x;
	do{
		printf("\nSo phan tu co trong tap hop: ");
		scanf("%d",&n);
	}
	while(n > MaxLength - 1 && n < 0);
	
	for(int i = 0; i < n; i++){
		printf("\n Phan tu thu %d la: ", i);
		scanf("%d",&x);
		InsertSet(x,a);
	}
}

void PrintSet(Set a){
	for(int i = 0; i<MaxLength;i++){
		if(a[i] == 1)	printf("\t%d",i);
	}
}

//TEST CHUONG TRINH
//int main(){
//	Set a,b,c;
//	MakeNullSet(a);
//	MakeNullSet(b);
//	MakeNullSet(c);
//	
//	printf("\nNhap cac tap hop cua a: ");
//	ReadSet(a);
//	printf("\n Tap hop cua a: ");
//	PrintSet(a);
//	
//	printf("\nNhap cac tap hop cua b: ");
//	ReadSet(b);
//	printf("\n Tap hop cua b: ");
//	PrintSet(b);
//	
//	Union(a,b,c);
//	printf("\n Hop cua a va b: ");
//	PrintSet(c);
//	
//	Intersection(a,b,c);
//	printf("\n Giao cua a va b: ");
//	PrintSet(c);
//	
//	Difference(a,b,c);
//	printf("\n Hieu cua a va b: ");
//	PrintSet(c);
//}




