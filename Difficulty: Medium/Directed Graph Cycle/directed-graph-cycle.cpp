class Solution {
  public:
  
    bool isCyclePresent(unordered_map<int,list<int>>&adj , unordered_map<int,bool>& visited,
                        unordered_map<int,bool>& dfsVisited , int node){
                            
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto neibhour : adj[node]){
            if(!visited[neibhour]){
                bool ans = isCyclePresent(adj,visited,dfsVisited,neibhour);
                if(ans) return true;
            }
            else if(dfsVisited[neibhour]){
                return true;
            }
        }
        
        dfsVisited[node] = false;
        
        return false;
                            
                            
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        unordered_map<int,list<int>>adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cycle = isCyclePresent(adj,visited,dfsVisited,i);
                if(cycle) return true;
            }
            
        }
        
        return false;
        
    }
};