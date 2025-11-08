// User function template for C++

class Solution {
  public:
    string removeSpecialCharacter(string s) {
        string str = "";
        
        for(int i=0;i<s.length();i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                str += s[i];
            }
        }
        
        if(str == "") return "-1";
        else return str;
        
    }
};