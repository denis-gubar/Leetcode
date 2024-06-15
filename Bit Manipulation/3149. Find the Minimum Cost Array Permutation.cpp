class Solution {
public:
    vector<int> result;
    vector<int> B;
    vector<int> nums;
    int N;
    int best;
    void calc(int i, int score, int mask)
    {
        if (mask == 0)
        {
            score += abs(B[N - 1] - nums[B[0]]);
            if (best > score)
                best = score, result = B;
            return;
        }
        if (i == 0)
        {
            for (B[i] = 0; B[i] < N; ++B[i])
                calc(i + 1, score, mask ^ (1 << B[i]));
            return;
        }
        for (B[i] = 0; B[i] < N; ++B[i])
            if (mask & (1 << B[i]))
            {
                int newScore = score + abs(B[i - 1] - nums[B[i]]);
                if (newScore <= best)
                    calc(i + 1, newScore, mask ^ (1 << B[i]));
            }
    }
    vector<int> findPermutation(vector<int>& nums) {
        N = nums.size();
        this->nums = nums;
        result.reserve(N);
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        B = I;
        best = 1 << 30;
        calc(0, 0, (1 << N) - 1);
        return result;
    }
};
