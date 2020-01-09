int isBalanced(Node *root, bool &balanced){
    int left = 0, right = 0;

    if(root->left)
        left = isBalanced(root->left,balanced);
    
    if(root->right)
        right = isBalanced(root->right,balanced);

    if(abs(left-right) > 1)
        balanced = false;
    
    return 1 + max(left,right);
}