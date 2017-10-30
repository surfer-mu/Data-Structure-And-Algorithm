#include<stdio.h>
int chess[12][12]={0};
int H[64][3];
int top=-1;
int move[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int count=0,cnt=0;
void PrintChese()
{
				for(int k=0;k<12;k++)
				{
						for(int g=0;g<12;g++)
						{
							printf("%3d",chess[k][g]);
						}
						printf("\n");
				}
}
void Horse()
{
	int a,b;
	int x=2,y=2;
	int i,j=0;
	for(;count<64;)
	{
		for(;j<8;j++)
		{
			a=H[top][0]+move[j][0];
			b=H[top][1]+move[j][1];
			if(chess[a][b]!=-1&&chess[a][b]==0)
				break;
		}
	
		if(j<8){
			top++;
			H[top][0]=a;
			H[top][1]=b;
			H[top][2]=j;
			chess[a][b]=++count;
			if(top<63){
				
				j=0;
			}
			else{
				printf("µÚ%d¸öÆåÅÌ\n",++cnt);
				PrintChese();
				
				x=H[top][0];
				y=H[top][1];
				j=H[top][2];
				chess[x][y]=0;
				count--;
				--top;
				j++;
			}
		}
		else{
				x=H[top][0];
				y=H[top][1];
				j=H[top][2];
				chess[x][y]=0;
				count--;
				--top;
				j++;
		}
	}
}

int main(void)
{
	for(int i=0;i<12;i++)
	{	for(int j=0;j<12;j++)
		{
			if(i==0||i==1||i==10||i==11||j==0||j==1||j==10||j==11)
				chess[i][j]=-1;
		}
	}
	chess[2][2]=++cnt;
	++top;
	H[top][0]=2;
	H[top][1]=2;
	H[top][2]=0;
	Horse();
	 PrintChese();
}
