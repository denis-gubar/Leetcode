class Solution {
public:
    bool isAdditiveNumber(string num) {
        int const N = num.size();
        string_view sw(num);
        auto check = [](string_view s) -> long long
            {
                long long A = stoll(string(s));
                if (to_string(A) != s)
                    return -1LL;
                return A;
            };
        for (int a = 1; a <= N / 2; ++a)
        {            
            long long AA = check(sw.substr(0, a));
            if (AA < 0)
                continue;
            for (int b = 1; b <= N / 2; ++b)
            {
                long long A = AA;
                long long B = check(sw.substr(a, b));
                if (B < 0)
                    continue;
                A += B;
                int L = to_string(A).size();
                int pos = a + b;
                if (pos == N)
                    return false;
                while (pos + L <= N)
                {
                    if (sw.substr(pos, L) != to_string(A))
                        break;
                    pos += L;
                    long long NB = A;
                    A += B;
                    B = NB;
                    L = to_string(A).size();
                }
                if (pos == N)
                    return true;
            }
        }
        return false;
    }
};
