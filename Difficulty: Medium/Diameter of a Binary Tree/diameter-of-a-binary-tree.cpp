

class Solution {
  public:
  
    int height(Node* root){
        
        if(root == NULL) return -1;
        
        return 1 + max(height(root->left) , height(root->right));
    }
  
    int diameter(Node* root) {
        
        //base case
        if(root == NULL) return 0;
        
        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->left) + height(root->right) + 2;
        
        int ans = max(opt1 , max(opt2,opt3));
        return ans;
        
    }
};