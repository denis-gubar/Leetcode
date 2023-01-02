class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int result = -10'000;
        int N = vals.size();
        vector<vector<int>> connectivity(N);
        for(vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        for(int V = 0; V < N; ++V)
        {
            sort(connectivity[V].begin(), connectivity[V].end(), [&vals](int a, int b)
            {
                return vals[a] > vals[b];
            });
            int total = vals[V];
            for(int i = 0, M = connectivity[V].size(); i < k && i < M && vals[connectivity[V][i]] > 0; ++i)
                total += vals[connectivity[V][i]];
            result = max(result, total);
        }
        return result;
    }
};