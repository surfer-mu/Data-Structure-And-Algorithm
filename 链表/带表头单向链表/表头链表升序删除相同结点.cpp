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
//ÉýÐòÉ¾³ý·¨ 
void DelSameUpNode(HElemSN * head)
{
	HElemSN * p,* del;
	p=head->next;
	while(p->next)
	{
		if(p->next->date!=p->date){
			p=p->next;
		}
		else{
			del=p->next;
			p->next=del->next;
			free(del);
		}
	}
}
int main(void)
{
	int arr[10]={1,2,2,3,5,5,5,8,9,9}; 
	HElemSN * head;
	head=HCreateLink(arr,10);
	DelSameUpNode(head); 
	HPrintLink(head);
}
