// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>

using namespace std;

struct node
{
	struct node *left;
	struct node *right;
	int val;
};

class tree
{
public:
	tree()
	{
		root=NULL;
	}
	//往树种插入节点
	void insert(node *rot,int num)
	{
		//先考虑根节点是否为空
		if(root==NULL)
		{
			root=new node;
			root->val=num;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			//左子节点
			if(rot->left==NULL&&rot->val>num)
			{
				node *add=new node;
				add->val=num;
				add->left=add->right=NULL;
				rot->left=add;
			}

			else if(rot->right==NULL&&rot->val<=num)
			{
				node *add=new node;
				add->val=num;
				add->left=add->right=NULL;
				rot->right=add;				
			}
			else
			{
				if(rot->val<=num) insert(rot->right,num);
				else insert(rot->left,num);
			}
		}
	}
	//用户调用
	void user_insert(int num)
	{
		insert(root,num);
	}
	void inorder(node *rot)
	{
		if(rot==NULL) return;
		inorder(rot->left);
		cout<<rot->val<<" ";
		inorder(rot->right);
	}
	void user_inorder()
	{
		inorder(root);
	}
	void user_interchange()
	{
		interchange(root);
	}
	//交换，用临时指针存储左子节点
	void interchange(node *rot)
	{
		node *tmp;
		if(rot->left==NULL&&rot->right==NULL) return;
		else
		{
			tmp=rot->left;
			rot->left=rot->right;
			rot->right=tmp;
		}
		if(rot->left) interchange(rot->left);
		if(rot->right) interchange(rot->right);
	}
private:
	node *root;
};

int main()
{
	tree myTree;
	int nodeNum,number;
	cin>>nodeNum;
	for(int i=0;i<nodeNum;i++)
	{
		cin>>number;
		myTree.user_insert(number);
	}
	myTree.user_inorder();
	cout<<endl;
	myTree.user_interchange();
	myTree.user_inorder();
	cout<<endl;
	return 0;
}
