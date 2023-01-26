class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int N = nums1.size();
        if (k == 0)
        {
            return (nums1 == nums2) - 1;
        }
        long long A = 0, B = 0;
        for (int i = 0; i < N; ++i)
        {
            int const& x = nums1[i];
            int const& y = nums2[i];
            if (abs(x - y) % k != 0)
                return -1;
            if (x == y)
                continue;
            if (x < y)
                A += (y - x) / k;
            else
                B += (x - y) / k;
        }
        if (A != B)
            return -1;
        return A;
    }
};
