class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long total = 1, result = 1LL << 40;
        int const N = nums1.size();
        for (int i = 0; i < N; ++i)
            total += abs(nums2[i] - nums1[i]);
        int const x = nums2[N];
        for (int i = 0; i < N; ++i)
        {
            int const a = min(nums1[i], nums2[i]), b = max(nums1[i], nums2[i]);
            if (a <= x && x <= b)
                return total;
            result = min(result, total + min(abs(x - a), abs(x - b)));
        }
        return result;
    }
};
