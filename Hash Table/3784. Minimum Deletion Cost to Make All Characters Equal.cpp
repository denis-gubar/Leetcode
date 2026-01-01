class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int const N = s.size();
        unordered_map<char, long long> M;
        long long total = 0;
        for (int i = 0; i < N; ++i)
            M[s[i]] += cost[i], total += cost[i];
        long long result = total;
        for (auto [key, value] : M)
            result = min(result, total - value);
        return result;
    }
};
