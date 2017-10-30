#include<stdio.h>
int move[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int chess[12][12]={0};
int count=0;
int cnt=0;
void Horse(int x,int y)
{
	int a,b,k,g;
	for(int i=0;i<8;i++)
	{
		a=x+move[i][0];
		b=y+move[i][1];
		if(chess[a][b]==0){
			chess[a][b]=++cnt;
			if(cnt<64){
				Horse(a,b);
			}
			else{
				printf("µÚ%d¸ö£º\n",++count);
				for(k=2;k<10;k++)
				{
					for(g=2;g<10;g++)
					{
						printf("%3d",chess[k][g]);
					}
					printf("\n");
				}
					
			}
			chess[a][b]=0;
			cnt--;
		}
	}
}
int main(void)
{
	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(i==0||i==1||i==11||i==10||j==0||j==1||j==11||j==10){
				chess[i][j]=-1;
			}
		}
	}	

	for(i=2;i<10;i++)
		for(j=2;j<10;j++)
		{
			chess[i][j]=++cnt;
			Horse(i,j);
			chess[i][j]=0;
			cnt=0;
		}
}


