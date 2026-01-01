class Solution {
public:
    using MapType = unordered_map<unsigned char, pair<long long, int>>;
    long long interactionCosts(int N, vector<vector<int>>& edges, vector<int>& group) {
        long long result = 0;
        vector<vector<int>> connectivity(N);
        for (int E = 0; E < N - 1; ++E)
        {
            int const& V = edges[E][0];
            int const& U = edges[E][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        auto dfs = [&](this const auto& self, int V, int P) -> MapType
            {
                MapType current;
                ++current[group[V]].second;
                for(int U : connectivity[V])
                    if (U != P)
                    {
                        MapType M = self(U, V);
                        for (auto [key, value] : M)
                        {                            
                            if (value.second > 0)
                            {
                                result += 1LL * current[key].second * (value.first + value.second);
                                result += 1LL * value.second * current[key].first;
                            }
                            current[key].first += value.first + value.second;
                            current[key].second += value.second;
                        }
                    }
                return current;
            };
        dfs(0, -1);
        return result;
    }
};
