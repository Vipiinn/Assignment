class Solution {
  public:
    int LongestRepeatingSubsequence(string &a) {
        
        string b = a;
        
        int n = a.length();
        
        vector<vector<int>>dp(n+1 , vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(a[i-1] == b[j-1] && i != j){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        
        return dp[n][n];
        
    }
};