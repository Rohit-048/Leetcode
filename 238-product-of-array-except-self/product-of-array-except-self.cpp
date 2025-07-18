class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int prefix = 1;

        for (int i = 0; i < n; i++) { // finding the prefix product
            result[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix; // find the suffix product
            suffix *= nums[i];
        }
        return result;
    }
};