bool hasSum(Node *root, int sum){
    if(!root)
        return false;
        
    if(!root->left && !root->right){
        if(root->key == sum)
            return true;
        else
            return false;
    }

    if(hasSum(root->left,sum-root->key))
        return true;

    return hasSum(root->right,sum-root->key);
}