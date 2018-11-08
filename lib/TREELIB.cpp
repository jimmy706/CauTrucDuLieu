#include <stdio.h>
#include <conio.h>
#define Maxlength 100
#define NIL -1

//THU VIEN CAY CAI DAT BANG DANH SACH


typedef char DataType;
typedef int Node;
typedef struct {
	DataType Data[Maxlength];
	Node Parent[Maxlength];
	int MaxNode;
}Tree;

void MakeNullTree(Tree &T){
	T.MaxNode = 0;
}

int EmptyTree(Tree T){
	return T.MaxNode == 0;
}

Node Parent(Node n,Tree T){
	if(EmptyTree(T) || (n>T.MaxNode - 1))
		return NIL;
	else
		return T.Parent[n];
}

DataType Label(Node n,Tree T){
	if(!EmptyTree(T)&&(n<=T.MaxNode-1))
		return T.Data[n];
	else 
		return '*';
}

Node Root(Tree T){
	if(!EmptyTree(T))
		return 0;
	else
		return NIL;
}

Node LeftMostChild(Node n,Tree T){
	Node i;
	int found = 0;
	if(n<0)	return NIL;
	i = n+1;
	found = 0;
	while((i<=T.MaxNode-1) && !found)
		if(T.Parent[i] == n) found = 1;
		else i++;
	if(found) return i;
	else return NIL;	
}

Node Rightsibling(Node n,Tree T){
	Node i,parent;
	int found;
	if(n<0)	return NIL;
	parent = T.Parent[n];
	i = n+1;
	found = 0;
	while((i<=T.MaxNode-1)&&!found)
		if(T.Parent[i]==parent) found =1;
		else i++;
	if (found) return i;
	else return NIL;
}

void ReadTree(Tree &T){
	int i;
	MakeNullTree(T);
	do{
		printf("Cay co bao nhieu nut: ");
		scanf("%d",&T.MaxNode);
	}while((T.MaxNode<1) || (T.MaxNode>Maxlength));
	
	printf("Nhap gia tri nut goc:");
	fflush(stdin);
	scanf("%c",&T.Data[0]);
	T.Parent[0]=NIL;
	
	printf("Nhap cac nut con lai:\n");
	for(i=1;i<T.MaxNode;i++){
		printf(" - Cha cua nut %d la: ",i);
		scanf("%d",&T.Parent[i]);
		printf(" - Gia tri cua nut %d la: ",i);
		fflush(stdin);
		scanf("%c",&T.Data[i]);
	}
}

void preorder(Node n,Tree T){
	Node i;
	printf("%3c",Label(n,T));
	i = LeftMostChild(n,T);
	while(i!=NIL){
		preorder(i,T);
		i = Rightsibling(i,T);
	}
}

void inorder(Node n, Tree T){
	Node i;
	i = LeftMostChild(n,T);
	if(i!=NIL)	inorder(i,T);
	printf("%3c",Label(n,T));
	i = Rightsibling(i,T);
	while(i!=NIL){
		inorder(i,T);
		i = Rightsibling(i,T);
	}
}

void postorder(Node n,Tree T){
	Node i;
	i = LeftMostChild(n,T);
	while(i!=NIL){
		postorder(i,T);
		i = Rightsibling(i,T);
	}
	printf("%3c",Label(n,T));
}

main(){
	Tree T;
	printf("Nhap du lieu cho cay tong quat, chua cac ky tu\n");
	ReadTree(T);
	printf("\nDuyet tien tu:");
	preorder(Root(T),T);
	printf("\nDuyet trung tu:");
	inorder(Root(T),T);
	printf("\nDuyet hau tu::");
	postorder(Root(T),T);
	getch();
}
