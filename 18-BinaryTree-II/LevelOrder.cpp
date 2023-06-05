vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(root == nullptr) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front(); q.pop();
        ans.push_back(cur->val);
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return ans;
}