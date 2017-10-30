#include<stdio.h>
#include<stdlib.h>
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
void Forder(BTNode * root)
{
	if(root)
	{
		
		printf("%5d",root->data);
		
			++count;
		
		Forder(root->left);
		Forder(root->right);
	}
}
void midPrint(BTNode * root)
{
	if(root)
	{
		
		Forder(root->left);
		printf("%5d",root->data);
		Forder(root->right);
	}
}
void endPrint(BTNode * root)
{
	if(root)
	{
	
		Forder(root->left);
		Forder(root->right);
		printf("%5d",root->data);
	}
}
int main(void)
{
	int  arr[8]={3,2,4,7,5,8,6,9};
	
	BTNode * root;
	root=CreateTree(arr,8);
	
	Forder(root);
	printf("\n");
	midPrint(root);
	printf("\n");
	endPrint(root);
	printf("\n");
	printf("%d",count);
} 

