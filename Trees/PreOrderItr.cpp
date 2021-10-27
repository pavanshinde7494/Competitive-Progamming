#include <bits/stdc++.h>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node* root)
{
    stack<Node*>stk;
    Node* curr = root;

    while (!stk.empty() || curr != NULL) {
        if (curr  != NULL) {
            cout << curr->data << ' ';
            stk.push(curr);
            curr = curr->left;
        }
        else {
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
    }
}

int main()
{

    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    inorderIterative(root);

    return 0;
}

