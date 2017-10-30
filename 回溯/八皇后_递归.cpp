#include<stdio.h>
int left[15]={0};
int right[15]={0};
int cal[8]={0};
int top=-1;
int count=0;
int Q[8];

void PrintQueue()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(Q[i]==j)
				printf(" Q");
			else
				printf(" X");
		}
		printf("\n");
	}
}
void Queue(int i)
{
	
	for(int j=0;j<8;j++)
	{
		if((!left[i+j])&&(!right[i-j+7])&&(!cal[j]))
		{
			left[i+j]=right[i-j+7]=cal[j]=1;
			Q[++top]=j;
			if(top<7)
			{
				Queue(i+1);
			}
			else
			{
				printf("第%d个皇后方案\n",++count);
				PrintQueue();
			}
			left[i+j]=right[i-j+7]=cal[j]=0;
			top--;
			
		}
	}
}
int main(void)
{
	Queue(0);
}
