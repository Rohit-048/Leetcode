class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c=0;
        for(int i=0;i<=30;i++)  //as int max is 2 pow 31
        {
            if((pow(2,i))==n)
            {
                c++;
            }
        }
        if(c==0)
        {
            return false;
        }
        else
        return true;
    }
};