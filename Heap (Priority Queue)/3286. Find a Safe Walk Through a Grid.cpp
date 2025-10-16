class Solution {
public:
    template<typename Distance, typename NodeIndex>
    bool dijkstra(vector<vector<pair<NodeIndex, Distance>>>& connectivity, int source, int health)
    {
        Distance const MAX = 1 << 20;
        int const N = connectivity.size();
        vector<Distance> minDistance(N, MAX);
        minDistance[source] = 0;
        set<pair<Distance, NodeIndex>> activeVertices;
        activeVertices.insert({ 0, source });
        while (!activeVertices.empty())
        {
            int node = activeVertices.begin()->second;
            activeVertices.erase(activeVertices.begin());
            for (auto edge : connectivity[node])
                if (minDistance[edge.first] > minDistance[node] + edge.second)
                {
                    activeVertices.erase({ minDistance[edge.first], edge.first });
                    minDistance[edge.first] = minDistance[node] + edge.second;
                    if (minDistance[edge.first] < health)
                        activeVertices.insert({ minDistance[edge.first], edge.first });
                }
        }
        return minDistance.back() < health;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int const N = grid.size(), M = grid[0].size();
        array dx{ -1, 0, 1, 0 };
        array dy{ 0, -1, 0, 1 };
        vector<vector<int>> F(N, vector<int>(M, 1 << 20));
        vector<vector<pair<int, int>>> connectivity(N * M);
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for (int z = 0; z < 4; ++z)
                {
                    int nx = i + dx[z];
                    int ny = j + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                        connectivity[i * M + j].emplace_back(nx * M + ny, grid[nx][ny]);
                }
        return dijkstra(connectivity, 0, health - grid[0][0]);
    }
};
