static int F[201][200];
class Solution {
public:
    int maxScore(int N, int K, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int result = 0;
        memset(F, 0, sizeof(F));
        for (int i = 0; i < K; ++i)
            for (int j = 0; j < N; ++j)
                for (int nj = 0; nj < N; ++nj)
                {
                    F[i + 1][nj] = max(F[i + 1][nj], F[i][j] + 
                        (nj == j) * stayScore[i][j] + 
                        (nj != j) * travelScore[j][nj]);
                    result = max(result, F[i + 1][nj]);
                }
        return result;
    }
};
