class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int i: nums){
            numSet.insert(i);
        }
        return (numSet.size()<nums.size());
        
    }
};