class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long result = 0;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<vector<int>> A(2), B(2);
        for (int x : nums)
            A[x % 2].push_back(x);
        for (int x : target)
            B[x % 2].push_back(x);
        for (int k = 0; k < 2; ++k)
        {
            N = A[k].size();
            for(int i = 0; i < N; ++i)
                result += abs(A[k][i] - B[k][i]);
        }
        return result / 4;
    }
};
