class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int result = 0;
        vector<vector<int>> A(3);
        for (int x : nums)
            A[x % 3].push_back(x);
        for (int i = 0; i < 3; ++i)
            sort(A[i].begin(), A[i].end(), greater{});
        auto update = [](int& x, int value)
            {
                if (x < value)
                    x = value;
            };
        for (int i = 0; i < 3; ++i)
            if (A[i].size() > 2)
                update(result, A[i][0] + A[i][1] + A[i][2]);
        if (A[0].size() > 0 && A[1].size() > 0 && A[2].size() > 0)
            update(result, A[0][0] + A[1][0] + A[2][0]);
        return result;
    }
};
