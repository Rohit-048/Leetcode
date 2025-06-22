class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> res;
        for(int i=0;i<n;i+=k){
            string str="";
            for(int j=i;j<k+i;j++){
                if(j<n){
                    str+=s[j];
                }
                
            }
            int l1=str.length();
            if(l1==k){
                res.push_back(str);
            }
            else{
                for(int i=0;i<k-l1;i++){
                    str+=fill;
                }
                res.push_back(str);
            }
            
        }
        return res;
    }
};