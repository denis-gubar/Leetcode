static int F[51];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        F[1] = 1, F[2] = 2, F[3] = 3, F[4] = 4, F[5] = 5;
        for (int x = 3; x <= 50; ++x)
        {
            for (int y = 1; x + y <= 48; ++y)
                F[x + 2 + y] = max(F[x + 2 + y], F[x] * (y + 1));
        }
    }
}

class Solution {
public:
    int maxA(int n) {
        init();
        return F[n];        
    }
};
