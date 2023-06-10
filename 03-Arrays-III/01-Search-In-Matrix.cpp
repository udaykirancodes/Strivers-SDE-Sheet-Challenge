// Naive Search
// O(N*M) + O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0 ;i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
// With Sorted Array Conditions
// O(N+M) + O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int i = 0 , j = m-1;
    while(i<n && j>=0){
        if(mat[i][j] == target) return true;
        if(mat[i][j] < target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}