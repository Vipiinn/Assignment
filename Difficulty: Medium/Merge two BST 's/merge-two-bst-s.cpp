

class Solution {
  public:
  
    void Inorder(Node* root , vector<int>& arr){
        if(root == NULL) return ;
        
        Inorder(root->left , arr);
        arr.push_back(root->data);
        Inorder(root->right , arr);
    }
    
    vector<int> mergeArray(vector<int>arr1 , vector<int>arr2){
        
        vector<int>ans;
        
        int i = 0;
        int j = 0;
        
        while(i < arr1.size() && j < arr2.size()){
            
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        
        while(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
        
        
    }
    
  
    vector<int> merge(Node *root1, Node *root2) {
        
        vector<int>arr1;
        
        Inorder(root1 , arr1);
        
        vector<int>arr2;
        
        Inorder(root2 , arr2);
        
        return mergeArray(arr1 , arr2);
        
        
    }
};