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


void DelSameNode(ElemSN * head)
{
	ElemSN * p,* q;
	q=head;
	p=head->next;
	while(p){
		if(q->date-p->date){
			q=p;
			p=p->next;
		}
		else{
			q->next=p->next;
			free(p);
			p=q->next;
		}
	}
}
int main(void)
{
	int arr[12]={1,2,3,3,4,5,5,7,8,8,9,11}; 
	ElemSN * head;
	head=CreateLinked(arr,12);
	DelSameNode(head);
	PrintLinked(head);
}
