class Solution {
public:
    int const MOD = 1'000'000'007;
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int N = types.size();
        long long F[1'001];
        memset(F, 0, sizeof(F));
        F[0] = 1;
        for (int j = 0; j < N; ++j)        
        {
            int const& count = types[j][0];
            int const& marks = types[j][1];
            for (int i = target; i > 0; --i)
            {                
                for (int k = i - marks, z = 0; k >= 0 && z < count; k -= marks, ++z)
                    F[i] += F[k];
                F[i] %= MOD;
            }
        }
        return F[target];
    }
};
