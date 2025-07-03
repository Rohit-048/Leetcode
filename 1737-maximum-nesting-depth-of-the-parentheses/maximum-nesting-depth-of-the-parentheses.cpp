class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int open=0;
        int close=0;
        int currCount=0,maxCount=0;
        for(char ch:s){
            if(ch=='('){
                open++;
                st.push(ch);
            }
            else if(ch==')'){
                st.pop();
                open--;
                close++;
            }
            currCount=open; // it has the max depth at each iteration 
            maxCount=max(maxCount,currCount);
        }
        return maxCount;
    }
};