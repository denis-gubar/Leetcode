class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        vector<unordered_map<int, int>> C(k + 2);
        vector<int> F(k + 2);
        for (int i = 0; i < N; ++i)
        {
            int const& x = nums[i];
            for (int j = k; j >= 0; --j)
            {
                if (F[j] + 1 > C[j + 1][x])
                    C[j + 1][x] = F[j] + 1;
                if (F[j] + 1 > F[j + 1])
                    F[j + 1] = F[j] + 1;
                ++C[j][x];
                if (C[j][x] > F[j])
                    F[j] = C[j][x];
            }
        }
        return F[k];
    }
};

