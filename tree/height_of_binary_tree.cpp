#include<iostream>
#include<queue>
#include<algorithm>

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

int get_height(Node* root)
{
    if(root == NULL)
        return 0;
    return 1 + std::max( get_height(root->left) , get_height(root->right) );
}

int get_height_iterative(Node* root)
{
    // if no node
    if (root == NULL)  
        return 0;

    int count = 0;
    std::queue<Node *> q;
    q.push(root);
    Node* node;

    while (!q.empty())
    {
        // first insert both child in the row, then remove parent
        int size = q.size();
        while(size--)
        {
            node = q.front();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            q.pop();
        }
        count++;
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
	
	std::cout<<get_height_iterative(root);
}