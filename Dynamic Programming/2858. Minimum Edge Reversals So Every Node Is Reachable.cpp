class Solution {
public:
    int N;
    int calc(vector<vector<int>> const& connectivity, vector<vector<int>> const& reverse,
        vector<int>& A, int V, int P)
    {
        int result = 0;
        for (int U : connectivity[V])
            if (U != P)
                result += calc(connectivity, reverse, A, U, V);
        for (int U : reverse[V])
            if (U != P)
                result += 1 + calc(connectivity, reverse, A, U, V);
        return A[V] = result;
    }
    void dfs(vector<int>& result, vector<vector<int>> const& connectivity, vector<vector<int>> const& reverse,
        vector<int>& A, int V, int P, int C)
    {
        result[V] = A[V] + C;
        for (int U : connectivity[V])
            if (U != P)
                dfs(result, connectivity, reverse, A, U, V, C + A[V] - A[U] + 1);
        for (int U : reverse[V])
            if (U != P)
                dfs(result, connectivity, reverse, A, U, V, C + A[V] - A[U] - 1);
    }
    vector<int> minEdgeReversals(int N, vector<vector<int>>& edges) {
        vector<int> result(N);
        this->N = N;
        vector<vector<int>> connectivity(N), reverse(N);
        vector<int> A(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            reverse[U].push_back(V);
        }
        for (int V = 0; V < N; ++V)
            if (connectivity[V].size() + reverse[V].size() == 1)
            {
                calc(connectivity, reverse, A, V, -1);
                dfs(result, connectivity, reverse, A, V, -1, 0);
                return result;
            }
        return result;
    }
};
