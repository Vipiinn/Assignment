class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        
        int n = arr.size();
        
        int count = 0;
        int element = -1;
        
        for(int i=0;i<n;i++){
            if(count == 0){
                element = arr[i];
                count++;
            }
            else if(arr[i] == element){
                count++;
            }
            else {
                count--;
            }
        }
        
        count = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == element) count++;
        }
        
        if(count > n/2) return element;
        else return -1;
        
    }
};