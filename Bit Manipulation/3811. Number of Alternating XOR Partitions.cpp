static const int MOD = 1'000'000'007;
static int F[100'000][2];
class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int const N = nums.size();
        unordered_map<int, int> M1, M2;
        ++M1[0], ++M2[0];
        memset(F, 0, sizeof(F));
        int total = 0;
        for (int i = N - 1; i > 0; --i)
        {
            total ^= nums[i];
            int t1 = total ^ target1, t2 = total ^ target2;
            int v1 = 0, v2 = 0;
            if (M2.find(t1) != M2.end())
                v1 = M2[t1];
            if (M1.find(t2) != M1.end())
                v2 = M1[t2];
            if (v1 > 0)
                M1[total] = (M1[total] + v1) % MOD;
            if (v2 > 0)
                M2[total] = (M2[total] + v2) % MOD;
        }
        return M2[total ^ nums[0] ^ target1];
    }
};
