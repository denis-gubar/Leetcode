class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {		
        int N = grid.size(), M = grid[0].size();
        int result = N * M;
        int hwm = M;
		for(int i = 0; i < N; ++i)
        {
            while(hwm > 0 && grid[i][hwm - 1] < 0)
                --hwm;
            if (hwm == 0)
                break;
            result -= hwm;
        }
		return result;
	}
};