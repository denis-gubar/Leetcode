static vector<vector<string>> F;
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        F = vector<vector<string>>(19);
        F[0].push_back({});
        F[1].push_back({ "0" });
        F[1].push_back({ "1" });
        for (int i = 2; i < 19; ++i)
        {
            F[i].reserve(1 << i);
            for (string const& s : F[i - 1])
            {
                if (s.back() == '1')
                {
                    F[i].push_back(s);
                    F[i].back().push_back('0');
                }
                F[i].push_back(s);
                F[i].back().push_back('1');
            }
        }
    }
}
class Solution {
public:
    vector<string> validStrings(int N) {
        init();
        return F[N];
    }
};
