#include<stdio.h>
/*
删除数组元素（无重复值）
*/ 
int DelKey(int arr[],int n,int key)
{
	int i,j;
	for(i=0;i<n&&arr[i]-key;i++);
	if(i==n) printf("未找到");
	else
	{
		for(j=i;j<n-1;j++){
			arr[j]=arr[j+1];
		}
		n--;
	}
	return n;
}
/*
删除数组元素（有重复值）
*/ 
int ReDelKey(int arr[],int n,int key)
{
	int i=0,j;
	while(i<n){
		if(arr[i]-key){
			i++;
		}
		else{
			for(j=i;j<n-1;j++){
				arr[j]=arr[j+1];
			}
			n--;
		}
	}
	return n;
} 
 
int main(void)
{
	int i,j;
	int key=24;
	int arr[8]={3,4,5,8,13,5,3,24};
	int n;
	n=ReDelKey(arr,8,key);
	for(j=0;j<n;j++){
		printf("%5d",arr[j]);
	}
	
}
