class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        int lucky=INT_MIN;
        unordered_map<int,int> mp;
        for(int i: arr){
            mp[i]++;
        }
        for(auto &it: mp){
            if(it.first==it.second){
               lucky=max(lucky,it.first);
            }
        }
        if(lucky>0){
            return lucky;
        }
        return -1;
    }
};