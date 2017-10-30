#include<iostream>
using namespace std;
void shellsort(int arr[],int len)
{
	for(int g=len/2;g>0;g/=2){
		for(int k=0;k<g;k++){
			for(int i=k+g;i<len;i++){
				int temp=arr[i];
				int j=i-g; 
				for(;j>-1&&temp<arr[j];j-=g){
					arr[j+g]=arr[j];	
				}
				arr[j+g]=temp;
			}
		}
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
	shellsort(arr,len);
	printArray(arr,len);
	return 0;
}
