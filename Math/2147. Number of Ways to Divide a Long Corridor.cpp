class Solution {
public:
    int numberOfWays(string corridor) {
        int const MOD = 1'000'000'007;
        int total = count(corridor.begin(), corridor.end(), 'S');
        if (total % 2 == 1 || total == 0)
            return 0;
        int result = 1;
        int N = corridor.size();
        int s = 0, p = 0;
        for (int i = 0; i < N; ++i)
        {
            if (corridor[i] == 'P')
                ++p;
            else
            {
                if (s == 2)
                {
                    result = 1LL * result * (p + 1) % MOD;
                    s = 1;
                    p = 0;
                }
                else
                {
                    ++s;
                    p = 0;
                }
            }
        }
        return result;
    }
};
