class Solution {

  public:
  
    void subsetSum(vector<int>& arr , int sum , vector<vector<int>>&dp){
        
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=sum;j++){
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
  
    int minDifference(vector<int>& arr) {
        
        int n = arr.size();
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        // initialization arr
        vector<vector<int>>dp(n+1 , vector<int>(sum+1 , 0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        
        subsetSum(arr , sum , dp);
        
        //vector for stroing sum of last row true's value
        
        vector<int>v;
        
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i] == true){
                v.push_back(i);
            }
        }
        
        int mini = INT_MAX;
        
        for(int i=0;i<v.size();i++){
            mini = min(mini , sum-(2*v[i]));
        }
        
        return mini;
    }
};
