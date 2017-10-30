#include<stdio.h>
#include<stdlib.h>
void Josephus(int * Q,int n,int s)
{
	int i,front=0,real=n;
	while(front-real){
		for(i=0;i<s-1;i++){
			front=(front+1)%(n+1);
			real=(real+1)%(n+1);
			Q[real]=Q[front];
		}
		front=(front+1)%(n+1);
		printf("%5d",Q[front]);
	}
}
int main(void)
{
	int *Q;
	int n,s;
	scanf("%d%d",&n,&s);
	Q=(int *)malloc(sizeof(int)*(n+1));
	for(int i=1;i<n+1;i++){
		Q[i]=i;
	}
	Josephus(Q,n,3);
}
