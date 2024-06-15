static char F[4'000];
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        memset(F, 0, sizeof(F));
        F[0] = 1;
        for (int i = 0; i < 2'000; ++i)
            if (F[i])
                for (int x : rewardValues)
                    if (x > i)
                        F[i + x] = 1;
        for (int x = 3'999; x >= 0; --x)
            if (F[x])
                return x;
        return -1;
    }
};
