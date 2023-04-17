class Solution {
public:
    int findShortestCycle(int N, vector<vector<int>>& edges) {
        int const INF = N + 1;
        int result = INF;        
        vector<vector<int>> connectivity(N);
        for (const vector<int>& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        for (int i = 0; i < N; ++i)
        {
            vector<int> D(N, INF);
            vector<int> A(N, -1);
            D[i] = 0;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty())
            {
                int V = Q.front(); Q.pop();
                for (int U : connectivity[V])
                {
                    if (D[U] == INF)
                    {
                        D[U] = D[V] + 1;
                        A[U] = V;
                        Q.push(U);
                    }
                    else if (A[V] != U && A[U] != V)
                        result = min(result, D[V] + D[U] + 1);
                }
            }
        }
        if (result > N)
            result = -1;
        return result;
    }
};
