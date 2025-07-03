class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int currCount=0, fCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                currCount++;
            }
            else{
                
                currCount=0;
            }
            fCount=max(fCount,currCount);
        }
        return fCount;
    }
};