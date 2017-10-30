#include<stdio.h>
#include<stdlib.h>
int level(char op)
{
	int l;
	switch(op){
		case '#':l=-1;break;
		case '+':
		case '-':l=1;break;
		case '(':l=0;break;
		case '*':
		case '/':l=2;break; 
	}
	return l;
}
int count(int y,int x,char op)
{
	int v;
	switch(op){
		case '+':v=x+y;break;
		case '-':v=x-y;break;
		case '*':v=x*y;break;
		case '/':v=x/y;break;
	}
	return v;
}
int computer(char s[])
{
	int vas[100];
	char ops[100];
	int vtop,otop,i=0;
	int v1,v2,op;
	vtop=otop=-1;
	ops[++otop]='#';
	
	while(s[i]){
		if(s[i]>='0'&&s[i]<='9'){
			int num=0;
			while(s[i]>='0'&&s[i]<='9')
			{
				num=num*10+s[i]-'0';
				i++;
			}
		
			vas[++vtop]=num;
			i--;
		}
		else if(s[i]=='('){
			ops[++otop]='(';
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			while(level(s[i])<level(ops[otop])){
				v1=vas[vtop--];
				v2=vas[vtop--];
				op=ops[otop--];
				vas[++vtop]=count(v1,v2,op);
			}
				ops[++otop]=s[i];
		}
		else if(s[i]==')'){
			while(ops[otop]!='('){
				v1=vas[vtop--];
				v2=vas[vtop--];
				op=ops[otop--];
				vas[++vtop]=count(v1,v2,op);
			}
			otop--;
		}
		i++;
	}
		while(otop!=0){
				v1=vas[vtop--];
				v2=vas[vtop--];
				op=ops[otop--];
				vas[++vtop]=count(v1,v2,op);
			}
	return vas[vtop];
}
int main(void)
{
	char s[100];
	int end=0;
	gets(s);
	end=computer(s);

	printf("%5d",end);
}
