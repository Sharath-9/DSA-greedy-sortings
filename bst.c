#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lch,*rch
};
struct node* createnode(int key)
{
	struct node* nn;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=key;
	nn->lch=NULL;
	nn->rch=NULL;
	return nn;
}
struct node* insert(struct node* root ,int key)
{
	if(root==NULL)
	root=createnode(key);
	else if(key<root->data)
	{
	root->lch=insert(root->lch,key);
	}
	else 
	root->rch=insert(root->rch,key);
	return root;
}
int inorder(struct node* root)
{
	if(root==NULL)
	return;
	inorder(root->lch);
	printf("%d\t",root->data);
	inorder(root->rch);
}
int preorder(struct node* root)
{
		if(root==NULL)
	return;
	printf("%d",root->data);
	preorder(root->lch);
	preorder(root->rch);
}
int main()
{
	struct node* root=NULL;
	int n,i,key;
	printf("enter n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter key");
	scanf("%d",&key);
	root=insert(root,key);
	}
	inorder(root);
	preorder(root);
	}
	
	

