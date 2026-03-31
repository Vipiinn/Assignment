//recursive code

class Solution {
  public:
  
    int dp[1001][1001];
  
    int unbound_knap(vector<int>& price , vector<int>& length , int n , int len){
        
        if(n == 0 || len == 0) return 0;
        
        if(dp[n][len] != -1){
            return dp[n][len];
        }
        
        if(length[n-1] <= len){
            
            return dp[n][len] = max(price[n-1]+unbound_knap(price,length,n,len-length[n-1]),
                                unbound_knap(price,length,n-1,len));
        }
        
        else{
            return dp[n][len] =  unbound_knap(price,length,n-1,len);
        }
        
    }
  
    int cutRod(vector<int> &price) {
        
        memset(dp,-1,sizeof(dp));
        
        int n = price.size();
        
        int len = n;
        
        vector<int>length(n);
        
        for(int i=0;i<n;i++){
            length[i] = i+1;
        }
        
        return unbound_knap(price , length , n , len);
    }
};