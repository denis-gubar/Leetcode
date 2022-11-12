class Solution {
public:
    bool check(string const& a, string const& b)
    {
        int count = 0;
        for (int i = 0; i < 8; ++i)
            count += a[i] != b[i];
        return count == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if (find(bank.begin(), bank.end(), start) == bank.end())
            bank.push_back(start);
        int S = find(bank.begin(), bank.end(), start) - bank.begin();
        int N = bank.size();
        vector<vector<bool>> F(N, vector<bool>(N));
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                F[i][j] = F[j][i] = check(bank[i], bank[j]);
        vector<bool> isEnd(N), visited(N);
        for (int i = 0; i < N; ++i)
            isEnd[i] = end == bank[i];
        queue<int> Q;
        Q.push(S);
        visited[S] = true;
        Q.push(0);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            int t = Q.front(); Q.pop();
            if (isEnd[V])
                return t;
            for(int U = 0; U < N; ++U)
                if (!visited[U] && F[V][U])
                {
                    Q.push(U); Q.push(t + 1);
                    visited[U] = true;
                }
        }
        return -1;
    }
};
