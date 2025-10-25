static bool F[1'001][1'001];
class Solution {
public:
    int numberOfPaths(int N, vector<vector<int>>& corridors) {
        int result = 0;
        memset(F, false, sizeof(F));
        for (vector<int> const& c : corridors)
        {
            int const& V = c[0];
            int const& U = c[1];
            F[V][U] = F[U][V] = true;
        }
        for (vector<int> const& c : corridors)
        {
            int const& V = c[0];
            int const& U = c[1];
            for (int W = 1; W <= N; ++W)
                if (F[W][V] && F[W][U])
                    ++result;
        }
        return result / 3;
    }
};
