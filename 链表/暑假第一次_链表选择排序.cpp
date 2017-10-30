
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int date;
	struct node * next;
}ElemSN;


ElemSN * PreCreateLink(int a[],int n);
void PrintLink(ElemSN * h);
ElemSN * SortALink(ElemSN * h,int n);


int main(void)
{
	ElemSN * head;
	int a[8]={3,2,4,7,5,8,6,9};
	//??
	head=PreCreateLink(a,8);
	//??
	PrintLink(head);
	//??
	head=SortALink(head,8);
	//??
		PrintLink(head);
	return 0;
}
ElemSN * PreCreateLink(int a[],int n)
{
	ElemSN * p,*h=NULL;
	int i;
	for(i=n-1;i>-1;i--) {
	p=(ElemSN *)malloc(sizeof(ElemSN));
	p->date=a[i];
	p->next=h;
	h=p;
	}
	return h;
}

void PrintLink(ElemSN * h)
{
	ElemSN * p;
	for(p=h;p;p=p->next)
		printf("%5d",p->date);
	printf("\n");
}

ElemSN * SortALink(ElemSN * h,int n)
{
	ElemSN *p,* q,*q2,*pmin;
	for(p=h;p->next;q=p,p=p->next)
		for(q2=p;q2->next;q2=q2->next)
		{
			if(p->date>q2->next->date) {
			pmin=q2->next;
			q2->next=pmin->next;
			pmin->next=p;
			
			
			if(p==h)
			p=h=pmin;
			
			else
			q->next=p=pmin;
			}
		}

	

	return h;
}


