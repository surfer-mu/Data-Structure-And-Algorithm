#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}BTree;  

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
//叶子节点个数
int leaf(BTree * root)
{
	int l,r;
	if(!root)
		return 0;

	if(!(root->left)&&!(root->right))
		return 1;
	
	l=leaf(root->left);
	r=leaf(root->right);
	return l+r;
	
} 
//二叉树高度
int BTreeDepth(BTree * root)
{
	if(!root)
		return 0;
	int l=BTreeDepth(root->left);
	int r=BTreeDepth(root->right);
	return (l>r?l:r)+1;
}
int main(void)
{
	BTree * root=NULL;
	int arr[]={3,2,5,8,4,7,6,9,1};
	int len=sizeof(arr)/sizeof(int);
	root=createTree(arr,len);
	cout<<"叶子节点个数："<<leaf(root)<<endl;
	cout<<"二叉树高度："<<BTreeDepth(root)<<endl; 
	return 0;
}
