void rootToLeafPath(Node *root, int sum, vector<Node *> &path, vector<vector<Node *>> &paths){
    if(!root)
        return;

    path.push_back(root);
    
    if(!root->left && !root->right){
        if(root->key == sum){
            paths.push_back(path);
        }
        path.pop_back();
        return;
    }

    rootToLeafPath(root->left,sum-root->key,path,paths);
    rootToLeafPath(root->right,sum-root->key,path,paths)
    
    path.pop_back();
}