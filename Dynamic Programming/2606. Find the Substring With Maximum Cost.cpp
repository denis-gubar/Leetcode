class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int N = s.size(), M = chars.size();
        int result = 0;
        vector<int> costs(26);
        iota(costs.begin(), costs.end(), 1);
        for (int i = 0; i < M; ++i)
            costs[chars[i] - 'a'] = vals[i];
        int prev = 0;
        int balance = 0;
        for (int i = 0; i < N; ++i)
        {
            balance += costs[s[i] - 'a'];
            result = max(result, balance - prev);
            if (balance < prev)
                prev = balance;
        }
        return result;
    }
};
