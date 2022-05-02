class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int result = 0;
        int N = piles.size();
        vector<int> F(k + 1);
        for (int i = 0; i < N; ++i)
        {            
            int M = min<int>(k, piles[i].size());
            vector<int> A(M + 1);
            for (int j = 0; j < M; ++j)
                A[j + 1] = A[j] + piles[i][j];
			for (int level = k; level >= 0; --level)
                for (int j = 0; j <= M && j <= level; ++j)
                    F[level] = max(F[level], F[level - j] + A[j]);
        }
        return F[k];
    }
};
