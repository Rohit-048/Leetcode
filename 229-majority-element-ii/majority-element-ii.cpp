class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freqMap;
        vector<int> result;
        for(int i: nums){
            freqMap[i]++;
        }

        for(auto it: freqMap){
            if(it.second>n/3){
                result.push_back(it.first);
            }
        }
        return result;
        
    }
};