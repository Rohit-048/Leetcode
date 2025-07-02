class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(),piles.end());
        int k=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long  hours=0;
            
            for(int p:piles){
                hours+=(p+mid-1)/mid; // for the division instead of using ceil 
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

// Step 1: Understand the behavior of ceil(a / b)

// We want:

// If a % b == 0 → ceil(a / b) = a / b
// If a % b != 0 → ceil(a / b) = (a / b) + 1
// But how do we simulate this with integer math?

// ✅ Step 2: Try to "force a round up"

// Let’s try some small values:

// a	b	a / b	ceil(a / b)
// 7	3	2.33	3
// 10	3	3.33	4
// 6	2	3	3
// Now, observe:

// How much do we need to add to the numerator so that it rounds up when using integer division?
// Answer: Just less than b. So the safe max is b - 1.

// Try:

// (a + b - 1) / b
// (7 + 2) / 3 = 9 / 3 = 3 ✅
// (10 + 2) / 3 = 12 / 3 = 4 ✅
// (6 + 1) / 2 = 7 / 2 = 3 ✅
// It’s working!

