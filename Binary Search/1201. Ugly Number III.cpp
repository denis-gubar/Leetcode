class Solution {
public:
    int nthUglyNumber(int N, int a, int b, int c) {
        if (a == 1 || b == 1 || c == 1)
            return N;
        auto calc = [A = 1LL * a, B = 1LL * b, C = 1LL * c](long long m) -> long long
            {
                return m / A + m / B + m / C - m / lcm(A, B) - m / lcm(B, C) - m / lcm(C, A) + m / lcm(lcm(A, B), C);
            };
        long long A = 1, B = 2'000'000'000;
        while (A + 1 < B)
        {
            int m = (A + B) / 2;
            if (calc(m) >= N)
                B = m;
            else
                A = m;
        }
        return B;
    }
};
