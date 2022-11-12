class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long result = 0;
        int N = costs.size();
        set<pair<int, int>> L, R;
        for (int i = 0; i < candidates; ++i)
            L.insert({ costs[i], i });
        for (int i = N - candidates; i < N; ++i)
            R.insert({ costs[i], i });
        int a = candidates, b = N - candidates - 1;
        for (int i = 0; i < k; ++i)
        {
            pair<int, int> P{100'001, 0};
            if (!L.empty())
                P = min(P, *L.begin());
            if (!R.empty())
                P = min(P, *R.begin());
            result += P.first;
            if (auto it = L.find(P); it != L.end())
                L.erase(it);
            if (auto it = R.find(P); it != R.end())
                R.erase(it);
            if (a <= b)
            {
                if (L.size() < candidates)
                    L.insert({ costs[a], a }), ++a;
                if (R.size() < candidates)
                    R.insert({ costs[b], b }), --b;                
            }
        }
        return result;
    }
};
