static bool isInit = false;
static int F[2'000];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        unordered_map<int, int> M;
        for (int a = 1; a <= 1'000; ++a)
            for (int b = a; b <= 1'000; ++b)
                ++M[a * a * a + b * b * b];
        for (auto [key, value] : M)
            if (value > 1)
                ++F[0], F[F[0]] = key;
        sort(&F[0] + 1, &F[0] + F[0] + 1);
    }
}
class Solution {
public:
    vector<int> findGoodIntegers(int N) {
        init();
        vector<int> result;
        for (int x = 1; x <= F[0] && F[x] <= N; ++x)
            result.push_back(F[x]);
        return result;
    }
};
