static short F[500][500];
class Solution {
public:
    int minInsertions(string s) {
        memset(F, -1, sizeof(F));
        int const N = s.size();
        function<int(int, int)> dfs = [&](int a, int b) -> int
            {
                if (a >= b)
                    return 0;
                if (F[a][b] < 0)
                {
                    if (s[a] == s[b])
                        return F[a][b] = dfs(a + 1, b - 1);
                    F[a][b] = min(dfs(a + 1, b), dfs(a, b - 1)) + 1;
                }
                return F[a][b];
            };
        return dfs(0, N - 1);
    }
};
