// O(NLog(N))
int findDuplicate(vector<int> &arr, int n){
	sort(arr.begin(),arr.end());
	for(int i=0 ; i<n-1 ; i++){
		if(arr[i] == arr[i+1]){
			return arr[i];
		}
	}
	return -1;
}
// O(N) + O(N)
int findDuplicate(vector<int> &arr, int n){
	unordered_set<int>st;
	for(int i=0 ; i<n ; i++){
		if(st.find(arr[i]) != st.end()) return arr[i];
		st.insert(arr[i]);
	}
	return -1;
}
// O(N) + O(1)
int findDuplicate(vector<int> &arr, int n){
	int slow = arr[0];
	int fast = arr[0];
	do{
		slow = arr[slow];
		fast = arr[arr[fast]];
	}while(slow != fast);
	fast = arr[0];
	while(slow != fast){
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}