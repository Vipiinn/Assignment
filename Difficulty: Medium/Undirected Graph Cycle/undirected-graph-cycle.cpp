class Solution {
  public:
  
    bool isCyclic(unordered_map<int,list<int> >&adj , unordered_map<int,bool>& visited , int src){
        // crating mapping for parent
        unordered_map<int,int>parent;
        parent[src] = -1;
        queue<int>q;
        q.push(src);
        visited[src] = true;
        
        while(q.size() > 0){
            int frontNode = q.front();
            q.pop();
            
            for(auto i : adj[frontNode]){
                if(visited[i] == true && i != parent[frontNode]) return true;
                else if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    parent[i] = frontNode;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // creating adjacancy list;
        unordered_map<int,list<int> >adj;
        int E = edges.size();
        
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //creating a visited 
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = isCyclic(adj , visited , i);
                if(ans == 1) return true;
            }
        }
        
        return false;
    }
};