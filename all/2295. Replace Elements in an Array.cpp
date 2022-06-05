class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int N = nums.size();
        vector<int> result(N);
        vector<int> M(1'000'001, -1);
        for (int i = 0; i < N; ++i)
            M[nums[i]] = i;
        for (int i = 0; i < operations.size(); ++i)
        {
            int pos = M[operations[i][0]];
            M[operations[i][1]] = M[operations[i][0]];
            M[operations[i][0]] = -1;
        }
        for (int i = 0; i < 1'000'001; ++i)
            if (M[i] >= 0)
                result[M[i]] = i;
        return result;
    }
};
