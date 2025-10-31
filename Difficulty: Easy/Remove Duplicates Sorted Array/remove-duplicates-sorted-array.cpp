class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        vector<int>ans;
        
        ans.push_back(arr[0]);
        
        for(int i=1;i<arr.size();i++){
            if(ans[ans.size()-1] != arr[i]) ans.push_back(arr[i]);
        }
        
        return ans;
        
    }
};