class Solution {
  public:
  
    int dp[1001][1001];
  
    int knap(vector<int>&val , vector<int>&wt , int n , int W){
        
        if(W == 0 || n == 0) return 0;
        
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + knap(val,wt,n,W-wt[n-1]) , knap(val, wt, n-1 , W));
        }
        else{
            return dp[n][W] = knap(val , wt , n-1 , W);
        }
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        
        memset(dp , -1 , sizeof(dp));
        
        int n = val.size();
        
        return knap(val , wt, n , W);
        
        
    }
};