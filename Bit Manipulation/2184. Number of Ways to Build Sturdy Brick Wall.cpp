static int const MOD = 1'000'000'007;
static int F[100][1 << 9];
class Solution {
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        long long result = 0;
        vector<bool> B(11);
        for (int x : bricks)
            B[x] = true;
        vector<int> masks;
        masks.reserve(1 << (width - 1));
        memset(F, 0, sizeof(F));
        for (int mask = 0, endMask = (1 << (width - 1)); mask < endMask; ++mask)
        {
            int prev = 0;
            bool flag = true;
            for (int k = 1; k < width; ++k)
                if (mask & (1 << (k - 1)))
                {
                    if (!B[k - prev])
                    {
                        flag = false;
                        break;
                    }
                    prev = k;
                }
            if (flag && B[width - prev])
                F[0][masks.size()] = 1, masks.push_back(mask);
        }
        auto add = [](int& x, int y) -> void
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        int const N = masks.size();
        for (int i = 1; i < height; ++i)
            for (int j = 0; j < N; ++j)
                if (F[i - 1][j])
                    for (int nj = 0; nj < N; ++nj)
                        if ((masks[j] & masks[nj]) == 0)
                            add(F[i][nj], F[i - 1][j]);
        for (int j = 0; j < N; ++j)
            result += F[height - 1][j];
        return result % MOD;
    }
};
