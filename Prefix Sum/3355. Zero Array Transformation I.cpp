class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size();
        vector<int> A(N + 1);
        for (vector<int> const& q : queries)
        {
            int const& L = q[0];
            int const& R = q[1];
            --A[L], ++A[R + 1];
        }
        int balance = 0;
        for (int i = 0; i < N; ++i)
        {
            balance += A[i];
            if (nums[i] + balance > 0)
                return false;
        }
        return true;
    }
};
