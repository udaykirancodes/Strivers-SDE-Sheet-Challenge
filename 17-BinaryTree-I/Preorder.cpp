void dfs(TreeNode* root , vector<int>&ans){
    if(root == nullptr) return ;
    ans.push_back(root->data);
    dfs(root->left , ans);
    dfs(root->right , ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    dfs(root , ans);
    return ans;
}