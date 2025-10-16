class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int const N = x.size();
        unordered_map<int, int> M;
        for (int i = 0; i < N; ++i)
        {
            int const& val = x[i];
            M[val] = max(M[val], y[i]);
        }
        vector<int> A;
        A.reserve(N);
        for (auto [key, value] : M)
            A.push_back(value);
        if (A.size() > 2)
        {
            partial_sort(A.begin(), A.begin() + 3, A.end(), greater{});
            return A[0] + A[1] + A[2];
        }
        return -1;
    }
};
