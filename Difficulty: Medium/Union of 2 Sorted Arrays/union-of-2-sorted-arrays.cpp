class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        set<int>s;
        
        for(int i=0;i<a.size();i++){
            s.insert(a[i]);
        }
        
        for(int i=0;i<b.size();i++){
            s.insert(b[i]);
        }
        
        return vector<int>(s.begin(),s.end());
        
        
    }
};