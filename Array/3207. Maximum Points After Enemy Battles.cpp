class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long result = 0;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int N = enemyEnergies.size();
        int b = N - 1;
        if (enemyEnergies[0] > currentEnergy)
            return 0;
        while (b >= 0)
        {
            result += currentEnergy / enemyEnergies[0],
            currentEnergy %= enemyEnergies[0];
            currentEnergy += enemyEnergies[b], --b;
        }
        return result;
    }
};
