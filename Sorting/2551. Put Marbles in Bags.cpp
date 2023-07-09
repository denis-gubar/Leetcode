class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int N = weights.size();
        vector<int> A;
        A.reserve(N);
        for (int i = 0; i < N - 1; ++i)
            A.push_back(weights[i] + weights[i + 1]);
        sort(A.begin(), A.end());
        return accumulate(A.begin() + N - k, A.end(), 0LL) - accumulate(A.begin(), A.begin() + k - 1, 0LL);
    }
};
