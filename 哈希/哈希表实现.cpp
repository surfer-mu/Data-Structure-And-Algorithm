#include<stdio.h>
#include<stdlib.h>
#define N 7
typedef struct node{
	int date;
	struct node * next;
}ElemSN;
ElemSN ** CreateHashmap(int Data[],int n)
{
	int i,R;
	ElemSN * p,* t;
	ElemSN ** s;
	s=(ElemSN **)malloc(sizeof(ElemSN *)*N);
	for(i=0;i<N;i++)
		s[i]=NULL;
	for(i=0;i<n;i++){
		p=(ElemSN *)malloc(sizeof(ElemSN));
		p->date=Date[i];
		p->next=NULL;
		R=Data[i]%N;
		t=s[R];
		while(t&&t->next)
		{
			t=t->next;
		}
		if(!t)
			s[R]=p;
		else
			t=t->next=p;
	}
	return s;
}

void PrintHash(ElemSN ** s)
{
	int i;
	for(i=0;i<N;i++)
		for(p=s[];)
}
int main(void)
{
	
	int Data[12]={5,7,9,11,13,14,12,15,18,4,1,3};
	ElemSN **s;
	s=CreateHashmap(Data,12);
	//Êä³öhashmap
	PrintHash(s);		
}
