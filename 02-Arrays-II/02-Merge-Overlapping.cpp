vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>>ans;
    int n = intervals.size();
    sort(intervals.begin() , intervals.end());
    vector<int>temp = intervals[0];
    for(int i=1 ; i<n ; i++){
        // check if it can be merged
        if(intervals[i][0] <= temp[1]){
            temp[0] = min(temp[0],intervals[i][0]);
            temp[1] = max(temp[1],intervals[i][1]);
        }
        else{
            ans.push_back(temp);
            temp = intervals[i];
        }
    }
    ans.push_back(temp);
    return ans;
}