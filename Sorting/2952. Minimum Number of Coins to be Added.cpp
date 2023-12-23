class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int result = 0;
        coins.push_back(target + 1);
        sort(coins.begin(), coins.end());
        int N = coins.size();
        int last = 0;
        for (int i = 0; last < target && i < N; )
        {
            if (coins[i] <= last + 1)
                last += coins[i], ++i;
            else
            {
                last = last + (last + 1);
                ++result;
            }
        }
        return result;
    }
};
