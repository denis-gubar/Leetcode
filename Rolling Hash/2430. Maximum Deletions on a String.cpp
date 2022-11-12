class Solution {
public:
    template <int base>
    struct HashString
    {
        const int MOD = 1'000'000'007;
        HashString(const string& s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
        {
            power[0] = 1;
            for (int i = 1; i <= N; ++i)
            {
                power[i] = 1LL * power[i - 1] * base % MOD;
                prefixes[i] = (1LL * prefixes[i - 1] * base + hash(s[i - 1])) % MOD;
            }
        }
        static int hash(char c)
        {
            return c - 'a' + 1;
        }
        int hash(int start, int length) const
        {
            return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
        }
        int N;
        vector<int> prefixes;
        vector<int> power;
        string data;
    };
    int deleteString(string S) {
        int N = S.size();
        vector<int> F(N + 1);
        F[0] = 1;
        F[N] = 2;
        HashString<29> H1(S);
        HashString<31> H2(S);
        auto calc = [&H1, &H2](int x, int y, int length)
        {
            return H1.hash(x, length) == H1.hash(y, length) && H2.hash(x, length) == H2.hash(y, length);
        };
        for (int i = 0; i < N; ++i)
            if (F[i] > 0)
            {
                int rest = N - i;
                for (int length = 1; length * 2 <= rest; ++length)
                    if (F[i + length] <= F[i] && calc(i, i + length, length))
                    {
                        F[i + length] = F[i] + 1;
                        F[N] = max(F[N], F[i + length] + 1);
                    }
            }
        return F[N] - 1;
    }
};
