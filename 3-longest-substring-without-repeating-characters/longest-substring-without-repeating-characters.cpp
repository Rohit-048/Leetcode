class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int currLen = 0;
        unordered_set<char> setMap;
        while (right < n) {
            if (setMap.find(s[right]) == setMap.end()) {
                currLen = right - left + 1;
                setMap.insert(s[right]);
                maxLen = max(maxLen, currLen);
                right++;
            } else {
                setMap.erase(s[left]);
                //currLen = right - left + 1;
                left++;
            }
        }

        return maxLen;
    }
};