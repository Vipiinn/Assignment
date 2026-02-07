

class Solution {
  public:
  
    void helper(Node* root , vector<int>&ans , int lvl){
        
        if(root == NULL) return ;
        
        if(ans.size() == lvl){
            ans.push_back(root->data);
        }
        
        helper(root->right , ans , lvl+1);
        helper(root->left , ans , lvl+1);
    }
  
    vector<int> rightView(Node *root) {
        
        vector<int>ans;
        helper(root,ans,0);
        return ans;
        
    }
};