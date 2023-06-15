class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int N = mat.size(), M = mat[0].size();
        vector<int> R(N);
        vector<int> C(M);
        vector<pair<int, int>> P(N * M);
        for (int i = 0, x = 0; i < N; ++i)
            for (int j = 0; j < M; ++j, ++x)
                P[x] = { mat[i][j], x };
        sort(P.begin(), P.end());
        for (int x = 0; x < N * M; ++x)
        {
            int y = x;
            while (y + 1 < N * M && P[x].first == P[y + 1].first)
                ++y;
            vector<int> A;
            for (int i = x; i <= y; ++i)
            {
                int a = P[i].second / M;
                int b = P[i].second % M;
                int weight = 1 + max(R[a], C[b]);                
                A.push_back(weight);
            }
            for (int i = x; i <= y; ++i)
            {
                int a = P[i].second / M;
                int b = P[i].second % M;
                int const& weight = A[i - x];
                R[a] = max(R[a], weight);
                C[b] = max(C[b], weight);
            }
            x = y;
        }
        return max(*max_element(R.begin(), R.end()), *max_element(C.begin(), C.end()));
    }
};
