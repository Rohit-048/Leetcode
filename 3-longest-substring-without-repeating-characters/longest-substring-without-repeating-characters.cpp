class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxLen=0;
        set<char> charSet;
        while(right<n){
            if(charSet.find(s[right])==charSet.end()){
                charSet.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
                right++;
            }
            else{
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};