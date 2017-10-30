#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int date;
	struct node * next;
}ElemSN;

ElemSN * CreateCircleLink(int arr[],int n)
{
	ElemSN * p,* t,* head=NULL;
	for(int i=0;i<n;i++)
	{
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->date=arr[i];
		if(!head){
			p->next=p;
			t=head=p;
		}
		else{
			t=t->next=p;
			p->next=head;
		}
	}
	return head;
}

void PrintCircleLink(ElemSN * head)
{
	ElemSN * p;
	p=head;
	do{
		printf("%5d",p->date);
		p=p->next;
	}while(p!=head);
}
void Tostphus(ElemSN * head)
{
	ElemSN *p,* q;
	p=head;
	int count=0;
	while(p->next-p){
		if(count==2){
			q->next=p->next;
			printf("%5d",p->date);
			free(p);
			p=q->next;
			count=0;
		}
		else{
			q=p;
			p=p->next;
			count++;
		}
	}
	
}
int main(void)
{
	int arr[11]={1,2,3,4,5,6,7,8,9,10,11}; 
	ElemSN * head;
	head=CreateCircleLink(arr,11);
	Tostphus(head);
	PrintCircleLink(head);
}
