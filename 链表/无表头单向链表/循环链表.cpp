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
ElemSN * DelLink(ElemSN *head,int key)
{
	ElemSN *p,*q;
	q=NULL;
	p=head;
	do{
		if(p->date-key){
			q=p;
			p=p->next;
		}
		else{
			break;
		}
	}while(p!=head);
	
	if(p==head&&q){
		printf("Not Found\n");
	}
	else{
		if(p==head){
			for(q=head;q->next!=head;q=q->next);
			head=head->next;
		}
		q->next=p->next;
		free(p);
	}	
	return head;
}
int main(void)
{
	int arr[8]={1,2,3,4,5,6,7,8}; 
	ElemSN * head;
	head=CreateCircleLink(arr,8);
	DelLink(head,1);
	PrintCircleLink(head);
}
