int maximumProfit(vector<int> &prices){
    int curmin = prices[0];
    int res = 0;
    for(int i=0 ; i<prices.size() ; i++){
        res = max(res , (prices[i]-curmin));
        curmin = min(curmin , prices[i]);
    }
    return res;
}