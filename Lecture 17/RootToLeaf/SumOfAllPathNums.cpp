void sumOfAllPahts(Node *root,int curr,int &sum){
    if(!root)
        return;

    int tmp = ((curr*10)%1003 + root->key)%1003;
    
    if(root->left){
        sumOfAllPahts(root->left,tmp,sum);
    }

    if(root->right){
        sumOfAllPahts(root->right,tmp,sum);
    }

    if(!root->left && !root->right){
        sum = (sum+tmp)%1003;
    }
}