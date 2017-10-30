
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int date;
	struct node * next;
}ElemSN;


ElemSN * PreCreateLink(int a[],int n);
void PrintLink(ElemSN * h);
ElemSN * SortALink(ElemSN * h);


int main(void)
{
	ElemSN * head;
	int a[]={3,2,4,7,5,8,6,9};
	//??
	head=PreCreateLink(a,a.length);
	//??
	PrintLink(head);
	//??
	head=SortALink(head);
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

ElemSN * SortALink(ElemSN * h)
{
	ElemSN *p,* q;
	q=h;
	p=h->next;

	while(p) {	
		if(q->date>p->date) {
		q->next=p->next;
		p->next=h;
		q=h=p;
		p=h->next;

		}
		else {
		q=p;
		p=q->next;
		}
		
	}
	return h;
}


