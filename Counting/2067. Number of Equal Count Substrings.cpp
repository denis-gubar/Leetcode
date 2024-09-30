static int F[30'001][26];
class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int const N = s.size();
        int result = 0;
        memset(F, 0, sizeof(F));
        for (int i = 0; i < N; ++i)
        {
            char x = s[i] - 'a';
            for (char c = 0; c < 26; ++c)
                F[i + 1][c] = F[i][c] + (c == x);
        }
        for (int L = 0; L + count <= N; ++L)
        {
            bool flag = true;
            for (int R = L + count, k = 0; flag && R <= N && k < 26; ++k, R += count)
            {
                bool isOk = true;
                for (char c = 0; c < 26; ++c)
                    if (F[R][c] - F[L][c] != 0 && F[R][c] - F[L][c] != count)
                    {
                        isOk = false;
                        flag &= F[R][c] - F[L][c] < count;
                        break;
                    }
                result += isOk;
            }
        }
        return result;
    }
};
