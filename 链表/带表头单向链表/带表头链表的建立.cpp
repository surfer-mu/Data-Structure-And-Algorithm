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
void HfreeMem(HElemSN * head)
{
	HElemSN * p;
	while(head->next){
		p=head->next;
		head->next=head->next->next;
		free(p);
	}
}
int main(void)
{
	int arr[8]={3,2,8,4,7,6,9,5}; 
	HElemSN * head;
	head=HCreateLink(arr,8);
	HPrintLink(head);
	HfreeMem(head);
}
