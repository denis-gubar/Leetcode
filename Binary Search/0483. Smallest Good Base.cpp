class Solution {
public:
    using ul = unsigned long long;
    string smallestGoodBase(string n) {
        ul N = stoull(n);
        ul result = N - 1;
        for (ul x = 2; x <= 100; ++x)
        {
            for (ul total = 1, y = 1; total <= N; )
            {
                if (total == N)
                    return to_string(x);
                if (1.0 * total + 1.0 * x * y > 2 * N)
                    break;
                y *= x, total += y;
            }
        }
        for (int p = 9; p >= 2; --p)
        {
            ul a = 0, b = exp(log(1.1 * N) / p);
            while (a + 1 < b)
            {
                ul m = (a + b) / 2;
                ul total = 1;
                for (ul y = 1, k = 0; k < p; ++k)
                    y *= m, total += y;
                if (total == N)
                    return to_string(m);
                if (total < N)
                    a = m;
                else
                    b = m;
            }
        }
        return to_string(result);
    }
};
