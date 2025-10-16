class Solution {
public:
    int findChampion(int N, vector<vector<int>>& edges) {
        vector<vector<bool>> M(N, vector<bool>(N));
        vector<vector<bool>> F(N, vector<bool>(N));
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            M[V][U] = F[U][V] = true;
        }
        int result = -1;
        for (int V = 0; V < N; ++V)
        {
            int count = 0;
            for (int U = 0; U < N; ++U)
                if (U != V)
                    count += !M[V][U] && F[V][U];
            if (count == 0)
            {
                if (result == -1)
                    result = V;
                else
                    return -1;
            }
        }
        return result;
    }
};
