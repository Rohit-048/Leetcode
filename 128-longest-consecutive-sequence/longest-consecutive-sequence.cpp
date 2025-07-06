class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setMap(nums.begin(),nums.end());
        

        // the core idea is to find that for any n the n-1 is not in the set means
        // n is the start of the set
        int maxLen=0;
        for(int i:setMap){
            if(!setMap.count(i-1)){ //ensure this is start of seq
                int currVal=i;
                int currLen=1;
                while(setMap.count(currVal+1)){
                    currVal++;
                    currLen++;
                }
                maxLen=max(maxLen,currLen);

            }
        }
        return maxLen;
    }
};