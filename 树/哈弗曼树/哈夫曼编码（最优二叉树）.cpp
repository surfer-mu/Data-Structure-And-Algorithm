#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char word;
	int weight;
	int left,right,parent;
	int * code;
}Huffman;
void CreateHuffman(Huffman * F,int n)
{
	int k1,k2,i,j;
	for(i=0;i<n-1;i++){
		for(k1=0;k1<n+i&&F[k1].parent!=-1;k1++);
		for(k2=k1+1;k2<n+i&&F[k2].parent!=-1;k2++);
		for(j=k2;j<n+i;j++)
		{
			if(F[j].parent==-1){
				if(F[j].weight<F[k1].weight)
				{
					k2=k1;
					k1=j;
				}
				else  if(F[j].weight<F[k2].weight){
					k2=j;
				}
			}
		}
		F[n+i].word='X';
		F[n+i].weight=F[k1].weight+F[k2].weight;
		F[n+i].left=k1;
		F[n+i].right=k2;
		F[n+i].parent=-1;
		F[k1].parent=F[k2].parent=n+i;
		
	}
}

void HuffmanCode(Huffman * F,int n)
{
	int i,j,p,c;
	for(i=0;i<n;i++){
		F[i].code=(int *)malloc((n+1)*sizeof(int));
		F[i].code[0]=0;
		c=i;
		while(F[c].parent!=-1){
			p=F[c].parent;
		
			if(F[p].left==c)
			{
				F[i].code[++F[i].code[0]]=0;
			}
			else
			{
				F[i].code[++F[i].code[0]]=1;
			}
			c=p;
		}
	}
}
void PrintTree(Huffman * F,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%c: ",F[i].word);
		for(int j=F[i].code[0];j>0;j--)
			printf("%d",F[i].code[j]);
		printf("\n");
	}
}
int main(void)
{
	int i,n;
	Huffman * F;
	scanf("%d",&n);
	F=(Huffman * )malloc((2*n-1)*sizeof(Huffman));
	for(i=0;i<n;i++){
		getchar();
		scanf("%c",&F[i].word);
		scanf("%d",&F[i].weight);
		F[i].left=F[i].right=F[i].parent=-1;
		F[i].code=NULL;
	}
	CreateHuffman(F,n);
	HuffmanCode(F,n);
	PrintTree(F,n);
}
