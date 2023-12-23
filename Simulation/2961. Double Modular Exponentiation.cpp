class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> result;
        int N = variables.size();
        for (int i = 0; i < N; ++i)
        {
            int const& a = variables[i][0];
            int const& b = variables[i][1];
            int const& c = variables[i][2];
            int const& m = variables[i][3];
            int x = 1;
            for (int k = 0; k < b; ++k)
                x = x * a % 10;
            int y = 1;
            for (int k = 0; k < c; ++k)
                y = y * x % m;
            if (y == target)
                result.push_back(i);
        }
        return result;
    }
};
