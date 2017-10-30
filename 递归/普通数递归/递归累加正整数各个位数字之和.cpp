#include<stdio.h>
int sun (int n)
{
	if(n/10)
		return n;
	else
		return sun(n/10)+n%10;
} 
int main(void)
{
	int n;
	n=12345;
	printf("%5d\n",sun(n));	
}
