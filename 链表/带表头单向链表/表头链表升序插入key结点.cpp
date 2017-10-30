#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int date;
	struct node * next;
}HElemSN;

HElemSN * HCreateLink(int arr[],int n)
{
	HElemSN * t,* head;
	t=head=(HElemSN *)malloc(sizeof(HElemSN));
	head->next=NULL;
	for(int i=0;i<n;i++){
		t=t->next=(HElemSN *)malloc(sizeof(HElemSN));
		t->date=arr[i];
		t->next=NULL;
	}
	return head;
}
void HPrintLink(HElemSN * head)
{
	HElemSN * p;
	for(p=head->next;p;p=p->next){
		printf("%5d",p->date);
	}
}
void InsertNode(HElemSN * head,HElemSN *Ins)
{
	HElemSN * p,* q;
	for(p=head;p->next&&p->next->date<Ins->date;p=p->next);
	if(!p->next)
		printf("Not Found");
	else{
		Ins->next=p->next;
		p->next=Ins;
	}
} 
int main(void)
{
	int arr[8]={1,2,3,4,6,7,8,79}; 
	
	HElemSN * head,* t;
	t=(HElemSN *)malloc(sizeof(HElemSN));
		t->date=5;
		t->next=NULL;
	head=HCreateLink(arr,8);
	InsertNode(head,t);
	HPrintLink(head);
}
