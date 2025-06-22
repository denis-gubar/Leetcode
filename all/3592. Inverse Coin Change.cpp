static int F[101];
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int const N = numWays.size();
        numWays.insert(numWays.begin(), 0);
        vector<int> result;
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= N; ++i)
        {
            if (F[i] == numWays[i] - 1)
            {
                result.push_back(i);
                ++F[i];
                for (int j = i + 1; j <= N; ++j)
                    if (F[j - i] > 0)
                        F[j] += F[j - i];
            }
            if (F[i] != numWays[i])
                return {};
        }
        return result;
    }
};
