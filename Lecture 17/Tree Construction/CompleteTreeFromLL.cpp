#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

struct NodeLL {
    int key;
    NodeLL *next;
};

NodeLL *newNodeLL(int key){
    NodeLL *t = new NodeLL;
    t->key = key;
    t->next = NULL;
    return t;
}

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

Node *constructTree(NodeLL *head){
    Node *root = NULL;
    if(head)
        root = newNode(head->key);
    
    head = head->next;
    queue<Node *> q;
    q.push(root);

    while(head){
        Node *t = q.front(); q.pop();
        
        Node *left = newNode(head->key);
        head = head->next;
        t->left = left;
        
        if(!head)
            break;
        
        Node *right = newNode(head->key);
        head = head->next;
        t->right = right;

        q.push(left);
        q.push(right);
    }
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
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    NodeLL *head = newNodeLL(1);
    head->next = newNodeLL(2);
    head->next->next = newNodeLL(3);
    head->next->next->next = newNodeLL(4);
    head->next->next->next->next = newNodeLL(5);
    head->next->next->next->next->next = newNodeLL(6);
    Node *root = constructTree(head);
    cout << "Inorder of the constructed tree : ";
    inorder(root);
    cout << endl << "Preorder of the constructed tree : ";
    preorder(root);
}
