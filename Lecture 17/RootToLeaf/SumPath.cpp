bool rootToLeafPath(Node *root, int sum, vector<Node *> &path){
    if(!root)
        return false;

    path.push_back(root);
    
    if(!root->left && !root->right){
        if(root->key == sum)
            return true;
        path.pop_back();
        return false;
    }

    if(rootToLeafPath(root->left,sum-root->key,path))
        return true;
    if(rootToLeafPath(root->right,sum-root->key,path))
        return true;
    
    path.pop_back();
    return false;
}