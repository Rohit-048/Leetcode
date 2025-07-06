class FindSumPairs {
public:
    vector<int> nums1, nums2;
    int n1, n2;
    unordered_map<int,int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        n1 = nums1.size();
        n2 = nums2.size();
        for(int i: nums2){
            mp[i]++;
        }

    }

    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
         mp[nums2[index]]++; 
        }

    int count(int tot) {
        int count = 0;
        
            for (int j = 0; j < n1; j++) {
                int target=tot-nums1[j];
                if (mp.find(target)!=mp.end()) {
                    count+=mp[target];
                    
                }
            }
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */