class Solution {
public:
    vector<int> remainingMethods(int N, int k, vector<vector<int>>& invocations) {
        vector<int> result;
        result.reserve(N);
        int const I = invocations.size();
        vector<vector<int>> connectivity(N);
        for (int i = 0; i < I; ++i)
        {
            int const& V = invocations[i][0];
            int const& U = invocations[i][1];
            connectivity[V].push_back(U);
            //connectivity[U].push_back(V);
        }
        vector<bool> visited(N);
        queue<int> Q;
        Q.push(k);
        visited[k] = true;
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for(int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                }
        }
        for (int V = 0; V < N; ++V)
            if (!visited[V])
            {
                for (int U : connectivity[V])
                    if (visited[U])
                    {
                        result.resize(N);
                        iota(result.begin(), result.end(), 0);
                        return result;
                    }
                result.push_back(V);
            }
        return result;
    }
};
