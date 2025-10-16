class Solution {
public:
    int calc(int V)
    {
        int result = nums[V];
        for (int U : children[V])
            result ^= calc(U);
        A[V] = result;
        return result;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        result = 1'000'000'000;
        int N = nums.size();
        vector<vector<int>> connectivity(N);
        children = vector<vector<int>>(N);
        F = vector<vector<bool>>(N, vector<bool>(N));
        A = vector<int>(N);
        total = 0;
        for (int i = 0; i < N; ++i)
            total ^= nums[i];
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        int root = -1;
        for (int V = 0; V < N; ++V)
            if (connectivity[V].size() == 1)
            {
                root = V;
                break;
            }
        queue<int> Q;
        Q.push(root);
        vector<bool> visited(N);
        visited[root] = true;        
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            for (int U : connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    children[V].push_back(U);
                    Q.push(U);
                }
        }
        for (int i = 0; i < N; ++i)
        {
            queue<int> Q;
            Q.push(i);
            while (!Q.empty())
            {
                int V = Q.front(); Q.pop();
                for (int U : children[V])
                {
                    F[i][U] = true;
                    Q.push(U);
                }
            }
        }
        calc(root);
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
            {
                int X, Y, Z;
                if (i == root)
                {
                    X = nums[i];
                    Y = A[j];
                    Z = total ^ X ^ Y;
                }
                else if (F[i][j])
                {
                    X = A[i] ^ A[j];
                    Y = A[j];
                    Z = total ^ A[i];
                }
                else if (F[j][i])
                {
                    X = A[i];
                    Y = A[i] ^ A[j];
                    Z = total ^ A[j];
                }
                else
                {
                    X = A[i];
                    Y = A[j];
                    Z = total ^ X ^ Y;
                }
                result = min(result, max({ X, Y, Z }) - min({ X, Y, Z }));
            }
        return result;
    }
    vector<int> A;
    vector<vector<int>> children;
    vector<int> nums;
    vector<vector<bool>> F;
    int result, total;
};
