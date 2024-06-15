class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> A;
        int N = nums.size(), Q = queries.size();
        A.reserve(N);
        vector<int> result(Q, -1);
        for (int i = 0; i < N; ++i)
            if (nums[i] == x)
                A.push_back(i);
        for (int q = 0; q < Q; ++q)
        {
            int const& i = queries[q];
            if (A.size() >= i)
                result[q] = A[i - 1];
        }
        return result;
    }
};
