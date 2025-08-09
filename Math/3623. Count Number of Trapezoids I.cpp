static int const MOD = 1'000'000'007;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int result = 0;
        unordered_map<int, int> M;
        for (vector<int> const& p : points)
        {
            int const& X = p[0];
            int const& Y = p[1];
            ++M[Y];
        }
        int V = 0;
        for (auto [key, value] : M)
        {
            if (value == 0)
                continue;
            int const X = 1LL * value * (value - 1) / 2 % MOD;
            result = (result + 1LL * X * V) % MOD;
            V = (V + X) % MOD;
        }
        return result;
    }
};
