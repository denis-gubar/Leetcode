class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        unordered_map<int, int> A;
        A.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            int delta = nums[i] - i;
            ++A[delta];
            result += i + 1 - A[delta];
        }
        return result;
    }
};
