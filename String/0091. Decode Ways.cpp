static unsigned int F[102];
class Solution {
public:
    int numDecodings(string s) {
        int const N = s.size();
        memset(F, 0, sizeof(F));
        F[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            if (s[i] != '0')
                F[i + 1] += F[i];
            if (s[i] == '1')
                F[i + 2] += F[i];
            if (s[i] == '2' && i + 1 < N && s[i + 1] <= '6')
                F[i + 2] += F[i];
        }
        return F[N];
    }
};
