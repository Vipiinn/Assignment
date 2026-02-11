
class Solution {
  public:
 
    int findIndex(vector<int>& in , int val){
        
        for(int i=0;i<in.size();i++){
            if(in[i] == val) return i;
        }
        return -1;
    }
  
  
    Node* constructTree(vector<int>& in , vector<int>& pre , int stIdx , int endIdx,int &preIdx){
        //base case
        if(stIdx > endIdx) return NULL;
        
        Node* temp = new Node(pre[preIdx++]);
        
        if(stIdx == endIdx) return temp;
        
        int idx = findIndex(in,temp->data);
        
        temp->left = constructTree(in,pre,stIdx,idx-1,preIdx);
        temp->right = constructTree(in,pre,idx+1,endIdx,preIdx);
        
        return temp;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        
        int n = inorder.size();
        int stIdx = 0;
        int endIdx = n-1;
        int preIdx = 0;
        
        Node* root = constructTree(inorder,preorder,stIdx,endIdx,preIdx);
        
        return root;
        
    }
};