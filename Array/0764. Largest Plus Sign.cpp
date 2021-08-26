class Solution {
public:
    int orderOfLargestPlusSign( int N, vector<vector<int>>& mines ) {
        int result = 0;
        vector<vector<int>> M( N + 2, vector<int>( N + 2 ) );
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                M[i][j] = 1;
        for (const auto& m : mines)
            M[m[0] + 1][m[1] + 1] = 0;
        vector<int> dx = { 0, 1, 0, -1 };
        vector<int> dy = { 1, 0, -1, 0 };
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                if (M[i][j] == 1)
                {
                    int k = 0;
                    int count = 4;
                    while (count == 4)
                    {
                        count = 0;
                        for (int z = 0; z < 4; ++z)
                            count += M[i + k * dx[z]][j + k * dy[z]];
                        if ( count == 4 )
                            ++k;
                    }
                    if (result < k)
                        result = k;
                }
        return result;
    }
};