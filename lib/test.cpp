#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define B 5 /*number of buckets*/
typedef int ElementType;
typedef struct Node{
ElementType Data;
struct Node *next;
};
typedef struct Node *Position;
typedef Position Dictionary[B];
int h(ElementType x){
return x%B;
}
/*create a empty hashtable*/
void MakeNullSet(Dictionary &D){
int i;
for(i=0;i<B;i++)
D[i]=NULL;
}
/*check a memeber if it is in the dictionary*/
int Member(ElementType x, Dictionary D){
Position p;
int found=0;
p=D[h(x)];
while((p!=NULL)&&(!found))
if(p->Data==x)found=1;
else p=p->next;
return found;
}
/*add a member into dictionary*/
void InsertSet(ElementType x, Dictionary &D){
int Bucket;
Position p;
if(!Member(x,D)){
Bucket=h(x);
p=D[Bucket];
D[Bucket]=(Node*)malloc(sizeof(Node));
D[Bucket]->Data=x;
D[Bucket]->next=p;
}
}
/*delete a member from the dictionary*/
void DeleteSet(ElementType x, Dictionary &D){
int Bucket, Done;
Position p,q;
Bucket=h(x);
/*if x is in the header of the list*/
if(D[Bucket]->Data==x){
q=D[Bucket];
D[Bucket]=D[Bucket]->next;
free(q);
}else{/*find x*/
Done=0;
p=D[Bucket];
while((p->next!=NULL)&&(!Done))
if(p->next->Data==x)Done=1;
else p=p->next;
/*x is found*/
if(Done){
/*delete p->next*/
q=p->next;
p->next=q->next;
free(q);
}
}
}void read_hashtable(Dictionary &D){
int x;
printf("Enter a list of integer numbers. -1 to stop.\n");
MakeNullSet(D);
do{ printf("x=");scanf("%d",&x);
if(x!=-1)
InsertSet(x,D);
}while (x!=-1);
}
int main(){
Dictionary D;
int x;
read_hashtable(D);
printf("Enter a number to find it\n");
printf("x=");scanf("%d",&x);
if(Member(x,D))
printf("%d is already in the dictionary.",x);
else printf("%d has not been in the dictionary.",x);
getch();
return 0;
}
