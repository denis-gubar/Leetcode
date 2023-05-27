char static F[50][50];
class Solution {
public:
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        int result = 0;
        memset(F, 0, sizeof(F));
        for (int i = 0; i < N; ++i)
            F[i][i] = 1;
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            F[V][U] = F[U][V] = 1;
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<int> visited(N);
        for (int V = 0; V < N; ++V)
            if (!visited[V])
            {
                visited[V] = true;
                vector<int> A{ V };
                queue<int> Q;
                Q.push(V);
                while (!Q.empty())
                {
                    int V = Q.front(); Q.pop();
                    for(int U : connectivity[V])
                        if (!visited[U])
                        {
                            A.push_back(U);
                            visited[U] = true;
                            Q.push(U);
                        }
                }
                bool isOk = true;
                for (int i = 0; i < A.size(); ++i)
                    for (int j = i + 1; j < A.size(); ++j)
                        isOk &= F[A[i]][A[j]];
                result += isOk;
            }
        return result;
    }
};
