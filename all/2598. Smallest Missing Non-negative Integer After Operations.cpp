class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int N = nums.size();
        vector<int> M(value);
        for (int x : nums)
            ++M[(1'000'000'000LL * value + x) % value];
        for (int result = 0; result < N; ++result)
            if (M[result % value] == 0)
                return result;
            else
                --M[result % value];
        return N;
    }
};
