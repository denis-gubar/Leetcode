class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int Q = queries.size(), N = nums.size(), M = nums[0].size();
        vector<int> result(Q);
        for (int i = 0; i < Q; ++i)
        {
            int const& k = queries[i][0];
            int const& trim = queries[i][1];
            vector<string_view> A(N);
            for (int j = 0; j < N; ++j)
                A[j] = string_view(&nums[j][M - trim], trim);
            vector<int> I(N);
            iota(I.begin(), I.end(), 0);
            nth_element(I.begin(), I.begin() + (k - 1), I.end(), [&A](int a, int b)
                {
                    if (A[a] != A[b])
                        return A[a] < A[b];
                    return a < b;
                });
            result[i] = I[k - 1];
        }
        return result;
    }
};
