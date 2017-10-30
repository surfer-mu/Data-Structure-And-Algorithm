#include<iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void duisort(int arr[],int end)
{
	int end=len,flag=1,p;
	while(end-1)
	{
		while(1){
			p=end/2;
			flag=0;
			while(p){
				if(arr[2*p]>arr[p])
				{
					swap(arr,2*p,p);
					flag=1;
				}
				if(2*p+1<=end&&arr[p*2+1]>arr[p]){
					swap(arr,p*2+1,p);
					flag=1;
				}
				
				p--;
			}
			if(!flag){
					break;
				}
		}
		swap(arr,1,end);
		end--;
	}
}
int main(void)
{
	int arr[12]={0,3,2,5,8,4,7,6,9,5,5,6};
	duisort(arr,11);
	for(int i=1;i<=11;i++){
		cout<<arr[i]<<" ";
	} 
	return 0;
}
