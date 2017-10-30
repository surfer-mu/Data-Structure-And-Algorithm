#include<stdio.h>
int main(void)
{
	int arr[12]={1,1,2,1,2,1,2,2,2,1,2,2};
	int i=0,j=12-1;
	int low=0,high=12-1;
	if(high-low>1){
		while(i<j){
			for(i=0;i<high&&arr[i]==1;i++);
			for(;j>-1&&arr[j]==2;j--);
			if(i<j)
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
		for(i=0;i<12;i++)
	{
		printf("%5d",arr[i]);
	}	
}
