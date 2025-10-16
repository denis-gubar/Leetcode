class Solution {
public:
    vector<vector<int>> connectivity;
    vector<int> height, dist;
    void calcHeight(int V, int P)
    {
        for (int U : connectivity[V])
            if (U != P)
            {
                calcHeight(U, V);
                height[V] = max(height[V], height[U]);
            }
        ++height[V];
    }
    void calcDist(int V, int P)
    {
        int max1 = 0, max2 = 0;
        for (int U : connectivity[V])
            if (U != P)
            {
                if (height[U] >= max1)
                {
                    max2 = max1;
                    max1 = height[U];
                }
                else if (height[U] > max2)
                    max2 = height[U];
            }
        int x = 0;
        for (int U : connectivity[V])
            if (U != P)
            {
                x = (max1 == height[U]) ? max2 : max1;
                dist[U] = 1 + max(1 + x, dist[V]);
                calcDist(U, V);
            }
    }
    pair<int, int> calc(vector<vector<int>> const& edges)
    {
        int N = edges.size() + 1;
        if (N == 1)
            return pair<int, int>{ 0, 0 };
        connectivity = vector<vector<int>>(N);
        height = vector<int>(N);
        dist = vector<int>(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        pair<int, int> result{ N, 0 };
        calcHeight(0, -1);
        calcDist(0, -1);
        for (int V = 0; V < N; ++V)
        {
            result.first = min(result.first, max(dist[V], height[V]) - 1);
            result.second = max(result.second, max(dist[V], height[V]) - 1);
        }
        return result;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        pair<int, int> x = calc(edges1);
        pair<int, int> y = calc(edges2);
        return max({x.second, x.first + 1 + y.first, y.second});
    }
};
