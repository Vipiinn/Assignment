/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    
    bool solve(Node* root , int node , vector<int>& path){
        //base base 
        if(root == NULL) return false;
        
        path.push_back(root->data);
        
        if(root->data == node){
            return true;
        } 
        
        bool left = solve(root->left , node , path);
        bool right = solve(root->right , node , path);
        
        if(left || right) return true;
    
        path.pop_back();
        
        return false ;
        
    }
  
    int kthAncestor(Node *root, int k, int node) {
        
        vector<int>path;
        
        bool ans = solve(root , node ,path);
        if(ans == false) return -1;
        
        int n = path.size();
        
        if(k >= n) return -1;
        else return path[n-1-k];
        
        
        
    }
};
