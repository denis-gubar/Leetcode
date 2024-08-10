static int F[50][50];
static int A[50];
static int const INF = 1 << 30;
class Solution {
public:
    int calc(int V, int U)
    {
        int& result = F[V][U];
        if (U < V + 2)
            return result = 0;
        if (result > INF)
            for (int W = V + 1; W != U; ++W)
                result = min(result, calc(V, W) + calc(W, U) + A[V] * A[W] * A[U]);
        return result;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(F, 64, sizeof(F));
        int const N = values.size();
        copy(values.begin(), values.end(), &A[0]);
        return calc(0, N - 1);
    }
};
