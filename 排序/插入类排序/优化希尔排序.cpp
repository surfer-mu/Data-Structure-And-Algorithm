#include<iostream>
using namespace std;
void shellSort(int arr[],int len)
{
	int g,i,j,temp;
	for(g=len/2;g>0;g/=2){
		for(i=g;i<len;i++){
			temp=arr[i];
			for(j=i-g;j>-1&&temp<arr[j];j-=g){
				arr[j+g]=arr[j]; 
			}
			arr[j+g]=temp;
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
	shellSort(arr,len);
	printArray(arr,len);
	return 0;
}
