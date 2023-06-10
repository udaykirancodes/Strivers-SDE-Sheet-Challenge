// O(N)
long long maxSubarraySum(int arr[] , int n){
    long long maxi = 0;  // keep the maximum sum found
    long long sum = 0; // sum of array
    for(int i=0 ; i<n ; i++){
        sum += arr[i];  // add to array
        maxi = max(maxi , sum ); // udate the maximum
        // if sum becomes less than zero
        if(sum < 0) sum = 0;
        // update it to zero
    }
    return maxi;
}