/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    int height(Node* root , int& dia){
        if(root == NULL) return 0;
        
        int lh = height(root->left , dia);
        int rh = height(root->right , dia);
        
        dia = max(dia , lh+rh);
        
        return 1 + max(lh,rh);
    }
  
    int diameter(Node* root) {
        
        int dia = 0;
        
        int ans = height(root , dia);
        
        return dia;
        
    }
};