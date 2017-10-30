#include<stdio.h>
void MergeSort(int Data[],int low,int high)
{
	int i,j,k,b[100],mid;
	if(high-low>1){
		mid=(high+low)/2;
		MergeSort(Data,low,mid);
		MergeSort(Data,mid,high);
		i=low;
		j=mid;
		k=low;
		while(i<mid||j<high){
			if(j==high||(i<mid&&Data[i]<Data[j]))
				b[k++]=Data[i++];
			else
				b[k++]=Data[j++];
		}
		for(i=low;i<high;i++){
			Data[i]=b[i];
		}
	}
}
int main(void)
{
	int Data[8]={3,2,4,7,5,8,6,9};
	MergeSort(Data,0,8);
	for(int i=0;i<8;i++)
	{
		printf("%5d",Data[i]);
	}
}
