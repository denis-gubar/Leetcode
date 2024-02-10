class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int result = 0;
        int N = points.size();
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
        {
            int const& a = points[i][0];
            int const& b = points[i][1];
            M[a].push_back(b);
        }
        vector<int> XS;
        int const& K = M.size();
        XS.reserve(K);
        for (auto it = M.begin(); it != M.end(); ++it)
        {
            XS.push_back(it->first);
            sort(it->second.begin(), it->second.end());
        }
        sort(XS.begin(), XS.end());
        for (int i = 0; i < K; ++i)
        {
            int const& x = XS[i];
            result += M[x].size() - 1;
            int best = -(1 << 30);
            for (int y : M[x])
            {
                for (int j = i + 1; j < K; ++j)
                {
                    int const& x2 = XS[j];
                    bool flag = false;
                    for (int y2 : M[x2])
                    {
                        if (y2 > y)
                            break;
                        if (y2 <= best)
                            continue;
                        flag = true;
                        best = y2;
                    }
                    result += flag;
                }
                best = y;
            }
        }
        return result;
    }
};
