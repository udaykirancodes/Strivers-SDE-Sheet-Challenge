// Brute Force
// O(N*N) + O(1)
int maximumProfit(vector<int> &prices){
    int profit = 0;
    for(int i=0 ; i<prices.size() ; i++) {
        int maxIndex = i;
        for(int j=i+1 ; j<prices.size() ; j++) {
            if(prices[maxIndex] < prices[j]){
                maxIndex = j;
            }
        }
        profit = max(profit , prices[maxIndex] - prices[i]);
    }
    return profit;
}
// O(N) + O(1)
int maximumProfit(vector<int> &prices){
    int curmin = prices[0];
    int res = 0;
    for(int i=0 ; i<prices.size() ; i++){
        res = max(res , (prices[i]-curmin));
        curmin = min(curmin , prices[i]);
    }
    return res;
}