class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        bitset<100'000> F;
        F[0] = 1;
        bitset<100'000> A;
        for (int x : rewardValues)
            A[x] = 1;
        for (int i = 0; i < 50'000; ++i)
        {
            A[i] = 0;
            if (F[i])
                F |= A << i;
        }
        for (int x = 99'999; x >= 0; --x)
            if (F[x])
                return x;
        return -1;
    }
};
