
class Solution {
  public:
  
    void Bfs_traversal(Node* root , vector<int>ans , vector<vector<int>> &output){
        
        queue<Node*>q;
        q.push(root);
        
        while(q.size() > 0){
            int level = q.size();
            
            for(int i=0;i<level;i++){
                Node* temp = q.front();
                ans.push_back(temp->data);
                q.pop();
                
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            
            output.push_back(ans);
            ans.clear();
        }
    }
  
    vector<vector<int>> levelOrder(Node *root) {
        
        vector<vector<int>>output;
        if(root == NULL) return output;
        vector<int>ans;
        
        Bfs_traversal(root,ans,output);
        return output;
        
    }
};