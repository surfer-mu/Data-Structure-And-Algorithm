#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
	int date;
	struct node * next;
	
}ElemSN;

ElemSN * CreateLink(int arr[],int n)
{
	ElemSN * p,* head=NULL;
	for(int i=n-1;i>-1;i--){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->date=arr[i];
		p->next=head;
		head=p;
	}
	return head;
}

void PrintLink(ElemSN * head)
{
	ElemSN * p;
	for(p=head;p;p=p->next)
	{
		printf("%5d",p->date);
	}
}

ElemSN * MergeLink(ElemSN * h1,ElemSN * h2) 
{
	ElemSN * head=NULL,* p,* t;
	while(h1||h2){
		if(!h2||h1&&h1->date<h2->date){
			p=h1;
			h1=h1->next;
		}
		else{
			p=h2;
			h2=h2->next;
		}
		p->next=NULL;
		if(!head) t=head=p;
		else{
			if(t->date==p->date){
				free(p);
			}
			else{
				//p->next=t->next;   ??
				t=t->next=p;
			}
		}
	}
	return head;
}
int main(void)
{
	int arr1[12]={-1,2,3,3,4,5,7,8,8,9,12,18}; 
	int arr2[8]={0,2,3,4,4,6,9,15};
	ElemSN * h1,*h2,*head;
	h1=CreateLink(arr1,12);
	h2=CreateLink(arr2,8);
	head=MergeLink(h1,h2);
	PrintLink(head);
}
