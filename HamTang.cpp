/*
	- Nhap danh sach cac so nguyen ko giam tu ban phim
	- viet ham xac dinh so phan tu co noi dung X trong mang voi X la tham so truyen vao
	- ham tro^n 2 danh sach co thu tu tang dan, tao ra 1 danh sach moi van thoa dieu kien tang dan
	- Ham xac dinh so phan tu co trong danh sach
*/
#include <stdio.h>
#include <conio.h>
#define MaxLength 100

typedef struct {
	int Elements[MaxLength];
	int ArrLength;
}Array;
 
void ReadIncreaseArr(Array &arr){
	int element;
	int index = 1;
	
	printf("\nPhan tu dau tien cua mang: ");
	scanf("%d",&arr.Elements[0]);
		
	while(index < arr.ArrLength){
		printf("\n - arr.Elements[%d] = ",index);
		scanf("%d",&arr.Elements[index]);
		if(arr.Elements[index] >= arr.Elements[index - 1])
			index++;
	}
}

void PrintArr(Array arr){
	for(int i = 0; i < arr.ArrLength; i++){
		printf("%3d",arr.Elements[i]);
	}
}

int NumberOfElement(Array arr){
	return arr.ArrLength;
}

int NumberOfElement(int X, Array arr){
	int numb = 0;
	for(int i = 0; i < arr.ArrLength; i++){
		if(arr.Elements[i]==X)
			numb++;
	}
	return numb;
}

void Combine(Array a, Array b, Array &c){
	int indexOfA = 0, indexOfB = 0;
	c.ArrLength = a.ArrLength + b.ArrLength;
	for(int i = 0; i < c.ArrLength; i++){
		if(indexOfA < a.ArrLength && indexOfB < b.ArrLength){			
			if(a.Elements[indexOfA] <= b.Elements[indexOfB]){
				c.Elements[i] = a.Elements[indexOfA];
				indexOfA++;
			}
			else{
				c.Elements[i] = b.Elements[indexOfB];
				indexOfB++;
			}
		}
		else if(indexOfA < a.ArrLength){
			c.Elements[i] = a.Elements[indexOfA];
		}
		else{
			c.Elements[i] = b.Elements[indexOfB];
			indexOfB++;
		}
	}
}
 
 
int main(){
//	Array arr;
//	int X;
//	do{
//		printf("Nhap so phan tu co trong mang: ");
//		scanf("%d",&arr.ArrLength);
//	}
//	while((arr.ArrLength<=0) || (arr.ArrLength > MaxLength));
//	
//	ReadIncreaseArr(arr);
//	
//	printf("\nCac phan tu trong mang: ");
//	PrintArr(arr);
//	
//	printf("\nSo phan tu co  trong mang: %d",NumberOfElement(arr));
//	
//	printf("\nNhap vao phan tu can tim trong mang: ");
//	scanf("%d",&X);
//	printf("So phan tu %d co trong mang la: %d",X,NumberOfElement(X,arr));

	Array a,b,c;
	printf("So phan tu trong A: ");
	scanf("%d",&a.ArrLength);
	ReadIncreaseArr(a);
	printf("Mang A: ");
	PrintArr(a);
	
	printf("\nSo phan tu trong B: ");
	scanf("%d",&b.ArrLength);
	ReadIncreaseArr(b);
	printf("Mang B: ");
	PrintArr(b);
	
	Combine(a,b,c);
	printf("\n Mang sau khi da tron: ");
	PrintArr(c);
	
	return 0;
}
