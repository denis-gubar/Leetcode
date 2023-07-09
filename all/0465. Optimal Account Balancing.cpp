int static F[1 << 12];
int static B[1 << 12];
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int N = 0;
        int T = transactions.size();
        for (vector<int> const& t : transactions)
        {
            int const& from = t[0];
            int const& to = t[1];
            N = max(N, max(from, to));
        }
        ++N;
        vector<int> balance(N);
        for (vector<int> const& t : transactions)
        {
            int const& from = t[0];
            int const& to = t[1];
            int const& amount = t[2];
            balance[from] -= amount;
            balance[to] += amount;
        }
        memset(F, 0, sizeof(F));
        memset(B, 0, sizeof(B));
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            for (int k = N - 1; k >= 0 && mask < (1 << k); --k)
                B[mask | (1 << k)] = B[mask] + balance[k];
        }
        for (int mask = 0; mask < (1 << N); ++mask)
            for(int k = N - 1; k >= 0; --k)
                if ((mask & (1 << k)) == 0)
                {
                    int const newMask = mask | (1 << k);
                    F[newMask] = max(F[newMask], F[mask] + (B[newMask] == 0));
                }
        return N - F[(1 << N) - 1];
    }
};
