class Solution {
  public:
  
    void leftBoundary(Node *root , vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        ans.push_back(root->data);
        
        if(root->left)
            leftBoundary(root->left , ans);
        else
            leftBoundary(root->right , ans);
    }
    
    void bottomBoundary(Node* root , vector<int>& ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        bottomBoundary(root->left , ans);
        bottomBoundary(root->right , ans);
    }
    
    void rightBoundary(Node* root , vector<int>&ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        
        if(root->right)
            rightBoundary(root->right , ans);
        else
            rightBoundary(root->left , ans);
            
        ans.push_back(root->data);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        ans.push_back(root->data);          // root
        
        leftBoundary(root->left, ans);      // left boundary
        bottomBoundary(root->left, ans);    // leaves
        bottomBoundary(root->right, ans);
        rightBoundary(root->right, ans);    // right boundary
        
        return ans;
    }
};
