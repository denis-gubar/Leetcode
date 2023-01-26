class Solution {
public:
    long long maxPower(vector<int>& stations, long long r, long long k) {
        int N = stations.size();
        long long a = 0, b = 1LL << 50;
        auto calc = [&stations, r, k, N](long long m)
        {
            vector<int> A(stations);
            long long count = 0;
            long long current = 0;
            for (int i = 0; i <= r; ++i)
                current += A[i];
            long long delta = max(0LL, m - current);
            count += delta;
            if (count > k)
                return false;
            current += delta;
            A[r] += delta;
            for (int i = 1; i < N; ++i)
            {
                if (i - r - 1 >= 0)
                    current -= A[i - r - 1];
                if (i + r < N)
                    current += A[i + r];
                delta = max(0LL, m - current);
                count += delta;
                if (count > k)
                    return false;
                current += delta;
                A[min<int>(N - 1, i + r)] += delta;
            }
            return true;
        };
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
