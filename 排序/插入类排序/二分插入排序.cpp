#include<iostream>
using namespace std;
void halfInsertSort(int arr[],int len)
{
	int i,j,low,high,mid,temp;
	for(i=1;i<len;i++){
		temp=arr[i];
		low=0;
		high=i-1;
		while(low<=high){
			mid=(low+high)/2;
			if(temp<arr[mid]){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		for(j=i-1;j>high;j--){
			arr[j+1]=arr[j];
		}
		arr[high+1]=temp;
	}
}
void printArray(int arr[],int len)
{
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
}
int main(void)
{
	int arr[]={49,38,65,97,26,13,27,49,55,4};
	int len=sizeof(arr)/sizeof(int);
	halfInsertSort(arr,len);
	printArray(arr,len);
	return 0;
}
