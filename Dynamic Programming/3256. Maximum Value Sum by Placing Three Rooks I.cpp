static pair<int, int> F[500][500];
static int A[3];
static int B[3];
static int Z[3];
static int V[3];
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int const N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                F[i][j] = { board[i][j], j };
        for (int i = 0; i < N; ++i)
            sort(&F[i][0], &F[i][0] + M, greater{});
        long long result = 0LL + board[0][0] + board[1][1] + board[2][2];
        vector<pair<long long, pair<int, int>>> X;
        X.reserve(N * M);
        auto g = [](int x, int y)
            {
                return x * 1000 + y;
            };
        for (A[0] = 0; A[0] < N; ++A[0])
            for (B[0] = 0; B[0] < 3; ++B[0])
            {
                Z[0] = F[A[0]][B[0]].second;
                V[0] = F[A[0]][B[0]].first;
                for (A[1] = A[0] + 1; A[1] < N; ++A[1])
                    for (B[1] = 0; B[1] < 3; ++B[1])
                    {
                        Z[1] = F[A[1]][B[1]].second;
                        if (Z[1] == Z[0])
                            continue;
                        V[1] = F[A[1]][B[1]].first;
                        X.push_back({ 0LL + V[0] + V[1], {g(A[0], Z[0]), g(A[1], Z[1])} });
                    }
            }
        sort(X.begin(), X.end(), greater{});
        for (A[2] = 0; A[2] < N; ++A[2])
            for (B[2] = 0; B[2] < 3; ++B[2])
            {
                Z[2] = F[A[2]][B[2]].second;
                V[2] = F[A[2]][B[2]].first;
                for (int i = 0; i < X.size(); ++i)
                {
                    auto P = X[i];
                    A[0] = P.second.first / 1000;
                    if (A[2] == A[0])
                        continue;
                    A[1] = P.second.second / 1000;
                    if (A[2] == A[1])
                        continue;
                    Z[0] = P.second.first % 1000;
                    if (Z[2] == Z[0])
                        continue;
                    Z[1] = P.second.second % 1000;
                    if (Z[2] == Z[1])
                        continue;
                    result = max(result, P.first + V[2]);
                }
            }
        return result;
    }
};
