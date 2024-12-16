class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int result = 1 << 30;
        int const N = strength.size();
        sort(strength.begin(), strength.end());
        do
        {
            int X = 1, current = 0;
            for (int a : strength)
            {
                current += (a + X - 1) / X;
                X += K;
            }
            result = min(result, current);

        } while (next_permutation(strength.begin(), strength.end()));
        return result;
    }
};
