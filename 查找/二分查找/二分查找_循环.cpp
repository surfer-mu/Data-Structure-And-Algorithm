#include<stdio.h>
int HalfSearch(int arr[],int n,int key)
{
	int start=0,end=n;
	int mid;
	while(start<=end){
		mid=(start+end)/2;
		if(key>arr[mid])
			start=mid+1;
		else if(key<arr[mid])
			end=mid-1;
		else 
			return mid;
			
	}
	return -1;
}
int main(void)
{
	int arr[8]={1,2,3,4,5,6,7,8};
	int index=HalfSearch(arr,8,8);
	printf("%d",index);
}
