#include<stdio.h>
#define N 15
//查找所有key，并将key替换为setkey
void find(int arr[],int key,int setkey)
{
	int i;
	for(int i=2;i<N&&(arr[i]-key||(arr[i]=setkey,1));i++);
	//加数字 1 是防止seykey为0	
} 
int main(void)
{
	int arr[N]={3,2,8,3,2,5,8,4,7,8,6,9,5,8,8};
	int i;
	int key=8;
	find(arr,8,2);
	for(int i=0;i<N;i++)
		printf("%5d",arr[i]);
}
