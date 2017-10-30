#include<stdio.h> 
int FindKey(int arr[],int n,int key)
{
	if(n==0)
		return -1;
	else{
		int k=FindKey(arr,n-1,key);
		if(arr[n-1]==key)
			k=n-1;
		return k;
	} 
}
int main(void)
{
	int arr[8]={3,2,5,8,4,7,6,9};
	int index=FindKey(arr,8,8);
	printf("%d",index);
}
