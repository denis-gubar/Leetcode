class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        vector<int> A;
        A.reserve(N + 2);
        A.emplace_back(0);
        partial_sum(nums.begin(), nums.end(), back_inserter(A));
        A.emplace_back(A.back());
        for (int i = 0; i < N; ++i)
            if (A[i] == A[N] - A[i + 1])
                return i;
        return -1;
    }
};
