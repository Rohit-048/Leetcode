class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int currCount=0, maxCount=0;

        for(int i: nums){
            mp[i]++;
        }
        for(auto &it:mp){
            currCount=0;
            for(auto & p: mp){
                if(it.first+1==p.first){
                    currCount+=p.second;
                    currCount+=it.second;
                }
            }
            maxCount=max(maxCount,currCount);
        }
        return maxCount;
    }
};