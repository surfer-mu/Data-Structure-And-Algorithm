#include<stdio.h>
void merge(){
		int b[100];
		i=low;j=mid;k=low;
		while(i<mid||j<high){
			if(j==high||(i<mid&&arr[i]<arr[j]))
				b[k++]=arr[i++];
			else
				b[k++]=arr[j++];
		}
		for(k=low;k<high;k++){
			arr[k]=b[k];
		}
}
void MergerSort(int arr[],int low,int high)
{
	int mid,i,j,k;
	
	if(high-low>1){
		mid=(low+high)/2;
		MergerSort(arr,low,mid);
		MergerSort(arr,mid,high);
		merge(arr,low,mid,high);
	}
}
int main(void)
{
	int arr[8]={3,2,5,8,4,7,6,9};
	MergerSort(arr,0,8);
	for(int i=0;i<8;i++)
		printf("%5d",arr[i]);
	
}
