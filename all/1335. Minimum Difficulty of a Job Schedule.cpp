static int F[11][301];
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        int const N = jobDifficulty.size();
        memset(F, -1, sizeof(F));
        F[0][0] = 0;
        auto update = [](int& x, int value)
            {
                if (x == -1 || x > value)
                    x = value;
            };
        for (int i = 0; i < D; ++i)
            for (int j = 0; j < N; ++j)
                if (F[i][j] >= 0)
                {
                    int difficulty = 0;
                    for (int nj = j; nj < N; ++nj)
                    {
                        difficulty = max(difficulty, jobDifficulty[nj]);
                        update(F[i + 1][nj + 1], F[i][j] + difficulty);
                    }
                }
        return F[D][N];
    }
};
