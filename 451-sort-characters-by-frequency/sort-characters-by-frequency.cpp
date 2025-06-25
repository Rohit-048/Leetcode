class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freqMap;
        for(char c: s){
            freqMap[c]++;
        }

        // to sort it based on  values we will take a vector of pair and then do it
        vector<pair<char,int>> freqVec(freqMap.begin(),freqMap.end());

        // to sort based on the values given to us 
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // descending
        });

        // forming the result;
        string result="";
        for(auto &p:freqVec){
            for(int i=0;i<p.second;i++){
                result+=p.first;
            }
        }
        return result;
    }
};

