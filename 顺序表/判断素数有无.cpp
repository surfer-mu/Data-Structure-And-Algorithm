#include<stdio.h>
int main(void)
{
	int x=29;//���жϵ���
	int i;
	for(i=2;i<x&&x%i;i++);
	printf("����Ϊ1������Ϊ0\n");
	printf("%d",!(i-x));
}
