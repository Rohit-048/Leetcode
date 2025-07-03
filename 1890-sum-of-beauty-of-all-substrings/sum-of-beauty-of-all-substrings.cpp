class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                int minVal = INT_MAX;
                int maxVal = INT_MIN;
                for (auto& it : mp) {
                    minVal = min(minVal, it.second);
                    maxVal = max(maxVal, it.second);
                }
                sum += (maxVal - minVal);
            }
        }
        return sum;
    }
};