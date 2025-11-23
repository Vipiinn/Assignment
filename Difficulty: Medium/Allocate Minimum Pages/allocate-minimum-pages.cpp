class Solution {
  public:
  
    bool isPossible(vector<int>& arr , int k , int mid){
        int studentCount = 1;
        int pageCount = 0;
        
        for(int i=0;i<arr.size();i++){
            if(pageCount + arr[i] <= mid){
                pageCount += arr[i];
            }
            else{
                studentCount++;
                if(studentCount > k || arr[i] > mid) return false;
                
                pageCount = arr[i];
            }
        }
        
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        
        
        int n = arr.size();
        
        if(k > n) return -1;
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        int st = 0;
        int end = sum;
        
        int ans = -1;
        
        while(st <= end){
            int mid = st + (end-st) / 2;
            
            if(isPossible(arr,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid + 1;
            }
        }
        
        return ans;
        
    }
};