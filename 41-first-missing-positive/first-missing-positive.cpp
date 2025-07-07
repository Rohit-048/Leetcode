class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1; // if any no. is not in range if - or > n then
                                 // make it a large value
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num >= 1 && num <= n) {
                int idx = num - 1;
                if (nums[idx] > -1) {
                    nums[idx] *= -1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n+1;
    }
};
// the main idea here is to first of all mark all the numbers to a infinite value or unreachable value here marked n+1 as that is still unreachable. We do this to the elements which are either less than 0 or more than n

// now for the elements we iterate and take the abs value of that index and check if that num is >=1 and <=n then we make the index of that no. as -1 value
// for 5 we will make index 4 as -ve 

// ✅ Example Input:
// nums = [3, 4, -1, 1]
// We'll go through each step and explain it. You can add these as comments in your code:

// \U0001f9fe Step 1: Replace out-of-range numbers with n+1
// We ignore numbers ≤ 0 and > n (where n = 4), replacing them with 5.

// Initial:

// nums = [3, 4, -1, 1]
// After step 1:

// // Replace out-of-range values (<=0 or >n) with n+1
// // nums = [3, 4, 5, 1]
// \U0001f9fe Step 2: Use index marking
// Mark presence of num by making nums[num - 1] negative.

// Iteration 1: i = 0 → num = abs(3) = 3 → index = 2

// nums[2] = -5  // mark presence of 3
// Iteration 2: i = 1 → num = abs(4) = 4 → index = 3

// nums[3] = -1  // mark presence of 4
// Iteration 3: i = 2 → num = abs(-5) = 5 → skip (5 > n)

// Iteration 4: i = 3 → num = abs(-1) = 1 → index = 0

// nums[0] = -3  // mark presence of 1
// After step 2:

// // After marking: nums = [-3, 4, -5, -1]
// \U0001f9fe Step 3: Find first positive index
// Now we look for the first index where value is still positive.

// i = 1 → nums[1] = 4 → this means 2 is missing

// // First index with positive value is 1 → so answer = 1 + 1 = 2
// ✅ Final Answer:
// return 2;