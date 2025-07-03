class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int currMax = 1, fMax = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                continue;

            if (nums[i] - 1 == nums[i - 1]) {
                currMax++;
            } else {

                currMax = 1;
            }
            fMax = max(fMax, currMax);
        }
        return fMax;
    }
};