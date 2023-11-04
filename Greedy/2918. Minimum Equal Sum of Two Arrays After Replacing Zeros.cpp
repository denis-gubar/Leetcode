class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int zero1 = 0, zero2 = 0;
        for (int i = 0; i < N1; ++i)
            zero1 += nums1[i] == 0;
        for (int i = 0; i < N2; ++i)
            zero2 += nums2[i] == 0;
        long long total1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long total2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        total1 += zero1;
        total2 += zero2;
        if (zero1 > 0 && zero2 > 0)
            return max(total1, total2);
        if (total1 == total2)
            return total1;
        if (zero1 > 0 && total1 < total2)
            return total2;
        if (zero2 > 0 && total1 > total2)
            return total1;
        return -1;
    }
};
