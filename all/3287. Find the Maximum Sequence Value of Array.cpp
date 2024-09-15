static bitset<128> L[401][202];
static bitset<128> R[401][202];
class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int result = 0;
        int const N = nums.size();
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        L[0][0][0] = 1;
        R[N][0][0] = 1;
        for(int i = 0; i < N; ++i)
            for (int j = 0, jMax = min(k, i); j <= jMax; ++j)
            {
                L[i + 1][j] |= L[i][j];
                for (int z = 0; z < 128; ++z)
                    if (L[i][j][z])
                        L[i + 1][j + 1][z | nums[i]] = 1;
            }
        for (int i = N; i > 0; --i)
            for (int j = 0, jMax = min(k, N - i); j <= jMax; ++j)
            {
                R[i - 1][j] |= R[i][j];
                for (int z = 0; z < 128; ++z)
                    if (R[i][j][z])
                        R[i - 1][j + 1][z | nums[i - 1]] = 1;
            }
        for(int i = k; i + k <= N; ++i)
            for(int z = 1; z < 128; ++z)
                if (L[i][k][z])
                    for(int z2 = 1; z2 < 128; ++z2)
                        if (R[i][k][z2])
                            result = max(result, z ^ z2);
        return result;
    }
};
