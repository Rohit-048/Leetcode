class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freqMap;
            for(int j=i;j<n;j++){
                freqMap[s[j]]++;

                int minVal=INT_MAX;
                int maxVal=INT_MIN;

                for(auto &p: freqMap){
                    minVal=min(minVal,p.second);
                    maxVal=max(maxVal,p.second);
                }
                sum+=(maxVal-minVal);
            }
       
        }
        return sum;

    }
};