#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left,*right;
};

Node* search(Node* root, int key) 
{ 
    if (root == NULL || root->key == key) 
       return root; 

    if (root->key < key) 
       return search(root->right, key); 
  
    return search(root->left, key); 
} 

Node *newNode(int item) 
{ 
    Node *temp = new Node;
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->key << " ";
        inorder(root->right); 
    } 
}

Node *minNode(Node *root){
    while(root->left)
        root = root->left;
    return root;
}

Node *remove(Node *root,int key)
{   
    if(!root)
        return root;

    if(root->key < key)
        root->right = remove(root->right,key);

    else if(root->key > key)
        root->left = remove(root->left,key);

    else {
        Node *tmp;
        
        if(!root->left){
            tmp = root->right;
            delete root;
            return tmp;
        }

        if(!root->right){
            tmp = root->left;
            delete root;
            return tmp;
        }

        tmp = minNode(root->right);
        root->key = tmp->key;
        root->right = remove(root->right,tmp->key);
    }
    return root;
}

int main() {

    // Insert nodes
    Node *root = NULL;
    root = insert(root,14);
    root = insert(root,12);
    root = insert(root,16);
    root = insert(root,19);
    root = insert(root,10);

    // Print them out 
    inorder(root);
    cout << endl;

    // Search nodes
    if(search(root,12))
        cout << "12 found" << endl;
    else 
        cout << "12 not present in the tree" << endl;

    if(search(root,25))
        cout << "25 found" << endl;
    else 
        cout << "25 not present in the tree" << endl;

    // Delete some nodes
    root = remove(root,14);
    cout << "After removing 14 :" << endl;
    inorder(root);
    cout << endl;

    root = remove(root,10);
    cout << "After removing 10 :" << endl;
    inorder(root);
    cout << endl;
}
