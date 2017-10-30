#include<stdio.h>
#include<stdlib.h>
#define N 8
typedef struct node{
	int data;
	struct node * left;
	struct node * right;
	
}BTNode;
int count=0;
BTNode * CreateTree(int arr[],int n)
{
	BTNode * t,*p,*q,*root=NULL;
	for(int i=0;i<n;i++){
		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=arr[i];
		p->left=p->right=NULL;
		if(!root){
			root=p;
		}
		else{
			q=root;
			while(q){
				t=q;
				if(q->data>p->data)
					q=q->left;
				else
					q=q->right;
			}
			
			if(t->data>p->data)
				t->left=p;
			else
				t->right=p;
		}
	}
	return root;
}
void LevelOrder(BTNode * root)
{
	BTNode * p;
	BTNode ** Q=(BTNode **)malloc(sizeof(BTNode)*(N+1));
	int front=0,real=0;
	Q[++real]=root;
	while(front-real){
		p=Q[++front];
		printf("%5d",p->data);
		if(p->left)
			Q[++real]=p->left;
		if(p->right)
			Q[++real]=p->right;
		
	}
}
int main(void)
{
	int  arr[N]={3,2,4,7,5,8,6,9};
	
	BTNode * root;
	root=CreateTree(arr,8);
		LevelOrder(root); 
} 

