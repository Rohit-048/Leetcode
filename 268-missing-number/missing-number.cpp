class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> freqMap(n + 1, 0);
        for(int i:nums){
            freqMap[i]++;
        }
        for(int i=0;i<=n;i++){
            if(freqMap[i]==0){
                return i;
            }
        }
        return -1;
    }
};