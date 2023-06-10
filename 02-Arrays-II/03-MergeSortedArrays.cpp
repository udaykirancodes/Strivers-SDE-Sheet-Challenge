// Using extra space
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int>v;
	for(int i=0 ; i<m ; i++){
		v.push_back(arr1[i]);
	}
	for(int i=0 ; i<n ; i++){
		v.push_back(arr2[i]);
	}
	sort(v.begin(),v.end());
	arr1 = v;
	return v;
}
// Merge In Place
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	    int k = arr1.size()-1;
        int j = n-1;
        int i = m-1;
        while(i >= 0 && j >= 0) {
            if(arr1[i] > arr2[j]) {
                arr1[k--] = arr1[i--];
            }
            else{
                arr1[k--] = arr2[j--];
            }
        }
        while(i>=0) {
            arr1[k--] = arr1[i--];
        }
        while(j>=0) {
            arr1[k--] = arr2[j--];
        }
		return arr1;
}