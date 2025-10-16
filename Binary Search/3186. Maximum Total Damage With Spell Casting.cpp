class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long result = 0;
        map<int, int> M;
        for (int x : power)
            ++M[x];
        deque<pair<int, long long>> Q;
        Q.push_back({ -2, 0LL });
        for (auto [key, value] : M)
        {
            result = 0LL;
            pair<int, long long> P = Q.front();
            while (!Q.empty() && Q.front().first + 2 < key)
            {
                P.first = Q.front().first;
                P.second = max(P.second, Q.front().second);
                Q.pop_front();
                result = max(result, P.second + 1LL * key * value);
            }
            Q.push_front(P);
            Q.push_back({ key, result });
        }
        while (!Q.empty())
            result = max(result, Q.front().second), Q.pop_front();
        return result;
    }
};
