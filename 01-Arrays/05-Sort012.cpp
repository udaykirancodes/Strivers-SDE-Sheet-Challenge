// Brute
void sort012(int *arr, int n)
{
   sort(arr ,arr+n);
}

// Better
void sort012(int *arr, int n)
{
   int one = 0 , two = 0 , zero = 0;
   for(int i=0 ; i<n ; i++){
      int el = arr[i];
      if(el == 0) zero++;
      else if(el == 1) one++;
      else if(el == 2) two++;
   }
   int ind = 0;
   while(zero--){
      arr[ind++] = 0;
   }
   while(one--){
      arr[ind++] = 1;
   }
   while(two--){
      arr[ind++] = 2;
   }
}
// Optimal
void sort012(int *arr, int n)
{
   int low = 0 , mid = 0 , high = n-1;
   while(mid <= high){
      if(arr[mid] == 0){
         swap(arr[low],arr[mid]);
         low++;
         mid++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{
         swap(arr[mid],arr[high]);
         high--;
      }
   }
}