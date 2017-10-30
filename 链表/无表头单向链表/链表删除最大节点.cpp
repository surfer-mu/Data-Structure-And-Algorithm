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

ElemSN * DelMaxNode(ElemSN * head)
{
	ElemSN  *pm,* qm,* p,* q;
	pm=q=head;
	p=head->next;
	while(p){
		if(p->date>pm->date){
			pm=p;
			qm=q;
		}
		else{
			q=p;
			p=p->next;
		}
	}
	if(pm==head)
		head=head->next;
	else{
		qm->next=pm->next;
		free(pm);
	}
	return head;
}
int main(void)
{
	int arr[12]={50,2,3,3,4,23,5,7,8,8,9,11}; 
	ElemSN * head;
	head=CreateLinked(arr,12);
	head=DelMaxNode(head);
	PrintLinked(head);
}
