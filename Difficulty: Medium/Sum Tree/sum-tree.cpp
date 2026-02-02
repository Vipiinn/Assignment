
class Solution {
  public:
  
    pair<bool,int>isSumTreeFast(Node* root){
        
        if(root == NULL) return {true,0};
        
        if(root->left == NULL && root->right == NULL){
            return {true,root->data};
        }
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool check = (left.second + right.second == root->data);
        
        pair<bool,int> ans;
        
        if(left.first && right.first && check){
            ans = {true , left.second + right.second + root->data};
        }
        else {
            ans = {false , left.second + right.second + root->data};
        }
        
        return ans;
    }
  
    bool isSumTree(Node* root) {
        
        return isSumTreeFast(root).first;
    }
};