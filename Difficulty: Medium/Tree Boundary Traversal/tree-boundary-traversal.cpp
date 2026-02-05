

class Solution {
  public:
  
    void leftBoundary(Node* root , vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        ans.push_back(root->data);
        
        if(root->left) leftBoundary(root->left,ans);
        else leftBoundary(root->right,ans);
    }
    
    void leafNode(Node* root , vector<int>& ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
            
        leafNode(root->left,ans);
        leafNode(root->right,ans);
        
    }

    
    void rightBoundary(Node* root , vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        if(root->right) rightBoundary(root->right,ans);
        else rightBoundary(root->left , ans);
        ans.push_back(root->data);
        
    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        if(root == NULL) return ans;
        ans.push_back(root->data);
        
        leftBoundary(root->left,ans);
        leafNode(root->left,ans);
        leafNode(root->right , ans);
        rightBoundary(root->right,ans);
        
        
        return ans;
        
    }
};