#include<stdio.h>
void QuickSort(int arr[],int low,int high)
{
	int i=low+1,j=high-1;
	int tag=low;
	int temp;
	if(high-low>1)
	{
		while(i<=j){
			for(;i<high&&arr[i]<arr[tag];i++);
			for(;j>low&&arr[j]>=arr[tag];j--);
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	} 
	if(j>low){
			temp=arr[low];
			arr[low]=arr[j];
			arr[j]=temp;	
	}	
	if(j-low>1)
		QuickSort(arr,low,j);
	if(high-(j+1)>1)
		QuickSort(arr,j+1,high);
}
int main(void)
{
	int arr[8]={3,5,5,10,5,5,5,6};
	QuickSort(arr,0,8);
	for(int i=0;i<8;i++)
	{
		printf("%5d",arr[i]);
	}	
} 
