static unsigned char F[200][200][202];
class Solution {
public:
    int longestPalindromicSubsequence(string s, int K) {
        int const N = s.size();
        unsigned char K1 = K + 1;
        memset(F, 255, sizeof(F));
        for (int a = 0; a < N; ++a)
            F[a][a][0] = 1;
        auto update = [](unsigned char& x, unsigned char value)
            {
                if (value == 255)
                    return;
                if (x == 255 || x < value)
                    x = value;
            };
        for (int a = 0; a < N - 1; ++a)
        {
            unsigned char x = abs(s[a] - s[a + 1]);
            x = min<unsigned char>(x, 26 - x);
            update(F[a][a + 1][0], F[a][a][0]);
            update(F[a][a + 1][min(K1, x)], 2);
        }
        for(int length = 0; length < N - 1; ++length)
            for (int k = 0; k <= K1; ++k)
            {
                update(F[0][length + 1][k], F[0][length][k]);
                update(F[N - 2 - length][N - 1][k], F[N - 1 - length][N - 1][k]);
                for (int a = 1, b = a + length; b < N - 1; ++a, ++b)
                    if (F[a][b][k] < 255)
                    {
                        unsigned char x = abs(s[a - 1] - s[b + 1]);
                        x = min<unsigned char>(x, 26 - x);
                        update(F[a - 1][b][k], F[a][b][k]);
                        update(F[a][b + 1][k], F[a][b][k]);
                        update(F[a - 1][b + 1][k], F[a][b][k]);
                        update(F[a - 1][b + 1][min<unsigned char>(K1, x + k)], F[a][b][k] + 2);
                    }
            }
        int result = 0;
        for (int k = 0; k <= K; ++k)
            if (F[0][N - 1][k] < 255)
                result = max<int>(result, F[0][N - 1][k]);
        return result;
    }
};
