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

int Addodd(ElemSN *head)
{
	int count=0;
	ElemSN * p;
	for(p=head;p;p=p->next)
	{
		count+=p->date%2;
	}
	return count;
}

int main(void)
{
	int arr[8]={3,2,8,4,7,6,9,5}; 
	ElemSN * head;
	head=CreateLinked(arr,8);
	PrintLinked(head);
	printf("\n%d\n",Addodd(head));
}
