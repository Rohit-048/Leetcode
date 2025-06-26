class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int res = *max_element(nums.begin(), nums.end());
        int curMax = 1, curMin = 1;

        for (int n : nums) {
            int temp = curMax * n;
            curMax = max({temp, curMin * n, n});
            // for cases where two -ve can make larger +ve value
            curMin = min({temp, curMin * n, n}); 
            

            res = max(res, curMax);
        }

        return res;   
    }
};