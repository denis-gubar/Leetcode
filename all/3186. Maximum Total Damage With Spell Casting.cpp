class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long result = 0;
        int N = power.size();
        map<int, int> M;
        map<int, long long> F;
        F[-2] = 0;
        for (int x : power)
            ++M[x];
        for (auto [key, value] : M)
        {
            auto it = F.lower_bound(key - 2);
            --it;
            F[key] = max(F[key], it->second + 1LL * key * value);
            auto itF = F.find(key);
            --itF;
            F[key] = max(F[key], itF->second);
            result = max(result, F[key]);
        }
        return result;
    }
};
