vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    if(root == nullptr) return ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size ; i++){
            TreeNode<int>* cur = q.front(); q.pop();
            if(i==0){
                ans.push_back(cur->data);
            }
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return ans;
}

void inorder(TreeNode<int>* root ,int level , vector<int>&ans){
    if(root == nullptr) return ;
    if(ans.size() == level) {
        ans.push_back(root->data);
    }
    inorder(root->left , level+1 , ans);
    inorder(root->right , level+1 , ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    int level = 0;
    if(root == nullptr) return ans;
    inorder(root , level ,ans);
    return ans;
}