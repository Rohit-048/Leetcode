class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool> mp;
        
        for(int i:nums){
           if(i>0){
            mp[i]=true;
           }
        }

        for(int i=1;i<=n+1;i++){
            if(!mp[i]){ // checking if we have seen this element
                return i;
            }
            
        }
        
        return -1;

    }
};