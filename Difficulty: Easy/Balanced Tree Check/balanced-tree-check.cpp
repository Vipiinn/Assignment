
class Solution {
  public:
  
    int height(Node* root){
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right) + 1;
    }
  
    bool isBalanced(Node* root) {
        
        if(root == NULL) return true;
        
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(leftAns && rightAns && diff) return true;
        else return false;
        
    }
};