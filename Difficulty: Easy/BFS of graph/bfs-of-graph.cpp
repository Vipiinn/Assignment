class Solution {
  public:
  
  
    void breadthFirstSearch(vector<vector<int>>& adj , unordered_map<int,bool>& visited , 
                            vector<int>& ans , int node){
                                
        queue<int>q;
        q.push(node);
        visited[node] = true;
        
        while(q.size() > 0){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
                                
    }
  
    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int>ans;
        unordered_map<int,bool> visited;
        
        breadthFirstSearch(adj,visited,ans,0);
        
        return ans;
        
    }
};