class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            int a = asteroids[i];
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop(); // the top of stack gets destroyed
                    continue;
                } else if (abs(st.top()) == abs(a)) {
                    st.pop(); // both get destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(a);
            }
        }
        vector<int> res(st.size());
        for(int i=st.size()-1;i>=0;--i){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};