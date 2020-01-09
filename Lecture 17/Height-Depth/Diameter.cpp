int diameter(Node *root,int &d){
    if(!root)
        return 0;

    if(!root->left && !root->right){
        d = max(d,1);
        return 1;
    }

    int left = diameter(root->left,d);
    int right = diameter(root->right,d);
    d = max(d, 1+left+right);
    return 1+max(left,right)
}