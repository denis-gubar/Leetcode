class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int N = nums.size(), Q = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> A{0};
        partial_sum(nums.begin(), nums.end(), back_inserter(A));
        vector<int> result(Q);
        for (int q = 0; q < Q; ++q)
        {
            auto it = upper_bound(A.begin(), A.end(), queries[q]);
            --it;
            result[q] = it - A.begin();
        }
        return result;
    }
};
