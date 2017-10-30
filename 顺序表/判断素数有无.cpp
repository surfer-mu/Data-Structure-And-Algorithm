#include<stdio.h>
int main(void)
{
	int x=29;//被判断的数
	int i;
	for(i=2;i<x&&x%i;i++);
	printf("质数为1，合数为0\n");
	printf("%d",!(i-x));
}
