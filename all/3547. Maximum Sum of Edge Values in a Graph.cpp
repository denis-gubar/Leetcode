class Solution {
public:
    long long maxScore(int N, vector<vector<int>>& edges) {
        long long result = 0;
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<bool> visited(N);
        queue<int> Q;
        vector<int> A, B;
        for(int V = 0; V < N; ++V)
            if (!visited[V])
            {
                visited[V] = true;
                Q.push(V);
                int count = 1;
                bool isCycle = connectivity[V].size() > 1;
                while (!Q.empty())
                {
                    int const V = Q.front(); Q.pop();
                    for(int const U : connectivity[V])
                        if (!visited[U])
                        {
                            visited[U] = true;
                            Q.push(U);
                            ++count;
                            isCycle &= connectivity[U].size() > 1;
                        }
                }
                if (count == 1)
                    continue;
                if (!isCycle)
                    A.push_back(count);
                else
                    B.push_back(count);
            }
        int I = N;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        deque<int> D;
        while (!B.empty())
        {
            D.clear();
            D.push_back(I);
            int x = B.back(); B.pop_back();
            --I, --x;
            while (x > 0)
            {
                D.push_back(I);
                --I, --x;
                if (x > 0)
                {
                    D.push_front(I);
                    --I, --x;
                }
            }
            result += 1LL * D.front() * D.back();
            int prev = D.front(); D.pop_front();
            while (!D.empty())
            {
                result += 1LL * prev * D.front();
                prev = D.front(); D.pop_front();
            }
        }
        while (!A.empty())
        {
            D.clear();
            D.push_back(I);
            int x = A.back(); A.pop_back();
            --I, --x;
            while(x > 0)
            {
                D.push_back(I);
                --I, --x;
                if (x > 0)
                {
                    D.push_front(I);
                    --I, --x;
                }
            }
            int prev = D.front(); D.pop_front();
            while (!D.empty())
            {
                result += 1LL * prev * D.front();
                prev = D.front(); D.pop_front();
            }
        }
        return result;
    }
};
