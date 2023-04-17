class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();
        int result = 0;
        vector<vector<int>> connectivity(N);
        vector<int> inv(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            ++inv[U];
        }
        vector<vector<int>> F(26, vector<int>(N));
        queue<int> Q;
        for(int V = 0; V < N; ++V)
            if (inv[V] == 0)
            {
                F[colors[V] - 'a'][V] = 1;
                Q.push(V);
            }
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for (int U : connectivity[V])
            {
                for (int i = 0; i < 26; ++i)
                    F[i][U] = max(F[i][U], F[i][V] + (colors[U] - 'a' == i));
                if (--inv[U] == 0)
                    Q.push(U);
            }
        }
        for (int V = 0; V < N; ++V)
            if (inv[V] != 0)
                return -1;
        for (int i = 0; i < 26; ++i)
            result = max(result, *max_element(F[i].begin(), F[i].end()));
        return result;
    }
};
