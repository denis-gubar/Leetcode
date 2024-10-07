static int G[61];
static bool isInit = false;
static int mex(vector<int> const& A)
{
    unordered_set<int> S(A.begin(), A.end());
    for (int result = 0; ; ++result)
        if (S.find(result) == S.end())
            return result;
}
static void init()
{
    if (!isInit)
    {
        isInit = true;
        G[0] = G[1] = 0;
        G[2] = 1;
        vector<int> A;
        A.reserve(60);
        for (int i = 3; i <= 60; ++i)
        {
            A.clear();
            for (int a = 0, b = i - 2; a < i / 2; ++a, --b)
                A.push_back(G[a] ^ G[b]);
            G[i] = mex(A);
        }
    }
}
class Solution {
public:
    bool canWin(string currentState) {
        init();                
        int result = 0;
        currentState += '-';
        int const N = currentState.size();        
        for (int i = 0; i < N; ++i)
            if (currentState[i] == '+')
            {
                int j = i + 1;
                while (currentState[j] == '+')
                    ++j;
                result ^= G[j - i];
                i = j;
            }
        return result != 0;
    }
};
