class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int N = nums.size();
        int const INF = 1'000'000'001;
        vector<int> A(32, INF);
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < 31; ++k)
                if (nums[i] & (1 << k))
                    A[k] = min(A[k], nums[i]);
        for (int i = 0; i < 31; ++i)
            if (A[i] > (1 << i))
                return 1 << i;
        return 1 << 30;
    }
};
