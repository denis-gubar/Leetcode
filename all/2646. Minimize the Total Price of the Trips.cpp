class Solution {
public:
    vector<vector<int>> connectivity;
    vector<int> price, visits;
    vector<vector<int>> F;
    int calc(int V, long long visited, long long marked, bool flag = true)
    {
        int& result = F[flag][V];
        if (result < 0)
        {
            result = 0;
            if (flag)
            {
                int current = price[V] / 2 * visits[V];
                for (int U : connectivity[V])
                    if ((visited & (1LL << U)) == 0)
                        current += calc(U, visited | (1LL << U), marked | (1LL << V), false);
                result = max(result, current);
            }
            int current = 0;
            for (int U : connectivity[V])
                if ((visited & (1LL << U)) == 0)
                    current += calc(U, visited | (1LL << U), marked, true);
            result = max(result, current);
        }
        return result;
    }
    int minimumTotalPrice(int N, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        connectivity = vector<vector<int>>(N);
        this->price = price;
        vector<vector<long long>> Path(N, vector<long long>(N));
        F = vector<vector<int>>(2, vector<int>(N, -1));
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<long long> Q;
        for (int i = 0; i < N; ++i)
        {
            Q.push(i); Q.push(1LL << i);
            while (!Q.empty())
            {
                long long V = Q.front(); Q.pop();
                long long mask = Q.front(); Q.pop();
                Path[i][V] = mask;
                for(int U : connectivity[V])
                    if ((mask & (1LL << U)) == 0LL)
                    {
                        Q.push(U); Q.push(mask | (1LL << U));
                    }
            }
        }
        visits = vector<int>(N);
        for (vector<int> const& t : trips)
        {
            int const& V = t[0];
            int const& U = t[1];
            for (int k = 0; k < N; ++k)
                if (Path[V][U] & (1LL << k))
                    ++visits[k];
        }
        int result = 0;
        for (int i = 0; i < N; ++i)
            result += visits[i] * price[i];
        result -= calc(0, 1LL, 0LL);
        return result;
    }
};
