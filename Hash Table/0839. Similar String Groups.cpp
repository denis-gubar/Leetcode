class Solution {
public:
    int numSimilarGroups( vector<string>& A ) {
        int result = 0;
        sort(A.begin(), A.end());
        A.resize(unique(A.begin(), A.end()) - A.begin());
        int n = A.size(), m = A[0].size();
        vector<vector<int>> connectivity( n );
        for(int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int diffCount = 0;
                for(int k = 0; k < m; ++k)
                    if (A[i][k] != A[j][k])
                    {
                        ++diffCount;
                        if (diffCount == 3)
                            break;
                    }
                if (diffCount == 2)
                {
                    connectivity[i].push_back( j );
                    connectivity[j].push_back( i );
                }
            }
        vector<int> groups(n);
        for (int i = 0; i < n; ++i)
            if (!groups[i])
            {
                ++result;
                groups[i] = result;
                queue<int> q;
                q.push( i );
                while (!q.empty())
                {
                    int v = q.front(); q.pop();
                    for(int u: connectivity[v])
                        if (!groups[u])
                        {
                            groups[u] = result;
                            q.push( u );
                        }
                }
            }
        return result;
    }
};