int static F[1'000][26][26];
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int N = words.size();
        int total = 0;
        for (string const& x : words)
            total += x.size();
        int result = total;
        memset(F, -1, sizeof(F));
        F[0][words[0][0] - 'a'][words[0].back() - 'a'] = 0;
        for(int i = 1; i < N; ++i)
            for(int a = 0; a < 26; ++a)
                for(int b = 0; b < 26; ++b)
                    if (F[i - 1][a][b] >= 0)
                    {
                        int c = words[i][0] - 'a';
                        int d = words[i].back() - 'a';
                        if (b == c && F[i][a][d] < F[i - 1][a][b] + 1)
                            F[i][a][d] = F[i - 1][a][b] + 1;
                        else if (F[i][a][d] < F[i - 1][a][b])
                            F[i][a][d] = F[i - 1][a][b];
                        if (d == a && F[i][c][b] < F[i - 1][a][b] + 1)
                            F[i][c][b] = F[i - 1][a][b] + 1;
                        else if (F[i][c][b] < F[i - 1][a][b])
                            F[i][c][b] = F[i - 1][a][b];
                    }
        for (int a = 0; a < 26; ++a)
            for (int b = 0; b < 26; ++b)
                result = min(result, total - F[N - 1][a][b]);
        return result;
    }
};
