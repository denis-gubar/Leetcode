static unsigned char F[250][250][26];
class Solution {
public:
    int longestPalindromeSubseq(string s) { 
        unsigned char result = 0;
        memset(F, 0, sizeof(F));
        int const N = s.size();
        auto update = [&result](auto& x, auto value)
            {
                if (x < value)
                {
                    x = value;
                    if (result < x)
                        result = x;
                }
            };
        for (int length = 2; length <= N; ++length)
            for (int start = 0; start <= N - length; ++start)
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (s[start] == s[start + length - 1])
                    {
                        if (c != s[start])
                            update(F[start][start + length - 1][s[start] - 'a'],
                                F[start + 1][start + length - 2][c - 'a'] + 2);
                    }
                    update(F[start][start + length - 1][c - 'a'],
                        F[start + 1][start + length - 1][c - 'a']);
                    update(F[start][start + length - 1][c - 'a'],
                        F[start][start + length - 2][c - 'a']);
                }
        return result;
    }
};
