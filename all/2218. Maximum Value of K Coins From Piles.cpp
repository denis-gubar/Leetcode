static int A[2'001];
static int F[2'001];
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int result = 0;
        int N = piles.size();
        memset(F, 0, sizeof(F));        
        A[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            int P = piles[i].size();
            int M = min(k, P);
            for (int j = 0; j < P; ++j)
                A[j + 1] = A[j] + piles[i][j];
			for (int level = k; level >= 0; --level)
                for (int j = 0; j <= M && j <= level; ++j)
                    F[level] = max(F[level], F[level - j] + A[j]);
        }
        return F[k];
    }
};
