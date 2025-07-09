class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, res = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (freq[nums[right]] == 0) { // new unique
                k--;
            }
            freq[nums[right]]++;

            while (k < 0) { // too many unique
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    k++; // lost one unique
                }
                left++;
            }

            res += right - left + 1; // all subarrays ending at right
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
