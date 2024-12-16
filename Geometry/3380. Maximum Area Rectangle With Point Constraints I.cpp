class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int result = -1;
        int const N = points.size();
        vector<int> A;
        A.reserve(4);
        for (int a = 0; a < N; ++a)
            for (int b = a + 1; b < N; ++b)
                for (int c = b + 1; c < N; ++c)
                    for (int d = c + 1; d < N; ++d)
                    {
                        A.clear();
                        A.push_back(a);
                        A.push_back(b);
                        A.push_back(c);
                        A.push_back(d);
                        sort(A.begin(), A.end(), [&points](int a, int b)
                            {
                                if (points[a][0] != points[b][0])
                                    return points[a][0] < points[b][0];
                                return points[a][1] < points[b][1];
                            });
                        int const& x0 = points[A[0]][0], y0 = points[A[0]][1];
                        int const& x1 = points[A[1]][0], y1 = points[A[1]][1];
                        int const& x2 = points[A[2]][0], y2 = points[A[2]][1];
                        int const& x3 = points[A[3]][0], y3 = points[A[3]][1];
                        if (x0 == x1 && x2 == x3 && y0 == y2 && y1 == y3 && result < (y3 - y0) * (x3 - x0))
                        {
                            bool flag = true;
                            for (int x = 0; x < N; ++x)
                                if (x != a && x != b && x != c && x != d)
                                {
                                    int const& X = points[x][0], Y = points[x][1];
                                    flag &= !(x0 <= X && X <= x3 && y0 <= Y && Y <= y3);
                                }
                            if (flag)
                                result = (y3 - y0) * (x3 - x0);
                        }
                    }
        return result;
    }
};
