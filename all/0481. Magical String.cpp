static int F[500'010];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        string s;
        s.reserve(500'010);
        s += "122";
        int pos = 2;
        int const delta = static_cast<int>('1') + '2';
        char z = '1';
        memset(F, 0, sizeof(F));
        while (s.size() < 500'000)
        {
            for (char c = '1'; c <= s[pos]; ++c)
                s += z;
            ++pos;
            z = delta - z;
        }
        for (int i = 0; i < 500'000; ++i)
            F[i + 1] = F[i] + s[i] % 2;
        for (int i = 0; i < 20; ++i)
            cout << s[i];
        cout << '
';
    }
}
class Solution {
public:
    int magicalString(int n) {
        init();
        return F[n];
    }
};
