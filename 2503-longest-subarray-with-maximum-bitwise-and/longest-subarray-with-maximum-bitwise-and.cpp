class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLength = 0, currentLength = 0;

        // Traverse the array to find the longest subarray with maximum value
        for (int num : nums) {
            if (num == maxVal) {
                // If the current number is the max value, increase the current length
                currentLength++;
            } else {
                // Reset the current length as the subarray is broken
                currentLength = 0;
            }
            // Update the maximum length found
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};