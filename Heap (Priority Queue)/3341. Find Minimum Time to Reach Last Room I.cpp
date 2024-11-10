static int F[50][50];
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int const N = moveTime.size(), M = moveTime[0].size();
        memset(F, 125, sizeof(F));
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        set<pair<int, int>> S;
        F[0][0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                S.insert({ F[i][j], i * M + j });
        while (!S.empty())
        {
            pair<int, int> P = *S.begin();
            S.erase(S.begin());
            int const x = P.second / M;
            int const y = P.second % M;
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && F[nx][ny] > max(moveTime[nx][ny], F[x][y]) + 1)
                {
                    auto it = S.find({ F[nx][ny], nx * M + ny });
                    S.erase(it);
                    F[nx][ny] = max(moveTime[nx][ny], F[x][y]) + 1;
                    S.insert({ F[nx][ny], nx * M + ny });
                }
            }
        }
        return F[N - 1][M - 1];
    }
};

