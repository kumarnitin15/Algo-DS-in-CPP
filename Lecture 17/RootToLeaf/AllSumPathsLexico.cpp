void rootToLeafPath(Node *root, int sum, vector<int> &path, set<vector<int>> &st){
    if(!root)
        return;

    path.push_back(root->key);
    
    if(!root->left && !root->right){
        if(root->key == sum){
            st.insert(path);
        }
        path.pop_back();
        return;
    }

    rootToLeafPath(root->left,sum-root->key,path,st);
    rootToLeafPath(root->right,sum-root->key,path,st);
    
    path.pop_back();
    return;
}