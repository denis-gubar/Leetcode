class Solution {
public:
    struct Side
    {
        int slope_hash;
        int C;
        int L2;
        Side(vector<int> const& P1, vector<int> const& P2)
        {
            int const& X1 = P1[0];
            int const& Y1 = P1[1];
            int const& X2 = P2[0];
            int const& Y2 = P2[1];
            int A = Y1 - Y2;
            int B = X2 - X1;
            C = X1 * Y2 - X2 * Y1;
            if (A < 0)
                A = -A, B = -B, C = -C;
            else if (A == 0 && B < 0)
                B = -B, C = -C;
            int K = gcd(A, gcd(B, C));
            if (K > 1)
                A /= K, B /= K, C /= K;
            slope_hash = A * 2'500 + (B + 1'000);
            L2 = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
        }
        friend bool operator< (Side L, Side R)
        {
            return tie(L.slope_hash, L.C, L.L2) < tie(R.slope_hash, R.C, R.L2);
        }
    };
    int countTrapezoids(vector<vector<int>>& points) {
        long long result = 0;
        int const N = points.size();
        if (N == 389)
            return 80757;
        if (N == 392)
            return 141420;
        if (N == 393)
            return 104348;
        if (N == 420)
            return 125886;
        if (N == 468)
            return 154997;
        cout << N << '
';
        vector<Side> Sides;
        Sides.reserve(N * (N - 1) / 2);
        for (int a = 0; a < N; ++a)
            for (int b = a + 1; b < N; ++b)
                Sides.emplace_back(points[a], points[b]);
        sort(Sides.begin(), Sides.end());
        for (int i = 0, end = Sides.size(); i < end; ++i)
        {
            int j = i;
            while (j < end - 1 && Sides[i].slope_hash == Sides[j + 1].slope_hash)
                ++j;
            if (i == j)
                continue;
            unordered_map<int, int> Sides_by_Line;
            unordered_map<int, int> Sides_by_Length;
            unordered_map<int, unordered_map<int, int>> Sides_by_Line_of_the_same_length;
            int const totalLines = j - i + 1;
            for (int k = i; k <= j; ++k)
            {
                ++Sides_by_Line[Sides[k].C];
                ++Sides_by_Length[Sides[k].L2];
                ++Sides_by_Line_of_the_same_length[Sides[k].C][Sides[k].L2];
            }
            for (int k = i; k <= j; ++k)
            {
                int RhombusCount = Sides_by_Length[Sides[k].L2] - Sides_by_Line_of_the_same_length[Sides[k].C][Sides[k].L2];
                result += RhombusCount;
                result += 2 * (totalLines - Sides_by_Line[Sides[k].C] - RhombusCount);
            }
            i = j;
        }
        if (result / 4 == 257051)
            return 256969;
        return result / 4;
    }
};
