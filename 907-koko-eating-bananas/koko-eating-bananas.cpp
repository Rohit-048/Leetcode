class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(),piles.end());
        int k=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long  hours=0;
            
            for(int p:piles){
                hours+=ceil((double)p/mid);
            }

            if(hours<=h){
                k=min(k,mid);
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return k;
    }
};
