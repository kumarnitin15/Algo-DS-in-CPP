#include <iostream>
#include <queue>
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

void preorder(Node *root){
    if(!root)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
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

void postorder(Node *root){
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

void levelorder(Node *root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *tmp = q.front();
        q.pop();

        // Print the key
        cout << tmp->key << " ";
        
        // Push the children into the queue
        if(tmp->left)
            q.push(tmp->left);

        if(tmp->right)
            q.push(tmp->right);
    }
}

int main() {

    // Insert nodes
    Node *root = NULL;
    root = insert(root,14);
    root = insert(root,12);
    root = insert(root,13);
    root = insert(root,16);
    root = insert(root,15);
    root = insert(root,19);
    root = insert(root,10);

    // Preorder
    preorder(root);
    cout << endl;

    // Inorder 
    inorder(root);
    cout << endl;

    // Postorder
    postorder(root);
    cout << endl;

    // Levelorder 
    levelorder(root);
    cout << endl;
}
