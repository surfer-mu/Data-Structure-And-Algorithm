#include<stdio.h>
int FindKey(int arr[],int n,int key)
{
	int i;
	for(i=n-1;i>-1&&arr[i]-key;i--);
	return i;	
}
int main(void)
{
	int arr[8]={3,2,5,8,4,7,6,9};
	int index=FindKey(arr,8,10);
	printf("%d",index);
}
