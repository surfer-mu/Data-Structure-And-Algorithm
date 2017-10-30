#include<stdio.h>
#define N 8
int find(int a[],int key)
{	int i;
	for(i=0;i<N&&a[i]-8;i++);
	if(i<N) return i;
	else    return -1; 	
}
int main(void)
{
	int n;
	int arr[N]={3,2,5,8,4,7,6,9};
	n=find(arr,8);
	printf("%d\n",arr[n]);  
}
	
	 
