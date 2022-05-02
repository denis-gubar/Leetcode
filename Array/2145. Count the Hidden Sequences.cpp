class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long result = 0;
        int N = differences.size();
        vector<long long> A(N + 1);
        A[0] = lower;
        long long a = lower, b = lower;
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] + differences[i];
			a = min(a, A[i + 1]);
			b = max(b, A[i + 1]);
        }
        while (b <= upper)
        {
            if (a >= lower)
                ++result;
            ++a, ++b;
        }
        return result;
    }
};
