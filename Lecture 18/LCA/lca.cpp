#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

bool search(Node *root,int key){
    if(!root)
        return false;
    if(root->key == key)
        return true;
    if(search(root->left,key))
        return true;
    return search(root->right,key);
}

Node *lca(Node *root,int n1,int n2){
    if(!root)
        return NULL;
    
    if(root->key == n1 || root->key == n2)
        return root;

    Node *left = lca(root->left,n1,n2);
    Node *right = lca(root->right,n1,n2);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
}

Node *findLCA(Node *root,int n1,int n2){
    if(!search(root,n1) || !search(root,n2))
        return NULL;
    return lca(root,n1,n2);
}