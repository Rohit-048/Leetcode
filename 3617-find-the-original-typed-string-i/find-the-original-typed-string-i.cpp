class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int count=1; // as right now the word given can also be correct
        set<int> s;
        for(int i=1;i<n;i++){
            s.insert(word[i]);
            if((word[i]==word[i-1]) && s.find(word[i])!=s.end()){
                count++;
            }
        }
        return count;
    }
};