

class Solution {
  public:
  
    void helper(Node* root , vector<int>& ans , int lvl){
        
        if(root == NULL) return;
        
        if(ans.size() == lvl){
            ans.push_back(root->data);
        }
        
        helper(root->left , ans , lvl+1);
        helper(root->right , ans , lvl+1);
    }
  
    vector<int> leftView(Node *root) {
         
        vector<int>ans;
        int lvl = 0;
        helper(root,ans,lvl);
        return ans;
        
    }
};