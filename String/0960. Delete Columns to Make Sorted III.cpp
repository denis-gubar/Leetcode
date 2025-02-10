static char F[101];
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int const N = strs.size(), M = strs[0].size();
        memset(F, 0, sizeof(F));
        for (int a = 0; a < M; ++a)
            for (int b = a + 1; b < M; ++b)
            {
                bool flag = true;
                if (b > 0)
                    for (int i = 0; i < N; ++i)
                        if (strs[i][b] < strs[i][a])
                        {
                            flag = false;
                            break;
                        }
                if (flag)
                    F[b] = max<char>(F[b], F[a] + 1);
            }
        return M - *max_element(&F[0], &F[0] + M) - 1;
    }
};
