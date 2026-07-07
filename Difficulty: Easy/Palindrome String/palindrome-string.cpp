class Solution {
  public:
  
    bool checkPalindrome(string& s, int idx){
        
        if(idx >= s.length()){
            return true;
        }
        
        if(s[idx] != s[s.length()-idx-1]) return false;
        
        return checkPalindrome(s,idx+1);
    }
  
    bool isPalindrome(string& s) {
        
        return checkPalindrome(s , 0);
        
    }
};