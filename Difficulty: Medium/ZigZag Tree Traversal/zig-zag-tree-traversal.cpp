
class Solution {
  public:
  
    void zigzag(Node* root , vector<int>&ans , vector<int>output){
        queue<Node*>q;
        q.push(root);
        
        bool flag = true;
        
        while(q.size() > 0){
            
            int level = q.size();
            for(int i=0;i<level;i++){
                Node* temp = q.front();
                q.pop();
                output.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag == true){
                for(int i=0;i<output.size();i++){
                    ans.push_back(output[i]);
                }
                flag = false;
            }
            else{
                for(int i=output.size()-1;i>=0;i--){
                    ans.push_back(output[i]);
                }
                flag = true;
            }
            output.clear();
        }
        
        
    }
  
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int>output;
        vector<int>ans;
        
        zigzag(root,ans,output);
        
        return ans;
    }
};