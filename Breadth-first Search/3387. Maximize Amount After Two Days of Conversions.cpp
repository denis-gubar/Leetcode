class Solution {
public:
    void calc(vector<double>& best, vector<pair<int, int>> const& P, vector<double> const& rates, int V, double amount)
    {
        int const N = P.size();
        for(int i = 0; i < N; ++i)
            if (P[i].first == V)
            {
                int const& U = P[i].second;
                if (amount * rates[i] > best[U])
                {
                    best[U] = amount * rates[i];
                    calc(best, P, rates, U, best[U]);
                }
            }
            else if (P[i].second == V)
            {
                int const& U = P[i].first;
                if (amount / rates[i] > best[U])
                {
                    best[U] = amount / rates[i];
                    calc(best, P, rates, U, best[U]);
                }
            }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        double result = 1.0;
        int const N1 = pairs1.size(), N2 = pairs2.size();
        unordered_map<string, int> M;
        int count = 0;
        vector<pair<int, int>> P1, P2;
        P1.reserve(N1);
        P2.reserve(N2);        
        for (int i = 0; i < N1; ++i)
        {
            if (M.find(pairs1[i][0]) == M.end())
                M[pairs1[i][0]] = count, ++count;
            if (M.find(pairs1[i][1]) == M.end())
                M[pairs1[i][1]] = count, ++count;
            P1.emplace_back(M[pairs1[i][0]], M[pairs1[i][1]]);
        }
        for (int i = 0; i < N2; ++i)
        {
            if (M.find(pairs2[i][0]) == M.end())
                M[pairs2[i][0]] = count, ++count;
            if (M.find(pairs2[i][1]) == M.end())
                M[pairs2[i][1]] = count, ++count;
            P2.emplace_back(M[pairs2[i][0]], M[pairs2[i][1]]);
        }
        vector<double> best(count);
        best[M[initialCurrency]] = 1.0;
        calc(best, P1, rates1, M[initialCurrency], 1.0);
        for (int V = 0; V < count; ++V)
            if (best[V] > 0)
                calc(best, P2, rates2, V, best[V]);
        return best[M[initialCurrency]];
    }
};
