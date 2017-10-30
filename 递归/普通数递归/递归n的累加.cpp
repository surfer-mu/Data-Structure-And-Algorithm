#include<stdio.h>
int fun (int n)
{
	if(n==1)
		return 1;
	else 
		return n+fun(n-1);
} 
int main(void)
{
	int n;
	n=5;
	printf("%5d\n",fun(n));	
}
