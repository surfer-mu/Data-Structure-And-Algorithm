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

ElemSN * DelSingNode(ElemSN * head)
{
	ElemSN * p, * q;
	for(p=head;p;)
	{
		if(p->date%2){
			if(p==head) {
				head=head->next;
			}
			else{
				q->next=p->next;
				free(p);
				p=q->next;
			}
		}
		else{
			q=p;
			p=p->next;
		}
	}
	return head;
}
int main(void)
{
	int arr[12]={50,2,3,3,4,23,5,7,8,8,9,12}; 
	ElemSN * head;
	head=CreateLinked(arr,12);
	head=DelSingNode(head); 
	PrintLinked(head);
}
