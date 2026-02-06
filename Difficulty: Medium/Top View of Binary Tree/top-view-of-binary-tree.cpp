

class Solution {
  public:
    vector<int> topView(Node *root) {
        
        vector<int>ans;
        
        if(root == NULL) return ans;
         
        map<int,int>mp; // type(hd,root->data)
        queue<pair<Node*,int>>q; //type(Node* , level)
        
        q.push(make_pair(root , 0));
        
        while(q.size() > 0){
            
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left , hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right , hd+1));
            }
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};