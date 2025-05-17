class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int const N = spells.size(), P = potions.size();
        vector<int> result(N);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < N; ++i)
            result[i] = potions.end() - lower_bound(potions.begin(), potions.end(), (success + spells[i] - 1) / spells[i]);
        return result;
    }
};
