#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node *newNode(int key){
    Node *t = new Node;
    t->key = key;
    t->left = t->right = NULL;
    return t;
}

int findIdx(vector<int> inorder,int key){
    int idx = -1;
    for(int el : inorder){
        if(el == key)
            return idx;
        idx++;
    }
}

Node *constructTree(vector<int> inorder,vector<int> postorder,int &index){
    if(index < 0 || inorder.size() == 0)
        return NULL;
    Node *root = newNode(postorder[index]);
    int idx = findIdx(inorder,postorder[index]);
    vector<int> leftIn;
    vector<int> rightIn;
    for(int i=0; i<=idx; i++)
        leftIn.push_back(inorder[i]);
    for(int i=idx+2; i<inorder.size();i++)
        rightIn.push_back(inorder[i]);
    index--;
    root->right = constructTree(rightIn,postorder,index);
    root->left = constructTree(leftIn,postorder,index);
    return root;
}

void inorder(Node *root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node *root){
    if(!root)
        return NULL;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int index = 6;
    Node *root = constructTree(vector<int>{15,12,37,17,23,31,18},vector<int>{15,37,17,12,31,18,23},index);
    cout << "Inorder of the constructed tree : ";
    inorder(root);
    cout << endl << "Preorder of the constructed tree : ";
    preorder(root);
}
