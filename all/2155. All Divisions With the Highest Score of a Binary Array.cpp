class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> result;
        int N = nums.size();
        vector<int> A(N + 1), B(N + 1);
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] + (nums[i] == 0);
            B[i + 1] = B[i] + (nums[i] == 1);
        }
        vector<pair<int, int>> F(N + 1);
        for (int i = 0; i <= N; ++i)
            F[i] = {A[i] + B[N] - B[i], i};
        sort(F.begin(), F.end());
        int best = F.back().first;
        while (!F.empty() && F.back().first == best)
        {
            result.push_back(F.back().second);
            F.pop_back();
        }
        return result;
    }
};
