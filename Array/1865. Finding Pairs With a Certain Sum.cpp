class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1(nums1), nums2(nums2) {
        sort(this->nums1.begin(), this->nums1.end());
        this->nums1.push_back(1 << 30);
        for (int x : nums2)
            ++M[x];
    }
    
    void add(int index, int val) {
        --M[nums2[index]];
        nums2[index] += val;
        ++M[nums2[index]];
    }
    
    int count(int tot) {
        int result = 0;
        for (int i = 0; nums1[i] <= tot; ++i)
            result += M[tot - nums1[i]];
        return result;
    }
    int N;
    unordered_map<int, int> M;
    vector<int> nums1, nums2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
