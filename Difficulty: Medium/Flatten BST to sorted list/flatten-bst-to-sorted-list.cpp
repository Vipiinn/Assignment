/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void Inorder(Node* root , vector<int>& in){
        if(root == NULL) return;
        
        Inorder(root->left , in);
        in.push_back(root->data);
        Inorder(root->right , in);
    }
  
    Node *flattenBST(Node *root) {
        
        vector<int>in;
        Inorder(root , in);
        
        root = new Node(in[0]);
        Node* curr = root;
        
        int n = in.size();
        
        for(int i=1;i<n;i++){
            Node* temp = new Node(in[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        
        curr->left = NULL;
        curr->right = NULL;
        
        return root;
        
    }
};