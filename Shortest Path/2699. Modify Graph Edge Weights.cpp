static int const INF = 1'000'000'001;
class Solution {
public:
    using NodeIndex = int;
    using Distance = long long;
    Distance dijkstra(vector<vector<pair<NodeIndex, Distance>>> const& connectivity, int const source, int const destination)
    {
        int const N = connectivity.size();
        vector<Distance> minDistance(N + 1, INF);
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
                    activeVertices.insert({ minDistance[edge.first], edge.first });
                }
        }
        cout << "dijkstra: " << minDistance[destination] << '
';
        return minDistance[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int N, vector<vector<int>>& edges, int source, int destination, int target) {
        int const E = edges.size();
        vector<vector<pair<NodeIndex, Distance>>> connectivity(N);
        for (int i = 0; i < E; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            int const& W = edges[i][2];
            if (W > 0)
            {
                connectivity[V].emplace_back(U, W);
                connectivity[U].emplace_back(V, W);
            }
        }
        int current = dijkstra(connectivity, source, destination);
        if (current < target)
            return {};
        bool flag = current == target; 
        for (int i = 0; i < E; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            int& W = edges[i][2];
            if (W > 0)
                continue;
            if (flag)
                W = INF;
            else
                W = 1;
            connectivity[V].emplace_back(U, W);
            connectivity[U].emplace_back(V, W);
            if (!flag)
                if (current = dijkstra(connectivity, source, destination); current <= target)
                {
                    flag = true;
                    W += target - current;
                }                    
        }
        if (!flag)
            return {};
        return edges;
    }
};
