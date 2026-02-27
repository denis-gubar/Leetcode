class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double result = 0;
        int const N = squares.size();        
        double total = 0;
        map<long long, double> M;        
        for (int i = 0; i < N; ++i)
        {
            int const& Y = squares[i][1], L = squares[i][2];
            M[Y * 2LL] += L;
            M[(Y + L) * 2LL + 1] -= L;
            total += 1LL * squares[i][2] * squares[i][2];
        }
        total *= 0.5;
        double balance = 0, sum = 0;
        long long last = 0, current = 0;
        for (auto [key, value] : M)
        {
            long long delta = key / 2 - last;
            if (key % 2 == 0)
            {
                sum += delta * balance;
                balance += value;
            }
            else
            {
                sum += delta * balance;
                balance += value;
            }
            if (sum + 0.000005 >= total)
            {
                current = key / 2;
                break;
            }
            last = key / 2;
        }
        double a = last, b = current;
        sum = 0;
        auto calc = [&squares, N, total](double m) -> bool
            {
                double sum = 0;
                vector<double> D;
                D.reserve(N);
                for (int i = 0; i < N; ++i)
                {
                    int const& Y = squares[i][1], L = squares[i][2];
                    D.push_back(L * (min<double>(Y + L, m) - min<double>(Y, m)));
                }
                sort(D.begin(), D.end());
                return accumulate(D.begin(), D.end(), 0.0) <= total;
            };
        while (a + 0.000005 < b)
        {
            double m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};

