class Solution {
public:
    int findKthNumber(int N, int K) {
        int result = 0;
        auto calc = [&N](int prefix)
            {
                if (prefix == 0) return 0;
                int pp = prefix;
                int result = 0, P = 10;
                result += prefix <= N;
                while (1LL * prefix * 10 <= N)
                {
                    prefix *= 10;
                    result += min(P, N - prefix + 1);
                    P *= 10;
                }
                if (1LL * pp * P < N && (pp + 1LL) * P > N)
                    result += N - prefix + 1;
                return result;
            };
        while (K > 0)
        {
            int d = 0;
            while (true)
            {               
                int x = calc(result * 10 + d);
                if (x > K)
                {
                    --K;
                    result = result * 10 + d;
                    break;
                }
                if (d == 9 || x == K)
                {
                    result = result * 10 + d;
                    --K;
                    break;
                }
                ++d;
                K -= x;
            }
        }
        return result;
    }
};
