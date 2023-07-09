class Solution {
public:
    bool checkArray(vector<int>& nums, int K) {
        int N = nums.size();
        if (K == 1)
            return true;
        vector<int> balance(N + 1);
        int B = 0;
        for (int i = 0; i + K <= N; ++i)
        {
            B += balance[i];
            int delta = nums[i] - B;
            if (delta < 0)
                return false;
            balance[i + 1] += delta;
            balance[i + K] -= delta;
        }
        for (int i = N - K + 1; i < N; ++i)
        {
            B += balance[i];
            if (nums[i] != B)
                return false;
        }
        return B + balance[N] == 0;
    }
};
