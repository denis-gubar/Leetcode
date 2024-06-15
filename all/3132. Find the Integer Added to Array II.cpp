class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int N = nums1.size();
        auto check = [&nums1, &nums2, N, M = N - 2](int X)
            {
                int count = 0, b = 0;
                for (int z : nums1)
                {
                    int x = z + X;
                    if (b < M && x == nums2[b])
                        ++b;
                    else
                        if (++count > 2)
                            return false;
                }
                return true;
            };
        for (int x = -1000; x <= 1000; ++x)
        {
            if (check(x))
                return x;            
        }
        return -1337;
    }
};
