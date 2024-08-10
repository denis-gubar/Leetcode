static int F[100'000];
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int N, vector<vector<int>>& queries) {
        int const Q = queries.size();
        vector<int> result(Q);
        for (int i = 0; i < N; ++i)
            F[i] = 0;
        set<pair<int, int>> S;
        for (int q = 0; q < Q; ++q)
        {
            int const& V = queries[q][0];
            int const& U = queries[q][1];
            S.insert({ V, U });
            auto it = S.lower_bound({ V, 0 });
            for (int i = V; i < N; ++i)
            {
                if (i > 0)
                    F[i] = max(F[i], F[i - 1]);
                while (it != S.end() && it->first == i)
                    F[it->second] = max(F[it->second], F[i] + it->second - it->first - 1), ++it;
            }
            result[q] = N - 1 - F[N - 1];
        }
        return result;
    }
};
