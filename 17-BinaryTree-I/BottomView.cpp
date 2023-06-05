#define Node BinaryTreeNode<int>
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int>ans;
    if(root == nullptr) return ans;
    map<int,int>mp; // distance , value
    queue<pair<Node*,int>>q;
    q.push({root , 0});
    mp[0] = root->data;
    while(!q.empty()) {
        auto it = q.front(); q.pop();
        Node* cur = it.first;
        int dist = it.second;
            mp[dist] = cur->data;
        if(cur->left){
            q.push({cur->left,dist-1});
        }
        if(cur->right){
            q.push({cur->right,dist+1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}