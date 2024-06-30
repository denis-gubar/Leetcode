class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long result = 0;
        vector<int> A(24);
        for (int x : hours)
            ++A[x % 24];
        for (int i = 1; i < 12; ++i)
            result += 1LL * A[i] * A[24 - i];
        result += 1LL * A[0] * (A[0] - 1) / 2;
        result += 1LL * A[12] * (A[12] - 1) / 2;
        return result;
    }
};
