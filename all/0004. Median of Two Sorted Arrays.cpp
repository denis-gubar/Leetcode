class Solution {
public:
    int const INF = 1 << 20;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            nums1.swap(nums2);
        int N = nums1.size(), M = nums2.size();
        int a = 0, b = N;
        while (a <= b)
        {
            int m1 = (a + b) / 2;
            int m2 = (N + M + 1) / 2 - m1;

            int a1 = m1 == 0 ? -INF : nums1[m1 - 1];
            int a2 = m2 == 0 ? -INF : nums2[m2 - 1];
            int b1 = m1 == N ? INF : nums1[m1];
            int b2 = m2 == M ? INF : nums2[m2];

            if (a1 <= b2 && a2 <= b1)
            {
                if ((N + M) % 2 == 0)
                    return 0.5 * (max(a1, a2) + min(b1, b2));
                return 1.0 * max(a1, a2);
            }
            else if (a1 > b2)
                b = m1 - 1;
            else
                a = m1 + 1;
        }
        return -INF;
    }
};

