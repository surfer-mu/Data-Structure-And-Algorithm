#include<stdio.h>
#define N 8
#define M 10
/*
	��Date1��Date2Ϊ�����������м����Ҳ����ظ�ֵ������������ϲ�Ϊһ���������� 
*/ 
int main(void)
{
	int i=0,j=0,k=0;
	int Date1[N]={3,4,5,8,13,21,47,89};
	int Date2[M]={3,5,6,7,14,21,29,47,60,61};
	int Date[M+N];
	while(i<N||j<M){
		if(j>=M||(i<N&&Date1[i]<=Date2[j])){
				//ȥ���ظ�ֵ 
//				if(Date1[i]==Date2[j]) {
//					j++; 
//				}	
			Date[k++]=Date1[i++];
	
		}
		else{
			Date[k++]=Date2[j++];
		}
	}
	for(i=0;i<k;i++){
		printf("%5d",Date[i]);
	}
}
