class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int const N = coordinates.size();
        vector<pair<int, int>> F[2];
        F[0].reserve(N); F[1].reserve(N);
        for (int i = 0; i < N; ++i)
        {
            int const& x = coordinates[i][0];
            int const& y = coordinates[i][1];
            if (x < coordinates[k][0] && y < coordinates[k][1])
                F[0].emplace_back(x, -y);
            else if (x > coordinates[k][0] && y > coordinates[k][1])
                F[1].emplace_back(x, -y);
        }
        int result = 1;
        for (int z = 0; z < 2; ++z)
        {
            vector<pair<int, int>>& A = F[z];
            sort(A.begin(), A.end());
            vector<int> M;
            int const N = A.size();
            M.reserve(N);
            for (int i = 0; i < N; ++i)
            {
                int const& x = -A[i].second;
                auto it = lower_bound(M.begin(), M.end(), x);
                if (it == M.end())
                    M.push_back(x);
                else
                    *it = x;
            }
            result += M.size();
        }
        return result;
    }
};
