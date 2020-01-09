bool isSymmetric(Node *root){
    queue<Node *>q1;
    queue<Node *>q2;

    q1.push(root);
    q2.push(root);

    while(!q1.empty()){
        Node *t1 = q1.front();
        Node *t2 = q2.front();

        q1.pop();
        q2.pop();

        if(t1->key != t2->key)
            return false;
        
        if(t1->left)
            q1.push(t1->left);
        if(t1->right)
            q1.push(t1->right);

        if(t2->right)
            q2.push(t2->right);
        if(t2->left)
            q2.push(t2->left);
    }
    return true;
}