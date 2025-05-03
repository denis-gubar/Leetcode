class Solution {
public:
    int countCoveredBuildings(int N, vector<vector<int>>& buildings) {
        set<pair<int, int>> S, R;
        for (vector<int> const& b : buildings)
        {
            S.insert({ b[0], b[1] });
            R.insert({ b[1], b[0] });
        }
        int result = 0;
        for (vector<int> const& b : buildings)
        {
            auto check = [](set<pair<int, int>>& S, int x, int y)
                {
                    auto it = S.lower_bound({ x, 0 });
                    if (it == S.end())
                        return false;
                    if (it->first != x)
                        return false;
                    if (it->second >= y)
                        return false;
                    it = S.upper_bound({ x, y });
                    if (it == S.end())
                        return false;
                    if (it->first != x)
                        return false;
                    return true;
                };
            if (check(S, b[0], b[1]) && check(R, b[1], b[0]))
                ++result;
        }
        return result;
    }
};
