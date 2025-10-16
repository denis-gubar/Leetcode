class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long result = 0;
        int const N = value.size();
        vector<pair<int, int>> P(N);
        map<int, int> M;
        for (int i = 0; i < N; ++i)
            P[i] = { limit[i], -value[i] };
        sort(P.begin(), P.end());
        for (int i = 0; i < N; ++i)
            P[i].second = -P[i].second;
        multiset<int> S;
        int inactiveCount = 0;
        int HWM = 0;
        for (int i = 0; i < N; ++i)
        {
            if (P[i].first <= HWM)
                continue;
            S.insert(P[i].second);
            while (S.size() > P[i].first + inactiveCount)
                S.erase(S.begin());
            ++M[P[i].first];
            for (auto it = M.begin(); it != M.end(); )
            {
                if (it->first > S.size() - inactiveCount)
                    break;
                inactiveCount += it->second;
                HWM = max(HWM, it->first);
                it = M.erase(it);
            }
        }
        for (int x : S)
            result += x;
        return result;
    }
};
