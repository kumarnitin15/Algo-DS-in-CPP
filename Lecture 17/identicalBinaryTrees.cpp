#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left,*right;
};

Node *newNode(int item) 
{ 
    Node *temp = new Node;
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node* insert(Node* node, int key) 
{ 
    if (node == NULL) 
        return newNode(key); 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
    return node; 
}

bool isIdentical(Node *root1, Node *root2){
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    if(root1->key != root2->key)
        return false;
    if(isIdentical(root1->left,root2->left))
        return isIdentical(root1->right,root2->right);
    return false;
}

int main() {

    // Insert nodes
    Node *root1 = NULL;
    root1 = insert(root1,14);
    root1 = insert(root1,12);
    root1 = insert(root1,16);
    root1 = insert(root1,19);
    root1 = insert(root1,10);
    root1 = insert(root1,22);
    root1 = insert(root1,36);
    root1 = insert(root1,9);
    root1 = insert(root1,1);

    Node *root2 = NULL;
    root2 = insert(root2,14);
    root2 = insert(root2,12);
    root2 = insert(root2,16);
    root2 = insert(root2,19);
    root2 = insert(root2,10);
    root2 = insert(root2,22);
    root2 = insert(root2,36);
    root2 = insert(root2,9);
    root2 = insert(root2,1);

    if(isIdentical(root1,root2))
        cout << "The trees are identical" << endl;
    else    
        cout << "The trees are not identical" << endl;
}
