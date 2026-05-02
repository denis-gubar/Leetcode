static unsigned int P[100'000];
class Solution {
public:
    int maxDistance(unsigned int side, vector<vector<int>>& points, int K) {
        int const N = points.size();
        points.push_back(points[0]);
        int a = 0, b = side + 1;
        auto plain = [&](int i) -> int
            {
                int const& x = points[i][0];
                int const& y = points[i][1];
                if (x == 0)
                    return y;
                if (y == side)
                    return side + x;
                if (x == side)
                    return 3 * side - y;
                return 4 * side - x;
            };
        for (int i = 0; i < N; ++i)
            P[i] = plain(i);
        sort(&P[0], &P[0] + N);
        auto calc = [&](int m) -> bool
            {
                int right = 1;
                while (right < N && P[right] - P[0] < m)
                    ++right;
                if (right == N)
                    return false;
                for (int start = 0; start < right; ++start)
                {
                    unsigned int length = P[N - 1] - P[start];
                    if (1LL * m * (K - 1) > length)
                        break;
                    int prev = start;
                    bool flag = true;
                    for (int k = 1; k < K; ++k)
                    {
                        int pos = prev + 1;
                        while (pos < N && P[pos] - P[prev] < m)
                            ++pos;
                        length -= P[pos] - P[prev];
                        if (1LL * m * (K - 1 - k) > length)
                        {
                            flag = false;
                            break;
                        }
                        prev = pos;
                    }
                    if (flag && 4 * side - (P[prev] - P[start]) >= m)
                        return true;
                }
                return false;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
