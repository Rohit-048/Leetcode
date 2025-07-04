class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kadane algorithm
        int n = nums.size();
        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
// take the max by adding the current element to the running sum or start from
// here
// if the current subarray sum becomes negative, it's better to discard it and
// start a new subarray from the next element