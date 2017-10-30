#include<stdio.h>
#include<string.h>
int Process(char s[])
{
	int i=0,tag=0;
	int top=-1;
	int Q[100];
	while(s[i]){
		if(s[i]=='(')
			++top;
		else if(s[i]==')'){
			if(top>-1)
				--top;
			else
				break;
		}
		i++;
	}
	if(!s[i]&&top==-1) 
		tag=1;
	return tag;
}
int main(void)
{
	char s[100];
	gets(s);
	if(Process(s)){
		printf("∆•≈‰"); 
	}
	else{
		printf("≤ª∆•≈‰");
	} 
}

