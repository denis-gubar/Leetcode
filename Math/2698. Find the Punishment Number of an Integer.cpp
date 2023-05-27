static int F[1'001];
static bool isInit = false;
static bool calc(int x)
{
    int xx = x * x;
    string s = to_string(xx);
    vector<pair<int, int>> P{{0, 0}};
    for (char c : s)
    {
        int d = c - '0';
        set<pair<int, int>> NP;
        for (auto [a, b] : P)
        {
            if (a + b + d <= x)
                NP.insert({ a + b, d });
            if (a + b * 10 + d <= x)
                NP.insert({ a, b * 10 + d });
        }
        P = vector<pair<int, int>>(NP.begin(), NP.end());
    }
    for (auto [a, b] : P)
        if (a + b == x)
            return true;
    return false;
}
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        for (int x = 1; x <= 1'000; ++x)
            F[x] = calc(x);
    }
}
class Solution {
public:
    int punishmentNumber(int N) {
        init();
        int result = 0;
        for (int x = 1; x <= N; ++x)
            if (F[x])
                result += x * x;
        return result;
    }
};
