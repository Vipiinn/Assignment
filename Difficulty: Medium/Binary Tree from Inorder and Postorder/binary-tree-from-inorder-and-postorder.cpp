

class Solution {
  public:
  
    Node* constructTree(vector<int>& in , vector<int>& post , int stIdx ,
                    int endIdx , int& postIdx , map<int,int>& mp){
                        
        //base case
        
        if(stIdx > endIdx) return NULL;
        
        Node* temp = new Node(post[postIdx--]);
        
        if(stIdx == endIdx) return temp;
        
        int idx = mp[temp->data];
        
        
        temp->right = constructTree(in,post,idx+1,endIdx,postIdx,mp);
        temp->left = constructTree(in,post,stIdx,idx-1,postIdx,mp);
        
        return temp;
                        
    }
  
    Node *buildTree(vector<int> &in, vector<int> &post) {
        
        int n = in.size();
        int stIdx = 0;
        int endIdx = n-1;
        
        int postIdx = n-1;
        
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        
        Node* root = constructTree(in,post,stIdx,endIdx,postIdx,mp);
        
        return root;
        
        
    }
};