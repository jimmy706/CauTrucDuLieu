/* 
 - Hieu chinh cay tong quat voi du lieu tai moi nut la 1 kieu ky tu
 - viet ham nhap cay tu ban phim voi so nut cho truoc
 - viet ham xac dinh BAC cua nut tren cay (BAC: so nut con cua nut do)
 - viet ham xac dinh so anh em ruot phai cua nut
 - hien thi duyet tien tu, trung tu, hau tu
 - Viet ham Max(Tree T) de tra ve nut co bac lon nhat trong cay
 - Tim so luong nut LA' trong cay
*/

#include <stdio.h>
#include <conio.h>
#define MaxLength 100
#define NIL -1

typedef char DataType;
typedef int Node;
typedef struct {
	DataType Data[MaxLength];
	Node Parent[MaxLength];
	int MaxNode;
}Tree;

void MakeNullTree(Tree &T){
	T.MaxNode = 0;
}

int EmptyTree(Tree T){
	return T.MaxNode == 0;
}

//Ham nhap cay
void ReadTree(Tree &T){
	MakeNullTree(T);
	do{
		printf("Nhap so nut cua cay: ");
		scanf("%d",&T.MaxNode);
	}
	while((T.MaxNode < 0)&&(T.MaxNode > MaxLength));
	
	printf("\nGia tri cua nut goc: ");
	fflush(stdin);
	scanf("%c",&T.Data[0]);
	T.Parent[0] = -1;
	
	for(int i = 1; i < T.MaxNode; i++){
		printf("\n Cha cua nut %d la: ",i);
		fflush(stdin);
		scanf("%d",&T.Parent[i]);
		printf("\n Gia tri cua nut %d la: ",i);
		fflush(stdin);
		scanf("%c",&T.Data[i]);
	}
}

//Tim so bac cua 1 nut
int NumberOfNode(Node n, Tree T){
	int numberOfNode = 0;
	for(int i = 0; i < T.MaxNode; i++){
		if(T.Parent[i] == n)
			numberOfNode++;
	}
	return numberOfNode;
}

int isLeaf(Node n, Tree T){
	if(NumberOfNode(n,T) == 0)
		return 1;
	else
		return 0;
}

//Xac dinh so anh em ruot phai cua 1 nut
int NumberOfRightSibling(Node n, Tree T){
	int numberOfRightSibling;
	for(int i = n + 1; i < T.MaxNode; i++){
		if(T.Parent[i] == T.Parent[n])
				numberOfRightSibling++;
	}
	return numberOfRightSibling;
}

//Ham tra ve nut goc cua cay
Node Root(Tree T){
	if(!EmptyTree(T))
		return 0;
	else
		return NIL;
}

Node RightSibling(Node n, Tree T){
	Node i = n + 1;
	if((i<MaxLength)&&(T.Parent[i] == T.Parent[n]))
		return i;
	else
		return NIL;
}

Node LeftMostChild(Node n,Tree T){
	Node i = n + 1;
	int Found = 0;
	while((i<T.MaxNode)&&(!Found)){
		if(T.Parent[i] == n)
			Found = 1;
		else
			i++;
	}
	
	if(Found)
		return i;
	else
		return NIL;
}

void PreOrder(Node n, Tree T){
	Node c;
	printf("%3c",T.Data[n]);
	c = LeftMostChild(n,T);
	while(c!=NIL){
		PreOrder(c,T);
		c = RightSibling(c,T);
	}
}

void InOrder(Node n, Tree T){
	Node c;
	c = LeftMostChild(n,T);
	if(c!=NIL)
		InOrder(c,T);
		
	printf("%3c",T.Data[n]);
	c = RightSibling(c,T);
	
	while(c!=NIL){
		InOrder(c,T);
		c = RightSibling(c,T);
	}
}

void PosOrder(Node n, Tree T){
	Node c;
	c = LeftMostChild(n,T);
	while(c!=NIL){
		PosOrder(c,T);
		c = RightSibling(c,T);
	}
	printf("%3c",T.Data[n]);
}

//Tim nut co bac lon nhat
Node MaxDegree(Tree T){
	Node MaxNode = 0;//nut co bac cao nhat
	int MaxChildNode = 0;//so nut con ma nut cha co
	for(int i = 1; i < T.MaxNode; i++){
		if(NumberOfNode(T.Parent[i],T) > MaxChildNode){
			MaxChildNode = NumberOfNode(T.Parent[i],T);
			MaxNode = T.Parent[i];
		}
	}
	return MaxNode;
}

int NumberOfLeaf(Tree T){
	int numb = 0;
	for(int i = 0; i < T.MaxNode; i++){
		if(isLeaf(i,T))
			numb++;
	}
	return numb;
}


int main(){
	Tree T;
	Node n;
	printf("Nhap du lieu cho cay tong quat, chua cac ky tu\n");
	ReadTree(T);
	printf("\nDuyet tien tu:");
	PreOrder(Root(T),T);
	printf("\nDuyet trung tu:");
	InOrder(Root(T),T);
	printf("\nDuyet hau tu::");
	PosOrder(Root(T),T);
	
	printf("\nNut co bac lon nhat: %d",MaxDegree(T));
	
	printf("\nSo nut trong la' cay: %d",NumberOfLeaf(T));
	
	printf("\nNhap vao nut can xac dinh so la nut la hay khong: ");
	scanf("%d",&n);	
	if(isLeaf(n,T))
		printf("Nut %d la nut la",n);
	else
		printf("Nut %d ko phai nut la",n);
	
	printf("\nNhap vao nut can xac dinh so bac: ");
	scanf("%d",&n);	
	printf("\n-Bac cua nut %d la: %d", n, NumberOfNode(n,T));
	
	printf("\nNhap vao nut can xac dinh so anh em: ");
	scanf("%d",&n);
	printf("\n-So anh em cua nut %d la: %d", n, NumberOfRightSibling(n,T));
	
	getch();
}
