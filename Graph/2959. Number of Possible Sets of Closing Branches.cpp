static int F[10][10];
static int G[10][10];
class Solution {
public:
    int numberOfSets(int N, int maxDistance, vector<vector<int>>& roads) {
        int result = 0;
        memset(G, 1, sizeof(G));
        for (int V = 0; V < N; ++V)
            G[V][V] = 0;
        for (vector<int> const& e : roads)
        {
            int const& V = e[0];
            int const& U = e[1];
            int const& length = e[2];
            G[V][U] = G[U][V] = min({ G[V][U], G[U][V], length });
        }
        vector<int> A;
        A.reserve(N);
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            A.clear();
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    A.push_back(k);
            memcpy(F, G, sizeof(G));
            for (int k : A)
                for (int i : A)
                    for (int j : A)
                        if (F[i][j] > F[i][k] + F[k][j])
                            F[i][j] = F[i][k] + F[k][j];
            bool isGood = true;
            for (int i : A)
                for (int j : A)
                    isGood &= F[i][j] <= maxDistance;
            result += isGood;
        }
        return result;
    }
};
