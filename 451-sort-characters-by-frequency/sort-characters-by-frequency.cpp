class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>> pq; // max heap to always get the max element

        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        string result="";
        while(!pq.empty()){
            result+=string(pq.top().first,pq.top().second); // this uses string function < string(count, char)> where it appends the char to number of times it has occured in the t
            pq.pop();
        }

        return result;
    }
};