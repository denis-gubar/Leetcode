class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int result = 0;
        vector<vector<bool>> grid(201, vector<bool>(201));
        int N = circles.size();
        for(int x = 0; x <= 200; ++x)
            for (int y = 0; y <= 200; ++y)
                for (int i = 0; i < N; ++i)
                {
					int const& xc = circles[i][0];
					int const& yc = circles[i][1];
					int const& rc = circles[i][2];
                    grid[x][y] = ((x - xc)* (x - xc) + (y - yc) * (y - yc) <= rc * rc);
                    if (grid[x][y])
                    {
                        ++result;
                        break;
                    }
                }
        return result;
    }
};
