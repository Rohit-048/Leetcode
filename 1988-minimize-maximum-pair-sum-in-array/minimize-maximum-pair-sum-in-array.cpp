class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxSum=0;
        int n=nums.size();
        int j=n-1;  // using two pointer approach here
        // sorting the nums array
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            maxSum=max(maxSum,nums[i]+nums[j]);  //max pair sum
            j--; 
        }
        return maxSum;
    }
};