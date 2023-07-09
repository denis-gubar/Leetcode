class Solution {
public:
    int minimumPartition(string s, int k) {
        int N = s.size();
        int const INF = 1 << 20;
        vector<int> F(N + 1, INF);
        F[0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 1; j <= 10 && i + 1 >= j; ++j)
                if (F[i + 1] > F[i + 1 - j] + 1)
                {
                    long long x = stoll(s.substr(i + 1 - j, j));
                    if (x <= k)
                        F[i + 1] = F[i + 1 - j] + 1;
                }
        if (F[N] < INF)
            return F[N];
        return -1;
    }
};
