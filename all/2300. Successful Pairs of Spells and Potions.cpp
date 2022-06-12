class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int N = spells.size(), M = potions.size();
        vector<int> result(N);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < N; ++i)
        {
            auto it = lower_bound(potions.begin(), potions.end(), (success + spells[i] - 1) / spells[i]);
            result[i] = potions.end() - it;
        }
        return result;
    }
};
