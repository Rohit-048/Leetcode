class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(char c:s){
            if(isalnum(c)){
                str+=tolower(c);
            }
        }
        int n=str.length();
        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-1-i]){
                return false;
            }
        }
        return true;
    }
};