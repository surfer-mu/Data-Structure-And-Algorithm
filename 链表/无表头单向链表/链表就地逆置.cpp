#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int date;
	struct node * next;
}ElemSN; 

ElemSN * PreCreateLink(int arr[],int n)
{
	ElemSN * p,* q,*head=NULL;
	for(int i=n-1;i>-1;i--){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->date=arr[i];
		p->next=head;
		head=p;
	}
	return head;
}

void PrintLinked(ElemSN * head)
{
	ElemSN * p;
	for(p=head;p;p=p->next)
		printf("%5d",p->date);
}

ElemSN * PreLink1(ElemSN * head)
{
	ElemSN * p,*hn=NULL;
	while(head){
		p=head;
		head=head->next;
		p->next=hn;
		hn=p;		
	}
	return hn;
}
//¸Ä½ø°æ 
ElemSN * PreLink2(ElemSN * head)
{
	ElemSN * p,*q; 
	p=head->next;
	q=head;
	while(p){
		q->next=p->next;
		p->next=head;
		head=p;
		p=q->next;
	}
	return head;
}
int main(void)
{
	int arr[12]={1,2,3,4,5,6,7,8,9,10,11,12}; 
	ElemSN * head;
	head=PreCreateLink(arr,12);
	head=PreLink2(head); 
	PrintLinked(head);
}
