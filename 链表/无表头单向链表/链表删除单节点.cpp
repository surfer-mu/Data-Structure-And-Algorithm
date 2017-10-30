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

ElemSN * DelKeyNode(ElemSN * head,int key)
{
	ElemSN * p,* q;
	for(p=head;p&&p->date-key;q=p,p=p->next);
	if(!p){
		printf("Not Found");
	}
	else{
		if(p==head){
			head=head->next;
		}
		else{
			q->next=p->next;
		}
		free(p);
	}
	return head;
}
int main(void)
{
	int arr[8]={3,2,8,4,7,6,9,5}; 
	ElemSN * head;
	head=CreateLinked(arr,8);
	head=DelKeyNode(head,3); 
	PrintLinked(head);
}
