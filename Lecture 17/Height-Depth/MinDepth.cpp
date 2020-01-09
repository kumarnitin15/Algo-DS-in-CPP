int minDepth(Node *root){
    if(!root)
        return 0;
    return 1 + min(minDepth(root->left),minDepth(root->right));
}