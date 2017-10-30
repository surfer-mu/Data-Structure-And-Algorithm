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

void Queue()
{
	int i,j;
	i=0;j=0;
	for(i=0;i<8;)
	{
		for(;j<8;j++)
		{
			if((!left[i+j])&&(!right[i-j+7])&&(!cal[j]))
				break;
		}
		if(i==0&&j==8)
		{
			break;
		}
		
		if(j<8){
			left[i+j]=right[i-j+7]=cal[j]=1;
			Q[++top]=j;
			if(i<7){
				i++;
				j=0;
				
			}		
			else{
				printf("第%d个皇后方案\n",++count);
				PrintQueue();
				
				left[i+j]=right[i-j+7]=cal[j]=0;
				--top;
				j++;
			}	
		}
		else{
			i=top;
			j=Q[top]; 
			left[i+j]=right[i-j+7]=cal[j]=0;
			--top;
			j++; 
		}
	}
		
}

int main(void)
{
	Queue();
}
