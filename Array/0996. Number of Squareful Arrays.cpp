static int F[12][12][1 << 12];
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int result = 0, div = 1;
        unordered_map<int, int> M;
        for (int x : nums)
            div *= ++M[x];
        int const N = nums.size();
        memset(F, 0, sizeof(F));
        vector<vector<int>> Next(N);
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j)
                {
                    int const x = nums[i] + nums[j];
                    int const r = sqrt(x);
                    if (r * r == x)
                        Next[i].push_back(j);
                }
        for (int j = 0; j < N; ++j)
            F[0][j][1 << j] = 1;
        for (int i = 1; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int mask = 0; mask < (1 << N); ++mask)
                    if (F[i - 1][j][mask])
                        for (int nj : Next[j])
                            if ((mask & (1 << nj)) == 0)
                                F[i][nj][mask | (1 << nj)] += F[i - 1][j][mask];
        for (int j = 0; j < N; ++j)
            result += F[N - 1][j][(1 << N) - 1];
        return result / div;
    }
};
