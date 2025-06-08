#include<iostream>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	
	Node(int data)
	{
		val=data;
		left=nullptr;
		right=nullptr;
	}
};

Node* buildtree()
{
	Node* root=new Node(1);
	root->left=new Node(2);
	root->left->left=new Node(3);
	root->right=new Node(4);
	root->right->right=new Node(5);
	return root;
}
void inorder(Node* root)
{
	if(!root) return;
	inorder(root->left);
	cout<<root->val;
	inorder(root->right);
}
int main()
{
	Node*root=buildtree();
	cout<<" inorder traversal"<<endl;
	inorder(root);
}

// eg:     1
//        / \
//       2   4
//      /     \
//     3       5



// USING CLASS

#include<iostream>
using namespace std;

class Node{
    public:
	int val;
	Node* left;
	Node* right;
	
	Node(int data)
	{
		val=data;
		left=nullptr;
		right=nullptr;
	}
};

Node* buildtree()
{
	Node* root=new Node(1);
	root->left=new Node(2);
	root->left->left=new Node(3);
	root->right=new Node(4);
	root->right->right=new Node(5);
	return root;
}
void inorder(Node* root)
{
	if(!root) return;
	inorder(root->left);
	cout<<root->val;
	inorder(root->right);
}
int main()
{
	Node*root=buildtree();
	cout<<" inorder traversal"<<endl;
	inorder(root);
}
