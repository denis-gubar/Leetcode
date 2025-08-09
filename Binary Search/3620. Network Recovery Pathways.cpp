class Solution {
public:
    using Distance = long long;
    using NodeIndex = int;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long K) {
        int a = -1, b = 1'000'000'001;
        int const N = online.size(), E = edges.size();
        vector<vector<int>> connectivity(N);
        for (int i = 0; i < E; ++i)
        {
            vector<int> const& e = edges[i];
            int const& V = e[0];
            if (!online[V])
                continue;
            int const& U = e[1];
            if (!online[U])
                continue;
            connectivity[V].push_back(i);
        }
        for (int V = 0; V < N; ++V)
        {
            if (connectivity[V].size() < 2)
                continue;
            sort(connectivity[V].begin(), connectivity[V].end(), [&edges](int a, int b) -> bool
                {
                    return edges[a][2] < edges[b][2];
                });
        }
        auto calc = [&](int m) -> bool
            {
                vector<Distance> minDistance(N, K + 1);
                minDistance[0] = 0;
                set<pair<Distance, NodeIndex>> activeVertices;
                activeVertices.insert({ 0LL, 0 });
                while (!activeVertices.empty())
                {
                    int node = activeVertices.begin()->second;
                    activeVertices.erase(activeVertices.begin());
                    for (int i = connectivity[node].size() - 1; i >= 0 && edges[connectivity[node][i]][2] >= m; --i)
                    {
                        int const edge = connectivity[node][i];
                        Distance length = minDistance[node] + edges[edge][2];
                        if (length > K)
                            continue;
                        if (minDistance[edges[edge][1]] > length)
                        {
                            if (auto it = activeVertices.find({ minDistance[edges[edge][1]], edges[edge][1] }); it != activeVertices.end())
                                activeVertices.erase(it);
                            minDistance[edges[edge][1]] = length;
                            activeVertices.insert({ minDistance[edges[edge][1]], edges[edge][1] });
                        }
                    }
                }
                return minDistance[N - 1] <= K;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
