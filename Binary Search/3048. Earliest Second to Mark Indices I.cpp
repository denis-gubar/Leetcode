class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int N = nums.size(), M = changeIndices.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total + N > M)
            return -1;
        int a = total + N - 1, b = M + 1;
        auto check = [&nums, &changeIndices, N, total](int m)
            {
                vector<int> last(N, m);
                vector<int> I(N);
                int T = 0;
                for (int i = 0; i < m; ++i)
                    last[changeIndices[i] - 1] = i;
                for (int x : last)
                    if (x >= m)
                        return false;
                iota(I.begin(), I.end(), 0);
                sort(I.begin(), I.end(), [&last](int a, int b)
                    {
                        return last[a] < last[b];
                    });
                for (int i = 0; i < N; ++i)
                {
                    int const pos = I[i];
                    if (last[pos] < nums[pos] + T)
                        return false;
                    T += nums[pos] + 1;
                }
                return true;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (check(m))
                b = m;
            else
                a = m;
        }
        if (b > M)
            return -1;
        return b;
    }
};
