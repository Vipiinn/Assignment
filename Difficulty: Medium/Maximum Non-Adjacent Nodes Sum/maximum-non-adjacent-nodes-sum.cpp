

class Solution {
  public:
  
    pair<int,int> solve(Node* root){
        
        if(root == NULL) return {0,0};
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int>ans;
        
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first , left.second) + max(right.first , right.second);
        
        return ans;
        
    }
  
    int getMaxSum(Node *root) {
        
        pair<int,int> maxAns = solve(root);
        
        return max(maxAns.first , maxAns.second);
        
        
    }
};