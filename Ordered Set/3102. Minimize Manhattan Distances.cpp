static vector<int> BP;
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int N = points.size();
        int result = 0;
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { points[i][0], points[i][1] };
        BP.clear();
        vector<int> A(N), B(N);
        iota(A.begin(), A.end(), 0);
        iota(B.begin(), B.end(), 0);
        if (N > 10)
        {
            sort(A.begin(), A.end(), [&P](int a, int b)
                {
                    return P[a].first + P[a].second < P[b].first + P[b].second;
                });
            sort(B.begin(), B.end(), [&P](int a, int b)
                {
                    return P[a].first - P[a].second < P[b].first - P[b].second;
                });
            vector<int> C;
            C.push_back(A[0]);
            C.push_back(A[N - 1]);
            C.push_back(B[0]);
            C.push_back(B[N - 1]);
            sort(C.begin(), C.end());
            C.resize(unique(C.begin(), C.end()) - C.begin());
            for (int i : C)
                BP.push_back(i);
        }
        else
            BP = A;
        vector<int> Z(N, -1);
        for (int k : BP)
            for (int i : BP)
                if (i != k)
                    for (int j = 0; j < N; ++j)
                        if (j != k && j != i)
                            Z[k] = max(Z[k], abs(P[i].first - P[j].first) + abs(P[i].second - P[j].second));
        sort(Z.begin(), Z.end());
        for(int x : Z)
            if (x >= 0)
                return x;
        return -1;
    }
};

