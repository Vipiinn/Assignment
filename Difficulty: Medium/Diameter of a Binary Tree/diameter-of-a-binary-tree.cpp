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
        
        int left = height(root->left , dia);
        int right = height(root->right , dia);
        
        dia = max(dia , left + right);
        
        return 1 + max(left , right);
    }
  
    int diameter(Node* root) {
        
        int dia = 0;
        
        height(root , dia);
        
        return dia;
        
    }
};