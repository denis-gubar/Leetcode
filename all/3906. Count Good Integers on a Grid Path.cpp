static int D[8];
class Solution {
public:
    long long countGoodIntegersOnPath(long long L, long long R, string directions) {
        long long result = 0;
        D[0] = 0; D[7] = 15;
        for (int i = 0; i < 6; ++i)
            D[i + 1] = D[i] + (directions[i] == 'D' ? 4 : 1);
        string A = to_string(L);
        if (A.size() < 16)
            A = string(16 - A.size(), '0') + A;
        string B = to_string(R);
        if (B.size() < 16)
            B = string(16 - B.size(), '0') + B;
        auto dfs = [&](this const auto& self, long long count, long long prefix, int level, int pos, bool isA, bool isB) -> void
            {
                if (pos == 16)
                {
                    result += count;
                    return;
                }
                if (pos < D[level])
                {
                    int const a = A[pos] - '0', b = B[pos] - '0';
                    int delta = 0;
                    for (int d = 0; d < 10; ++d)
                        if ((isA && d >= a || !isA) && (isB && d <= b || !isB))
                        {
                            if (isA && d == a)
                                self(count, prefix, level, pos + 1, isA, isB && d == b);
                            else if (isB && d == b)
                                self(count, prefix, level, pos + 1, isA && d == a, isB);
                            else
                                ++delta;
                        }
                    if (delta > 0)
                        self(count * delta, prefix, level, pos + 1, false, false);
                    return;
                }
                int const a = A[pos] - '0', b = B[pos] - '0';
                for (int d = prefix % 10; d < 10; ++d)
                    if ((isA && d >= a || !isA) && (isB && d <= b || !isB))
                        self(count, prefix * 10 + d, level + 1, pos + 1, isA && d == a, isB && d == b);
            };
        dfs(1LL, 0, 0, 0, true, true);
        return result;
    }
};
