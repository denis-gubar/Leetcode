class Solution {
public:
    int digArtifacts(int N, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int result = 0;
        vector<vector<bool>> grid(N, vector<bool>(N));
        for (vector<int> const& d : dig)
            grid[d[0]][d[1]] = true;
        for (vector<int> const& a : artifacts)
        {
			int const& r1 = a[0];
			int const& c1 = a[1];
			int const& r2 = a[2];
			int const& c2 = a[3];
            bool isOk = true;
            for (int r = r1; r <= r2; ++r)
                for (int c = c1; c <= c2; ++c)
                    isOk &= grid[r][c];
            result += isOk;
        }
        return result;
    }
};
