long long maxSubarraySum(int arr[], int n)
{
    long long int ans = 0;
    long long int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += arr[i];
        if(sum > ans){
            ans = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return ans;
}