

class Solution {
  public:
  
    
    void view(Node* root , int level , vector<int>& ds){
        
        if(root == NULL) return;
        
        if(ds.size() == level) ds.push_back(root->data);
        
        //preorder
        view(root->left , level+1 , ds);
        view(root->right , level+1 , ds);
    }
    
  
    vector<int> leftView(Node *root) {
        
        vector<int>ds;
        
        view(root , 0 , ds);
        
        return ds;
        
    }
};