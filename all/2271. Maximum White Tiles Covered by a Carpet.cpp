class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int N = tiles.size();
        int result = 0;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i)
        {
            int const& L = tiles[i][0];
            int const& R = tiles[i][1];
            A[i] = { L, R - L };
        }
        sort(A.begin(), A.end());
        vector<int> F(N + 1);
        for (int i = 0; i < N; ++i)
            F[i + 1] = F[i] + A[i].second + 1;
        for (int i = 0; i < N; ++i)
        {
            auto it = lower_bound(A.begin(), A.end(), pair<int, int>{ A[i].first + carpetLen, 0 });
            --it;
            int D = it - A.begin();
            int sum = F[D] - F[i];
            sum += min(A[i].first + carpetLen - 1, A[D].first + A[D].second) - A[D].first + 1;
            result = max(result, sum);
        }
        return result;
    }
};
