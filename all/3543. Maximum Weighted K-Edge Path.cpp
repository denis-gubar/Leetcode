class Solution {
public:
    int maxWeight(int N, vector<vector<int>>& edges, int K, int T) {
        int result = -1;
        --T;
        vector<unordered_map<int, bitset<611>>> F(N, unordered_map<int, bitset<611>>());
        for (int V = 0; V < N; ++V)
            F[V][0][0] = true;
        vector<int> D(N);
        vector<vector<pair<int, int>>> incoming(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            int const& W = e[2];
            incoming[U].push_back({ V, W });
            ++D[V];
        }
        set<pair<int, int>> S;
        for (int V = 0; V < N; ++V)
            S.insert({ D[V], V });
        while (!S.empty())
        {
            pair<int, int> P = *S.begin(); S.erase(S.begin());
            int const& U = P.second;
            for (auto const [V, W] : incoming[U])
            {
                S.erase({ D[V], V });
                --D[V];
                S.insert({ D[V], V });
                for (auto const& [L, value] : F[U])
                    F[V][L + 1] |= value << W;
            }
        }
        for(int V = 0; V < N; ++V)
            if (F[V].find(K) != F[V].end())
            {
                bitset<611> const& b = F[V][K];
                for (int i = T; i > result; --i)
                    if (b[i])
                        result = i;
            }
        return result;
    }
};
