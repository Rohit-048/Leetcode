class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            if (prefixCount.find(sum - goal) != prefixCount.end()) {
                count += prefixCount[sum - goal];
            }

            prefixCount[sum]++;
        }

        return count;
    }
};
// We store how many times each prefix sum has occurred.
// If sum - goal was seen before, that means we found a subarray that ends here and sums to goal.
// This counts all valid subarrays, not just one per position.
