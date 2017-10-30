#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int date;
	struct node * next;
}ElemSN; 

ElemSN * CreateLinked(int arr[],int n)
{
	int i;
	ElemSN * p,* t,* head=NULL;
	for(i=0;i<n;i++){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->date=arr[i];
		p->next=NULL;
		if(!head)
			t=head=p;
		else
			t=t->next=p;
	}
	return head;
}

void PrintLinked(ElemSN * head)
{
	ElemSN * p;
	for(p=head;p;p=p->next)
		printf("%5d",p->date);
}
void freeMem(ElemSN *head)
{
	ElemSN * p;
	while(head){
		p=head;
		head=head->next;
		free(p);
	}
}
int upNode(ElemSN * head)
{
	ElemSN * p;
	for(p=head;p->next&&p->date<p->next->date;p=p->next);
	return !(p->next);
}
int main(void)
{
	int arr[8]={1,2,3,4,5,6,7,8}; 
	ElemSN * head;
	head=CreateLinked(arr,8);
	PrintLinked(head);

	printf("ÊÇ·ñÉıĞò? %d",upNode(head));
}
