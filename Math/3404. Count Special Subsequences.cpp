static int A[1'001][1'001];
class Solution {
public:
    unordered_map<int, vector<int>> M;
    vector<int> calc(int x)
    {
        if (M.find(x) == M.end())
        {
            for (int k = 1; k * k <= x; ++k)
                if (x % k == 0 && x / k <= 1'000)
                {
                    M[x].push_back(k);
                    if (k * k != x)
                        M[x].push_back(x / k);
                }
        }
        return M[x];
    }
    long long numberOfSubsequences(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= 1'000; ++i)
            for (int j = 0; j < N; ++j)
                A[i][j + 1] = A[i][j] + (nums[j] == i);
        auto F = [](int V, int L, int R)
            {
                if (L > R)
                    return 0;
                return A[V][R + 1] - A[V][L];
            };
        for(int p = 0; p < N; ++p)
            for (int r = p + 4; r < N - 2; ++r)
            {
                int prv = nums[p] * nums[r];
                vector<int> divs = calc(prv);
                for (int qv : divs)
                {
                    int const qCount = F(qv, p + 2, r - 2);
                    if (qCount > 0)
                    {
                        int const sv = prv / qv;
                        int const sCount = F(sv, r + 2, N - 1);
                        result += qCount * sCount;
                    }
                }
            }
        return result;
    }
};
