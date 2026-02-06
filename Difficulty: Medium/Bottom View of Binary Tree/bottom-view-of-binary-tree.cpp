
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        vector<int>ans;
        if(root == NULL) return ans;
        
        map<int,map<int,vector<int>>>mp; // (hd,(level,list))
        queue<pair<Node* ,pair<int,int>>>q; // (Node,(hd,level))
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(q.size() > 0){
            pair<Node* ,pair<int,int>> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            mp[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left , make_pair(hd-1 , lvl+1)));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right , make_pair(hd+1 , lvl+1)));
            }
        }
        
        for(auto i : mp){
            vector<int>temp;
            for(auto j : i.second){
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
        
    }
};