class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        vector<int>ans;
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0;i<arr.size();i++){
            maxi = max(maxi , arr[i]);
            mini = min(mini , arr[i]);
        }
        
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
        
    }
};