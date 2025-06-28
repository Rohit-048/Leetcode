class Solution {
public:
int help(vector<int>& nums, int goal)
{
    if(goal<0)
    {
        return 0;
    }
    int l=0;
        int r=0;
        int count=0;
        int sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum=sum-nums[l];
                l=l+1;
            }
            count=count+(r-l+1);
            r=r+1;
        }
        return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums,goal)-help(nums,goal-1);
    }
};

// when ever we try to find = thing we can implement the sliding window for at most
// help(nums, goal) gives number of subarrays with sum ≤ goal
// help(nums, goal - 1) gives number of subarrays with sum ≤ goal - 1
// Their difference gives subarrays where sum == goal
