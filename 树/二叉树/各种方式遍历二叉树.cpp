#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}BTree;  

/*建立二叉树*/
BTree * createTree(int arr[],int len)
{
	BTree * q,* p,* qa,* root=NULL;
	int i;
	for(i=0;i<len;i++){
		p=(BTree *)malloc(sizeof(BTree));
		p->left=p->right=NULL;
		p->data=arr[i];
		if(!root){
			root=p;
		}
		else{
			q=root;
			while(q){
				qa=q;
				if(p->data<q->data){
					q=q->left;
				}
				else{
					q=q->right;
				}
			
			}
			if(p->data<qa->data){
				qa->left=p;
				
			}
			else{
				qa->right=p;
			}
			
		}
	}
	return root;
}

/*递归前序输出*/
void topPrint(BTree * root)
{
	if(root){
		cout<<root->data<<" ";
		topPrint(root->left);
		topPrint(root->right);
	}
	
}

/*递归中序输出*/
void midPrint(BTree * root)
{
	if(root){
		
		midPrint(root->left);
		cout<<root->data<<" ";
		midPrint(root->right);
	}
}

/*递归后序输出*/
void endPrint(BTree *root)
{
	if(root){
		
		endPrint(root->left);
		endPrint(root->right);
		cout<<root->data<<" ";
	}
}

/*非递归前序输出*/
void topNotPrint(BTree * root)
{
	BTree * p,q;
	p=root;
	BTree * S[100]={0};
	int top=-1;
	while(p||top>=0){
		if(p){
			S[++top]=p;
			cout<<p->data<<" ";
			p=p->left;
		}
		else{
			p=S[top--];
			p=p->right;
		}
	}
}

/*非递归中序输出*/
void midNotPrint(BTree *root)
{
	BTree * p,q;
	BTree * S[100]={0};
	int top=-1;
	p=root;
	while(p||top>-1){
		if(p){
			S[++top]=p;
			p=p->left;
		}
		else{
			p=S[top--];
			cout<<p->data<<" ";
			p=p->right;
		}
	}
}

/*非递归后序输出*/
void endNotPrint(BTree *root)
{
	BTree * p=root,*q=NULL;
	BTree * S[100]={0};
	int top=-1;
	while(p||top>-1){
		if(p){
			S[++top]=p;
			p=p->left;
		}
		else{
			p=S[top];
			if((p->right==NULL)||(p->right==q)){
				cout<<p->data<<" ";
				top--;
				q=p;
				p=NULL;
			}
			else{
				p=p->right;
			}
		}
	}
}
/*按层输出*/
void levelPrint(BTree * root)
{
	BTree * L[100]={0},* p;
	int front,real;
	front=real=0;
	L[real++]=root;
	while(front<real){
		p=L[front++];
		cout<<p->data<<" ";
		if(p->left)
			L[real++]=p->left;
		if(p->right)
			L[real++]=p->right;
	}
}
int main(void)
{
	BTree * root=NULL;
	int arr[]={3,2,5,8,4,7,6,9,1};
	int len=sizeof(arr)/sizeof(int);
	root=createTree(arr,len);
//	topPrint(root);
//	midPrint(root);
	endPrint(root);
	cout<<endl;
//	topNotPrint(root);
//	midNotPrint(root);
	endNotPrint(root);
//	levelPrint(root);
	return 0;
}
