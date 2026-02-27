class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int const N = towers.size();
        vector<vector<int>> T;
        T.reserve(N);
        int const& CX = center[0];
        int const& CY = center[1];
        for (int i = 0; i < N; ++i)
        {
            int const& X = towers[i][0];
            int const& Y = towers[i][1];
            int const& Q = towers[i][2];
            if (abs(X - CX) + abs(Y - CY) <= radius)
                T.push_back(towers[i]);
        }
        if (T.empty())
            return { -1, -1 };
        auto it = min_element(T.begin(), T.end(), [&](vector<int> const& a, vector<int> const& b)
            {
                if (a[2] != b[2])
                    return a[2] > b[2];
                return a < b;
            });
        return vector<int>{ (*it)[0], (*it)[1] };
    }
};
