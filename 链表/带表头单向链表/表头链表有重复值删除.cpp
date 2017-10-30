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

void DelNodeSameKey(HElemSN * head,int key)
{
	HElemSN * p,* del;
	p=head;
	while(p->next)
	{
		if(p->next->date-key){
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
	int arr[18]={2,4,7,4,2,5,9,3,4,3,2,8,4,7,6,9,5,4}; 
	HElemSN * head;
	head=HCreateLink(arr,18);
	DelNodeSameKey(head,4);
	HPrintLink(head);
}
