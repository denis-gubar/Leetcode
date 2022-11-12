class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int A = nums1.size();
        int B = nums2.size();
        if (B % 2 == 1)
        {
            for (int x : nums1)
                result ^= x;
        }
        if (A % 2 == 1)
            for (int x : nums2)
                result ^= x;
        return result;
    }
};
