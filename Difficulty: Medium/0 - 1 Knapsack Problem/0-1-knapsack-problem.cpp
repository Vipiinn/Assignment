class Solution {
  public:
  
    int dp[1002][1002];
    
    int knap(vector<int>&val , vector<int>&wt , int W , int n){
        
        //base case
        if(n == 0 || W == 0){
            return 0;
        }
        
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        
        if(W >= wt[n-1]){
            return dp[n][W] =  max(val[n-1] + knap(val,wt,W-wt[n-1],n-1) , knap(val,wt,W,n-1));
        }
        else return dp[n][W] = knap(val,wt,W,n-1);
    }
    
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        
        memset(dp,-1,sizeof(dp));
        
        return knap(val,wt,W , n);
        
    }
};