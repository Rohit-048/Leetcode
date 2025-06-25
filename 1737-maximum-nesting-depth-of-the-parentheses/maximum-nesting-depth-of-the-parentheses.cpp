class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxCount=0;
        int currCount=0;
        int open=0;
        int close=0;
        stack<int> st;
        for(char ch:s){
            currCount=0;
            if(ch=='('){
                st.push(ch);
                open++;
            }
            else if(ch==')'){
                st.pop();
                open--;
                close++;
            }
            // else {
            //     currCount=open;
            // }
             currCount=open;
            maxCount=max(maxCount,currCount);
           
        }
        if(st.empty()){
            return maxCount;
        }
        return -1;
    }
};