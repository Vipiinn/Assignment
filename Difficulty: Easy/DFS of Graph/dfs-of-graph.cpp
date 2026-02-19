class Solution {
  public:
  
    void depthFristSearch(vector<vector<int>>& adj , unordered_map<int,bool>& visited , vector<int>& ans , int node){
        
        ans.push_back(node);
        visited[node] = true;
        
        for(auto i : adj[node]){
            if(!visited[i]){
                depthFristSearch(adj,visited , ans , i);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        
        vector<int>ans;
        unordered_map<int,bool>visited;
        
        depthFristSearch(adj , visited , ans ,0);
        
        
        return ans;

    }
};