class Solution {
public:
    struct Set
    {
        Set(): size(0), L(0), H(0)
        {
        }
        void add(int x)
        {
            ++size;
            if (x == 0) return;
            if (x < 0)
            {
                low[L] = x, ++L;
                sort(&low[0], &low[0] + L);
                if (L == 4)
                    --L;
            }
            else
            {
                high[H] = -x; ++H;
                sort(&high[0], &high[0] + H);
                if (H == 4)
                    --H;
            }
        }
        void merge(Set const& other)
        {
            for (int i = 0; i < other.L; ++i)
                add(other.low[i]);
            for (int i = 0; i < other.H; ++i)
                add(-other.high[i]);
        }
        long long max()
        {
            if (size < 3)
                return 1;
            long long result = 0;
            if (L > 1 && H > 0)
                result = -low[0] * low[1] * high[0];
            if (H == 3)
                result = std::max(result, -high[0] * high[1] * high[2]);
            return result;
        }
        int L, H, size;
        long long low[4];
        long long high[4];
    };
    vector<long long> result;
    vector<vector<int>> tree;
    vector<int> cost;
    int N;
    Set calc(int V)
    {
        Set S;
        S.add(cost[V]);
        for (int U : tree[V])
            S.merge(calc(U));
        result[V] = S.max();
        return S;
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        N = cost.size();
        this->cost = cost;
        result = vector<long long>(N);
        vector<vector<int>> connectivity(N);
        tree = vector<vector<int>>(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        queue<int> Q;
        vector<bool> visited(N);
        Q.push(0);
        visited[0] = true;
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for (int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U);
                    tree[V].push_back(U);
                }
        }
        calc(0);
        return result;
    }
};
