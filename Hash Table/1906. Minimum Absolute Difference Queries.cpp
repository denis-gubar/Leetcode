class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size(), Q = queries.size();
        vector<vector<int>> A(101);
        for (int i = 0; i < N; ++i)
            A[nums[i]].push_back(i);
        for (int j = 1; j < 101; ++j)
            A[j].push_back(N);
        vector<int> result(Q, -1);
        for (int q = 0; q < Q; ++q)
        {
            int const& L = queries[q][0];
            int const& R = queries[q][1];
            int best = 100, last = -100;
            for(int j = 1; j < 101; ++j)
                if (*lower_bound(A[j].begin(), A[j].end(), L) <= R)
                {
                    best = min(best, j - last);
                    last = j;
                }
            if (best < 100)
                result[q] = best;
        }
        return result;
    }
};
