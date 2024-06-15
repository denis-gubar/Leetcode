int static F[101][100];
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memset(F, 100, sizeof(F));
        int const INF = F[0][0];
        int N = ring.size(), M = key.size();
        vector<vector<int>> A(26);
        for (int i = 0; i < N; ++i)
            A[ring[i] - 'a'].push_back(i);
        F[0][0] = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (F[i][j] < INF)
                    for (int k : A[key[i] - 'a'])
                        F[i + 1][k] = min(F[i + 1][k], F[i][j] + min(((k - j) + N) % N, ((j - k) + N) % N));                
        return *min_element(&F[M][0], &F[M][0] + N) + M;
    }
};
