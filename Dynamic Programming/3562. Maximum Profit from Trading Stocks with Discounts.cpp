static short F[160][161][2];
class Solution {
public:
    int maxProfit(int N, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<unsigned char>> connectivity(N);
        for (vector<int> const& h : hierarchy)
        {
            unsigned char const V = h[0] - 1;
            unsigned char const U = h[1] - 1;
            connectivity[V].push_back(U);
        }
        memset(F, -100, sizeof(F));
        auto dfs = [&](this const auto& self, unsigned char V) -> void
            {
                auto update = [](auto& x, auto value)
                    {
                        if (x < value)
                            x = value;
                    };
                for (unsigned char U : connectivity[V])
                    self(U);
                for (int includeParent = 0; includeParent < 2; ++includeParent)
                {
                    short const profit = future[V] - present[V] / (1 + includeParent);
                    short const spent = present[V] / (1 + includeParent);
                    short T[2][161];
                    memset(T, -100, sizeof(T));
                    T[0][0] = 0;
                    F[V][0][includeParent] = 0;
                    unsigned char i = 0;
                    for (unsigned char U : connectivity[V])
                    {
                        i = 1 - i;
                        for (unsigned char b = 0; b <= budget; ++b)
                        {
                            update(T[i][b], T[1 - i][b]);
                            if (F[U][b][false] > -1000)
                                for (unsigned char c = 0; b + c <= budget; ++c)
                                    if (T[1 - i][c] > -1000)
                                        update(T[i][b + c], F[U][b][false] + T[1 - i][c]);
                        }
                    }
                    for (unsigned char b = 1; b <= budget; ++b)
                        update(F[V][b][includeParent], T[i][b]);
                    memset(T, -100, sizeof(T));
                    T[0][spent] = profit;
                    i = 0;
                    for (unsigned char U : connectivity[V])
                    {
                        i = 1 - i;
                        for (unsigned char b = 0; b <= budget; ++b)
                        {
                            update(T[i][b], T[1 - i][b]);
                            if (F[U][b][true] > -1000)
                                for (unsigned char c = 0; b + c <= budget; ++c)
                                    if (T[1 - i][c] > -1000)
                                        update(T[i][b + c], F[U][b][true] + T[1 - i][c]);
                        }
                    }
                    for (unsigned char b = spent; b <= budget; ++b)
                        update(F[V][b][includeParent], T[i][b]);
                }
            };
        dfs(0);
        short result = 0;
        for (unsigned char b = 0; b <= budget; ++b)
            result = max(result, F[0][b][false]);
        return result;
    }
};
