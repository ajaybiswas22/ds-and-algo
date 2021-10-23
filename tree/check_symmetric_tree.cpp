#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

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

int check(Node* root)
{
    if(root==NULL)
        return 1;
    
    //queue<Node*> q;
    queue<Node*> lq;
    queue<Node*> rq;

    lq.push(root->left);
    rq.push(root->right);

    while(!lq.empty() || !rq.empty())
    {
        if(lq.size() != rq.size())
            return 0;

        Node* node = lq.front();
        Node* node2 = rq.front();

        //std::cout<<node->key<<" ";
        if(node == NULL && node2 == NULL)
        {
            continue;
        }
        else if(node == NULL || node2 == NULL)
        {
            return 0;
        }
        else if(node->key = node2->key)
        {
            lq.push(node->left);
            lq.push(node->right);

            rq.push(node->right);
            rq.push(node->left);
        }
        else
        {
            return 0;
        }
        lq.pop();
        rq.pop();   
    }
    return 1;
}


int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(20);
   // root->left->left=new Node(40);
   // root->right->right=new Node(40);
	
	std::cout<<check(root);
}