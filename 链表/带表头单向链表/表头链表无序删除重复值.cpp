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
//无序删除法 1-浪费时间换空间 
void DelSameNodeTime(HElemSN * head)
{
	HElemSN * q,* st,* del;
	st=head->next;
	while(st){
		q=st;
		while(q->next){
			if(q->next->date==st->date){
				del=q->next;
				q->next=del->next;
				free(del);
			}
			else{
				q=q->next;
			}
		}
		st=st->next;
	}
}
//无序删除法 2-浪费空间换时间
void DelSameNodeSpace(HElemSN * head)
{
	HElemSN * p,* q,* del;
	int arr[20]={0};
	p=head;
	while(p->next){
		if(!arr[p->next->date]){
			arr[p->next->date]++;
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
	DelSameNodeSpace(head); 
	HPrintLink(head);
}
