

class Solution {

  public:
  
    void Inorder(Node* root , vector<int>& ans){
        if(root == NULL) return ;
        Inorder(root->left , ans);
        ans.push_back(root->data);
        Inorder(root->right , ans);
    }
    
    Node* balanceTree(vector<int>& in , int st , int end){
        
        //base case
        if(st > end) return NULL;
        
        int mid = st + (end-st) / 2;
        
        Node* root = new Node(in[mid]);
        
        root->left = balanceTree(in , st , mid-1);
        root->right = balanceTree(in , mid+1 , end);
        
        return root;
        
    }
    
    
  
    Node* balanceBST(Node* root) {
        
        vector<int>in;
        Inorder(root,in);
        
        int n = in.size();
        
        root = balanceTree(in , 0 , n-1);
        
        return root;
    }
};