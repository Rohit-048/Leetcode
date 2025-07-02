class Solution {
public:
    string reverseWords(string s) {
        string res="";
        vector<string> result;
        reverse(s.begin(),s.end());
        string word="";
        for(char c:s){

            if(c!=' '){
                word+=c;
            }
            else if(!word.empty()){
                reverse(word.begin(),word.end());
                result.push_back(word);
                word="";
            }
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());
            result.push_back(word);
             
        }
        for(int i=0;i<result.size();i++){
            res+=result[i];
            if(i!=result.size()-1){
                res+=" ";
            }
        }
        return res;
    }
};