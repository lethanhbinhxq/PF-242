#include <iostream>

using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* create_tree() {
    BinaryTreeNode* root = new BinaryTreeNode();
    root->data = 10;

    BinaryTreeNode* sub1 = new BinaryTreeNode();
    sub1->data = 15;
    
    BinaryTreeNode * sub11 = new BinaryTreeNode();
    sub11->data = 7;
    sub11->left = nullptr;
    sub11->right = nullptr;

    BinaryTreeNode * sub12 = new BinaryTreeNode();
    sub12->data = 3;
    sub12->left = nullptr;
    sub12->right = nullptr;

    BinaryTreeNode* sub2 = new BinaryTreeNode();
    sub2->data = 30;
    sub2->left = nullptr;
    sub2->right = nullptr;

    root->left = sub1;
    root->right = sub2;
    sub1->left = sub11;
    sub1->right = sub12;

    return root;
}

int main() {
    BinaryTreeNode* root = create_tree();
    return 0;
}