class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int N = arr.size();
        long long result = 0LL;
        vector<int> A(N);
        auto calc = [&arr, N, &A](int delta)
        {
            long long result = 0LL;
            for (int shift = 0; shift < delta; ++shift)
            {
                int i = 0;
                for (int pos = shift; pos < N; pos += delta, ++i)
                    A[i] = arr[pos];
                sort(A.begin(), A.begin() + i);
                int M = A[i / 2];
                for (int j = 0; j < i; ++j)
                    result += abs(M - A[j]);
            }
            return result;
        };
        return calc(gcd(k, N));
    }
};
