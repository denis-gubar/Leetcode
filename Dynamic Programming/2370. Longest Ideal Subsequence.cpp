class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = s.size();
        vector<vector<int>> F(26, vector<int>(N + 1));
        int result = 0;
        for (int i = 0; i < 26; ++i)
            F[i][0] = 1;
        for (int j = 0; j < N; ++j)
        {
            int c = s[j] - 'a';
            for (int i = 0; i < 26; ++i)
            {
                F[i][j + 1] = max(F[i][j + 1], F[i][j]);
                if (abs(c - i) <= k)
                    F[c][j + 1] = max(F[c][j + 1], F[i][j] + 1);
            }
        }
        for (int i = 0; i < 26; ++i)
            result = max(result, F[i][N]);
        return result - 1;
    }
};
