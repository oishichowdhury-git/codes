#include <iostream>
#include <cmath>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Utility function to perform preorder traversal on a binary tree
void preorder(Node *node)
{
    if (node == nullptr) {
        return;
    }
 
    cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
}
 
// Utility function to return the sum of the left & right children of a given node
int children_sum(Node* node)
{
    int left = node->left ? node->left->data : 0;
    int right = node->right ? node->right->data : 0;
 
    return left + right;
}
 
// Function to fix a given binary tree to satisfy the children-sum property
void fixBinaryTree(Node* root)
{
    // base case: empty tree or leaf node
    if (!root || !root->left && !root->right) {
        return;
    }
 
    // recur for the left and right subtree
    fixBinaryTree(root->left);
    fixBinaryTree(root->right);
 
    // calculate the difference between the root and its children
    int diff = root->data - children_sum(root);
 
    // if the root is less than the children's sum, increment it by `abs(diff)`
    if (diff < 0) {
        root->data += abs(diff);
    }
    // if the root is greater than the children's sum, fix the root by
    // either updating the left or right subtree by `diff`
    else if (diff > 0)
    {
        Node* subtree = root->left ? root->left : root->right;
        subtree->data += diff;
        fixBinaryTree(subtree);
    }
}
 
int main()
{
    Node *root = new Node(25);
    root->left = new Node(8);
    root->right = new Node(10);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    fixBinaryTree(root);
    preorder(root);
 
    return 0;
}