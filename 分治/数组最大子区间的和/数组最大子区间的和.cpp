#include<stdio.h> 
int SubRange(int a[],int low,int high)
{
	if(high-low==1)
		return a[low];
	else{
		int mid,i,sum,maxl,maxr,ml,mr;
		mid=(low+high)/2;
		ml=SubRange(a,low,mid);
		mr=SubRange(a,mid,high);
		if(mr>ml)
			ml=mr;
		sum=0;
		maxl=a[mid-1];
		for(i=mid-1;i>=low;i--){
			sum+=a[i];
			if(sum>maxl)
				maxl=sum;
		}
		sum=0;
		maxr=a[mid];
		for(i=mid;i<high;i++){
			sum+=a[i];
			if(sum>maxr)
				maxr=sum;
		}
		
		maxl+=maxr;
		return maxl>ml?maxl:ml;
	}
}
int main(void)
{
	int a[7]={3,-2,5,-8,4,-7,1};
	int max;
	max=SubRange(a,0,7);
	printf("最大子区间的和：sub-range=%d",max);
}
