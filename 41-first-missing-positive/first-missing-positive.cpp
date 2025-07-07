class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        set<int> setMap;
        
        for(int i:nums){
            setMap.insert(i);
        }
       
        for(int i=1;i<=n+1;i++){
            if(setMap.find(i)==setMap.end()){
                return i;
            }
            
        }
        
        return -1;

    }
};