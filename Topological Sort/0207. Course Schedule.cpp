class Solution {
public:
    int N;
    vector<vector<int>> connectivity;
    vector<bool> visited, safe;
    bool calc(int V)
    {
        bool result = visited[V] = true;
        for (int U : connectivity[V])
            result &= visited[U] ? safe[U] : calc(U);
        return safe[V] = result;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        N = numCourses;
        connectivity = vector<vector<int>>(N);
        visited = vector<bool>(N);
        safe = vector<bool>(N);
        for (vector<int> const& p : prerequisites)
            connectivity[p[1]].push_back(p[0]);
        for (int V = 0; V < N; ++V)
            if (!visited[V] && !calc(V) || !safe[V])
                return false;
        return true;
    }
};
