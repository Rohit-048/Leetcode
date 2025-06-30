class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int currCount = 0, maxCount = 0;

        for (int i : nums) {
            mp[i]++;
        }
        for (auto& it : mp) {
            if (mp.count(it.first + 1)) {
                maxCount = max(maxCount, it.second + mp[it.first + 1]);
            }
        }

        return maxCount;
    }
};