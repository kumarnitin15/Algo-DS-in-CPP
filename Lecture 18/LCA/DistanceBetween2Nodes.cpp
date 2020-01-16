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

Node *LCA(Node *root,int n1,int n2){
    if(!root)
        return NULL;
    
    if(root->key == n1 || root->key == n2)
        return root;

    Node *left = LCA(root->left,n1,n2);
    Node *right = LCA(root->right,n1,n2);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
}

int dist(Node *root, int key){
    if(!root)
        return 0;
    if(root->key == key)
        return 1;
    return 1 + dist(root->left,key) + dist(root->right,key);  // one of left or right will always be zero.
}

Node *findLCA(Node *root,int n1,int n2){
    if(!search(root,n1) || !search(root,n2))
        return NULL;
    return LCA(root,n1,n2);
}

int distance(Node *root,int n1,int n2){
    Node *lca = findLCA(root,n1,n2);
    
    if(!lca)    
        return -1;
    
    return dist(lca,n1) + dist(lca,n2) - 1; // -1 because the lca would be added twice.
}