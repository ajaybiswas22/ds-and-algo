#include<iostream>
#include<queue>

// total no. of nodes in a binary tree

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k)
  {
      key=k;
      left=right=NULL;
  }
};

int get_size(Node *root)
{
    if(root == NULL)
        return 0;
    return 1 + get_size(root->left) + get_size(root->right);
}

int get_size_iterative(Node *root)
{
    // level order traversal 
    if(root == NULL)
        return 0;

    int count=1;
    
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();   
        if(temp->left)
        {
            q.push(temp->left);
            count++;
        }
        if(temp->right)
        {
            q.push(temp->right);
            count++;
        }
        q.pop();
    }
    return count;
}

int main()
{
    Node *root=new Node(40);
	root->left=new Node(20);
	root->right=new Node(60);
	root->left->left=new Node(30);
	root->left->right=new Node(90);
	root->right->right=new Node(70);
    root->left->right->left = new Node(10);
	
	std::cout<<get_size_iterative(root);
}