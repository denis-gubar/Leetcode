class Solution {
public:
    int calc(vector<int> const& nums, int K)
    {
        int const N = nums.size();
        int const total = accumulate(nums.begin(), nums.end(), 0);
        if (K == 0 && total > N / 2 || K == 1 && N - total > N / 2)
            return 1 << 30;
        int result = 0;
        int current = 0;
        for (int i = 0; i < N; ++i)
            if (nums[i] == K)
                result += abs(i - current), current += 2;
        return result;
    }
    int minSwaps(vector<int>& nums) {
        int const N = nums.size();
        for (int& x : nums)
            x %= 2;
        vector<int> A(2);
        for (int i = 0; i < N; ++i)
            ++A[nums[i]];
        if (abs(A[0] - A[1]) > 1)
            return -1;
        int result = 1 << 30;
        if (A[0] > A[1])
            result = calc(nums, 0);
        else if (A[1] > A[0])
            result = calc(nums, 1);
        else
            result = min(calc(nums, 0), calc(nums, 1));
        return result;
    }
};
