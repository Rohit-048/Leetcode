class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;

        // this problem wants us to find the longest window where max 2 distinct
        // elements are allowed
        while (right < n) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

// when a fruit comes we add it to the map
// when the size of map increases >2 we remove the count of the left part and keep doing it until the size if again 2

// fruits = [1, 2, 1, 2, 3]
// Step by step:
// right	fruit	map	        left	        window	maxLen
// 0	        1	{1:1}	    0	                [1]	1
// 1	        2	{1:1, 2:1}	0	                [1,2]	2
// 2	        1	{1:2, 2:1}	0	                [1,2,1]	3
// 3	        2	{1:2, 2:2}	0	                [1,2,1,2]	4
// 4	        3	{1:2, 2:2, 3:1} ❌	0	✂ Shrink	
// Now size > 2, so shrink:

// left = 0 → fruit=1 → count=1 → map={1:1,2:2,3:1}
// left = 1 → fruit=2 → count=1 → map={1:1,2:1,3:1}
// left = 2 → fruit=1 → count=0 → remove 1 → map={2:1,3:1}
// → Now window = [2,3] and valid again → update maxLen = max(4, 2) = 4

