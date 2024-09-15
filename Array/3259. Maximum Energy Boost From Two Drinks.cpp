static long long F[100'001][2];
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int const N = energyDrinkA.size();
        memset(F, 0, sizeof(F));
        for (int i = 0; i < N; ++i)
        {
            F[i + 1][0] = max(F[i][0] + energyDrinkA[i], i == 0 ? 0LL : (F[i - 1][1] + energyDrinkA[i]));
            F[i + 1][1] = max(F[i][1] + energyDrinkB[i], i == 0 ? 0LL : (F[i - 1][0] + energyDrinkB[i]));
        }
        return max(F[N][0], F[N][1]);
    }
};
