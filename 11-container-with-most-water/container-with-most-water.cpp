class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxVol=0;
        int area=0;
        int left=0, right=n-1;
        while(left<right){
            int len=min(height[left],height[right]);
            int br=right-left;
            maxVol=max(maxVol,len*br);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        

        return maxVol;
    }
};