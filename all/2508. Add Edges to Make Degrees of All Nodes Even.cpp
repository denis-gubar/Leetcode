class Solution {
public:
    bool isPossible(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> connectivity(N + 1);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].insert(U);
            connectivity[U].insert(V);
        }
        vector<int> odd;
        for (int i = 1; i <= N; ++i)
            if (connectivity[i].size() % 2 == 1)
                odd.push_back(i);
        int K = odd.size();
        if (K == 0)
            return true;
        auto check = [&connectivity](int a, int b)
        {
            return connectivity[a].find(b) == connectivity[a].end();
        };
        if (K == 2)
        {
            int a = odd[0];
            int b = odd[1];
            if (check(a, b))
                return true;
            for (int c = 1; c <= N; ++c)
                if (c != a && c != b && check(a, c) && check(b, c))
                    return true;                    
            return false;
        }
        if (K == 4)
        {
            int a = odd[0];
            int b = odd[1];
            int c = odd[2];
            int d = odd[3];
            return check(a, b) && check(c, d) || check(a, c) && check(b, d) || check(a, d) && check(b, c);
        }
        return false;
    }
};
