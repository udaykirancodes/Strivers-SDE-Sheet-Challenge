
// Give N return Matrix
vector<vector<long long int>> printPascal(int n){
    vector<vector<long long int>> ans(n);
    for(int i=0 ; i<n ; i++){
        ans[i].resize(i+1);
        ans[i][0]= ans[i][i] = 1;
        for(int j=1 ; j<i ; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}
// Given R,C return Value
int ncr(int n, int r){
  int res =0;
  for(int i=0 ; i<r ; i++){
    res = res * (n-i);
    res = res / (r-1);
  }
  return res;
}
int getValue(int r,int c){
  return ncr(r-1,c-1);
}
