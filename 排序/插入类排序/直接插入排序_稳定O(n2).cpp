#include<stdio.h>
int main(void)
{
	int i,j,x; 
	int arr[8]={3,2,5,8,4,7,6,9};
	for(i=1;i<8;i++)
	{
		x=arr[i];
		for(j=i-1;j>-1&&arr[j]>x;arr[j+1]=arr[j],j--);
			arr[j+1]=x;
	}
	for(i=0;i<8;i++)
		printf("%5d",arr[i]);
		
}
