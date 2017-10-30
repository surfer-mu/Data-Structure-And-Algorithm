#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int date;
	struct node * next;
}ElemSN; 

ElemSN * PreCreateLink(int arr[],int n)
{
	ElemSN * p,* q,*head=NULL;
	for(int i=n-1;i>-1;i--){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->date=arr[i];
		p->next=head;
		head=p;
	}
	return head;
}

void PrintLinked(ElemSN * head)
{
	ElemSN * p;
	for(p=head;p;p=p->next)
		printf("%5d",p->date);
}
void FreeLink(ElemSN * head)
{
	ElemSN * p;
	while(head){
		p=head;
		head=head->next;
		free(p);
	}
}
int main(void)
{
	int arr[12]={50,2,3,3,4,23,5,7,8,8,9,12}; 
	ElemSN * head;
	head=PreCreateLink(arr,12);
	FreeLink(head);
	PrintLinked(head);
}
