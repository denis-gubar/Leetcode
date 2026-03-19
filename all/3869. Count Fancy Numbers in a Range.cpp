static vector<bool> isFancy(151);
static bool isInit = false;
static vector<long long> A;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        for (int x = 0; x <= 150; ++x)
        {
            string s{ to_string(x) };
            unordered_set<char> S(s.begin(), s.end());
            if (s.size() != S.size())
                continue;
            if (is_sorted(s.begin(), s.end()))
                isFancy[x] = true;
            reverse(s.begin(), s.end());
            if (is_sorted(s.begin(), s.end()))
                isFancy[x] = true;
        }
        string s;
        auto dfs = [&](this const auto& self, long long last) -> void
            {
                if (!s.empty() && s[0] == 0)
                    return;
                if (!s.empty())
                {
                    int sum = 0;
                    for (char d : s)
                        sum += d - '0';
                    if (!isFancy[sum])
                        A.push_back(stoll(s));

                }
                for (char d = '0'; d <= '9'; ++d)
                    if (d - '0' > last)
                    {
                        s += d;
                        self(d - '0');
                        s.pop_back();
                    }
            };
        dfs(0);
        auto dfs2 = [&](this const auto& self, int last) -> void
            {
                if (!s.empty() && s[0] == 0)
                    return;
                if (!s.empty())
                {
                    int sum = 0;
                    for (char d : s)
                        sum += d - '0';
                    if (!isFancy[sum])
                        A.push_back(stoll(s));
                }
                for (char d = '0'; d <= '9'; ++d)
                    if (d - '0' < last)
                    {
                        s += d;
                        self(d - '0');
                        s.pop_back();
                    }
            };
        s.clear();
        dfs2(10);
        sort(A.begin(), A.end());
        A.resize(unique(A.begin(), A.end()) - A.begin());
    }
}
//N, sum of digits, balance, lastDigit +/- 1, isB, isZero
static long long F[17][151][2][2];
class Solution {
public:
    long long calc(long long x)
    {
        if (x < 10)
            return x;
        string B = to_string(x);
        int const N = B.size();
        long long result = 0;
        memset(F, 0, sizeof(F));
        F[0][0][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int sum = 0, b = B[i] - '0'; sum <= i * 9; ++sum)
                for (int d = 0; d < 10; ++d)
                    for (int isB = 0; isB < 2; ++isB)
                        for (int isZero = 0; isZero < 2; ++isZero)
                            if (!isB || d <= b)
                                F[i + 1][sum + d][isB && d == b][isZero && d == 0] += F[i][sum][isB][isZero];
        for (int sum = 0; sum <= N * 9; ++sum)
            if (isFancy[sum])
                for (int isB = 0; isB < 2; ++isB)
                    result += F[N][sum][isB][false];
        return result;
    }
    long long countFancy(long long L, long long R) {
        init();
        long long result = calc(R) - calc(L - 1);
        for (long long x : A)
            if (L <= x && x <= R)
                ++result;
        return result;
    }
};
