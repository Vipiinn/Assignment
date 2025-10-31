class Solution {
  public:

    
    void reverse(vector<int>& arr , int st , int end){
        
        while(st < end){
            swap(arr[st++] , arr[end--]);
        }
    }
    
    void rotateArr(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        d = d % n;
        
        reverse(arr , 0 , d-1);
        reverse(arr , d , n-1);
        reverse(arr , 0 , n-1);
        
        
    }
};