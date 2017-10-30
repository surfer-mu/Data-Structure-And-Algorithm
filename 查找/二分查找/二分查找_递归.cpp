#include<stdio.h>
int HalfSearch(int arr[],int low,int high,int key)
{
	if(low>high)
		return -1;
	else{
		int mid=(low+high)/2;
		int k;
		if(key>arr[mid])
			k=HalfSearch(arr,low+1,high,key);
		else if(key<arr[mid])
			k=HalfSearch(arr,low,high,key);
		else 
			k=mid;
		return k; 
	}
} 
int main(void)
{
	int arr[8]={1,2,3,4,5,6,7,8};
	int index=HalfSearch(arr,0,8,5);
	printf("%d",index);
}
