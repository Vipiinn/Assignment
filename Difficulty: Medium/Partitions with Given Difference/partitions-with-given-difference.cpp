class Solution {
  public:
  
    void subsetSum(vector<int>& arr , int sum , vector<vector<int>>& dp){
        
        int n = arr.size();
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        
        int n = arr.size();
        
        int arrSum = 0;
        
        for(int i=0;i<n;i++){
            arrSum += arr[i];
        }
        
        if((diff + arrSum) % 2 != 0) return 0;
        
        int sum = (diff+arrSum) / 2;
        
        // we have sum and arr .... now this question is converted into count no of subset 
        
        vector<vector<int>>dp(n+1 , vector<int>(sum+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }
        
        subsetSum(arr,sum , dp);
        
        return dp[n][sum];
    }
};