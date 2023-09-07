class Solution {
public:
    int N;
    vector<bool> visited, safe;
    bool calc(vector<vector<int>> const& graph, int V)
    {
        bool result = true;
        visited[V] = true;
        for (int U : graph[V])
            result &= visited[U] ? safe[U] : calc(graph, U);
        return safe[V] = result;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        N = graph.size();
        visited = vector<bool>(N);
        safe = vector<bool>(N);
        vector<int> result;
        result.reserve(N);
        for (int V = 0; V < N; ++V)
            if (!visited[V] && calc(graph, V) || safe[V])
                result.push_back(V);            
        return result;
    }
};
