static int const MOD = 1'000'000'007;
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int const N = conversions.size() + 1;
        vector<vector<pair<int, int>>> connectivity(N);
        for (vector<int> const& c : conversions)
        {
            int const& sourceUnit = c[0];
            int const& targetUnit = c[1];
            int const& conversionFactor = c[2];
            connectivity[sourceUnit].push_back({ targetUnit, conversionFactor });
        }
        vector<int> result(N, -1);
        result[0] = 1;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for (auto [U, CF]: connectivity[V])
                if (result[U] < 0)
                {
                    result[U] = 1LL * CF * result[V] % MOD;
                    Q.push(U);
                }
        }
        return result;
    }
};
