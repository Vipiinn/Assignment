class Solution {
  public:
  
   int dp[1003][1003];
  
    int knap(vector<int>&val , vector<int>&wt , int W , int n){
        
        //base case
        if(n == 0 || W == 0) return 0;
        
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        
        // case for choice diagram
        if(wt[n-1] <= W){
            dp[n][W] =  max((val[n-1] + knap(val , wt , W-wt[n-1] , n-1)) , knap(val,wt,W,n-1));
            return dp[n][W];
        }
        
        else if(wt[n-1] > W){
            dp[n][W] =  knap(val,wt,W,n-1);
            return dp[n][W];
        }
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        memset(dp, -1, sizeof(dp));
        
        int n = val.size();
        
        return knap(val , wt , W , n);
        
    }
};