static long long F[26][26];
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long result = 0;
        memset(F, 1, sizeof(F));
        for (int a = 0; a < 26; ++a)
        {
            F[a][a] = 0;
            long long total = 0;
            for (int b = (a + 1) % 26, k = 0; k < 25; ++k, b = (b + 1) % 26)
            {
                total += nextCost[(b + 25) % 26];
                F[a][b] = min(F[a][b], total);
            }
            total = 0;
            for (int b = (a + 25) % 26, k = 0; k < 25; ++k, b = (b + 25) % 26)
            {
                total += previousCost[(b + 1) % 26];
                F[a][b] = min(F[a][b], total);
            }
        }
        int const N = s.size();
        for (int i = 0; i < N; ++i)
            result += F[s[i] - 'a'][t[i] - 'a'];
        return result;
    }
};
