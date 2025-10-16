static int F[26][26];
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long result = 0;
        int N = cost.size();
        int M = source.size();
        int const INF = 1 << 26;
        for (int V = 0; V < 26; ++V)
            for (int U = 0; U < 26; ++U)
                F[V][U] = INF;
        for (int V = 0; V < 26; ++V)
            F[V][V] = 0;
        for (int i = 0; i < N; ++i)
        {
            int const V = original[i] - 'a';
            int const U = changed[i] - 'a';
            int const& C = cost[i];
            F[V][U] = min(F[V][U], C);
        }
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
        for (int i = 0; i < M; ++i)
        {
            int const V = source[i] - 'a';
            int const U = target[i] - 'a';
            if (F[V][U] < INF)
                result += F[V][U];
            else
                return -1;
        }
        return result;
    }
};
