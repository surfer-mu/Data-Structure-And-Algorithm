#include<stdio.h>
#include<stdlib.h>
//�ж������Ƿ��л� 
typedef struct node{
	int date;
	struct node * next;
}ElemSN; 
ElemSN * mid;//����ͷ 
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
			
		if(i==n/2){ //�м�ڵ��ַ���� 
			mid=t;
		}
	}
	t->next=mid; //���һ���ڵ�ָ���м�ڵ��γɻ� 
	return head;
}

void PrintLinked(ElemSN * head)
{
	ElemSN * p;
	for(p=head;p;p=p->next)
		printf("%5d",p->date);
	printf("\n");
}
void freeMem(ElemSN *head)
{
	ElemSN * p;
	while(head){
		p=head;
		head=head->next;
		free(p);
	}
}

void Circle(ElemSN *head)
{
	ElemSN *p,*p2;
	for(p=head,p2=head->next;p&&p2&&p2->next&&p2-p;p=p->next,p2=p2->next->next);
	if(p&&p2&&p2->next){
		printf("yes");
	}
	else{
		printf("No");
	}
}

int main(void)
{
	int arr[8]={3,2,8,4,7,6,9,5}; 
	ElemSN * head;
	head=CreateLinked(arr,8);
	//PrintLinked(head); //�л�������� ������ѭ�� 
	Circle(head);
	 //freeMem(head);//�л������ͷ� �����ָ���쳣 
}

