class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        
        int n = arr.size();
        
        
        
        
        for(int i=0;i<n;i++){
            int minIdx = -1;
            int min = INT_MAX;
            for(int j=i;j<n;j++){
                if(min > arr[j]){
                    minIdx = j;
                    min = arr[j];
                }
            }
            swap(arr[i] , arr[minIdx]);
        }
    }
};