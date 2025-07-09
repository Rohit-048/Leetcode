class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT;
        for (char c : t) {
            countT[c]++;
        }

        unordered_map<char, int> window;
        int have = 0, need = countT.size();
        int left = 0;
        int minLen = INT_MAX;
        int resStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                // update result
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    resStart = left;
                }

                // pop from left of window
                window[s[left]]--;
                if (countT.count(s[left]) && window[s[left]] < countT[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(resStart, minLen);
    }
};
