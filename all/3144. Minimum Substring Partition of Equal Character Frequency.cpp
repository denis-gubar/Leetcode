int static F[1'001];
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int N = s.size();
        vector<vector<int>> A(N + 1, vector<int>(26));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 26; ++j)
                A[i + 1][j] = A[i][j] + (s[i] - 'a' == j);
        vector<vector<int>> Next(N);
        for(int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j)
            {
                int delta = -1;
                bool flag = true;
                for (int c = 0; c < 26; ++c)
                {
                    int d = A[j + 1][c] - A[i][c];
                    if (d == 0 || delta == d)
                        continue;
                    if (delta == -1)
                        delta = d;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    Next[i].push_back(j + 1);
            }
        memset(F, 1, sizeof(F));
        F[0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j : Next[i])
                F[j] = min(F[j], F[i] + 1);
        return F[N];
    }
};
