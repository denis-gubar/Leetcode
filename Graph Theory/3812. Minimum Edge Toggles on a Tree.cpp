static int D[100'000];
class Solution {
public:
    vector<int> minimumFlips(int N, vector<vector<int>>& edges, string start, string target) {
        vector<int> result;
        result.reserve(N);
        vector<bool> s(N);
        for (int i = 0; i < N; ++i)
            s[i] = ((start[i] - '0') ^ (target[i] - '0'));
        if (accumulate(s.begin(), s.end(), 0) % 2 == 1)
            return { -1 };
        vector<unordered_set<int>> connectivity(N);
        memset(D, 0, sizeof(D));
        for (int E = 0; E < N - 1; ++E)
        {
            int const& V = edges[E][0];
            int const& U = edges[E][1];
            ++D[V], ++D[U];
            connectivity[V].insert(E);
            connectivity[U].insert(E);
        }
        set<pair<int, int>> S;
        for (int V = 0; V < N; ++V)
            S.insert({ D[V], V});
        while (!S.empty())
        {
            pair<int, int> const P = *S.begin();
            int const& V = P.second;
            int const E = *connectivity[V].begin();
            int const U = edges[E][0] + edges[E][1] - V;
            connectivity[V].clear();
            connectivity[U].erase(E);
            S.erase(S.begin());
            S.erase(S.find({ D[U], U }));
            --D[V], --D[U];
            if (D[U] > 0)
                S.insert({ D[U], U });
            if (s[V])
                s[V] = !s[V], s[U] = !s[U], result.push_back(E);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
