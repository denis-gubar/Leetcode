class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long result = 0;
        int N = roads.size() + 1;
        vector<unordered_set<int>> connectivity(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = roads[i][0];
            int const& U = roads[i][1];
            connectivity[V].insert(U);
            connectivity[U].insert(V);
        }
        queue<int> Q;
        vector<int> S(N);
        Q.push(0);
        vector<bool> visited(N);
        visited[0] = true;
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            vector<int> A;            
            for (int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    A.push_back(U);
                }
            for (int U : A)
            {
                Q.push(U);
                ++S[V];
                connectivity[V].erase(U);
            }
        }
        vector<int> passengers(N);
        for (int i = 1; i < N; ++i)
            if (S[i] == 0)
                Q.push(i);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            if (V == 0) continue;
            ++passengers[V];
            result += (passengers[V] + seats - 1) / seats;
            for (int U : connectivity[V])
            {
                --S[U];
                if (S[U] == 0)
                    Q.push(U);
                passengers[U] += passengers[V];
            }
        }
        return result;
    }
};
