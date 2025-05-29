class Solution {
public:
    long long minCuttingCost(long long N, long long M, long long K) {
        if (N <= K && M <= K)
            return 0;
        long long result = 1LL << 40;
        if (N > K && M > K)
        {
            long long cost = (N - K) * K;
            for (long long C = M - K; C <= K; ++C)
                if (C + (N - K) <= K)
                    result = min(result, cost + C * (M - C));
            swap(N, M);
            cost = (N - K) * K;
            for (long long C = M - K; C <= K; ++C)
                if (C + (N - K) <= K)
                    result = min(result, cost + C * (M - C));
        }
        else
        {
            if (M > N)
                swap(M, N);
            result = (N - K) * K;
        }
        return result;        
    }
};
