class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int N = nums.size();
        int a = 1, b = N + 1;
        auto calc = [&nums, N, k](int m)
            {
                unordered_map<int, int> M;
                int longCount = 0;
                for (int i = 0; i < N; ++i)
                {
                    if (++M[nums[i]] == k + 1)
                        ++longCount;
                    if (i >= m)
                    {
                        if (--M[nums[i - m]] == k)
                            --longCount;
                    }
                    if (i >= m - 1 && longCount == 0)
                        return true;
                }
                return false;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
