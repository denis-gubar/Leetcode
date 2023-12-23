static int F[100][26];
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int N = word.size();
        int result = N + 1;
        memset(F, 1, sizeof(F));
        for (int start = 0; start < 26; ++start)
        {
            F[0][start] = start + 'a' != word[0];
            for (int i = 1; i < N; ++i)
                for(int c = 0; c < 26; ++c)
                    for(int c2 = 0; c2 < 26; ++c2)
                        if (abs(c2 - c) > 1)
                            F[i][c2] = min(F[i][c2], F[i - 1][c] + (c2 + 'a' != word[i]));
        }
        for (int c = 0; c < 26; ++c)
            result = min(result, F[N - 1][c]);
        return result;
    }
};
