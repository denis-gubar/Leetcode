class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N);
        vector<int> A(N + 2);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i];
        A[N + 1] = A[N];
        for (int i = 0; i < N; ++i)
            result[i] = abs(A[i] - (A[N + 1] - A[i + 1]));
        return result;
    }
};
