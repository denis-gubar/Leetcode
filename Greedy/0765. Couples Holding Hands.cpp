class Solution {
public:
    int check( int i, const vector<int> row )
    {
        int a = min( row[i], row[i + 1] );
        int b = max( row[i], row[i + 1] );
        if (a % 2 == 0 && a + 1 == b)
            return 1;
        return 0;
    }
    int minSwapsCouples( vector<int>& row ) {
        int result = 0;
        while (!row.empty())
        {
            for (int i = 0; i + 1 < row.size(); i += 2)
            {
                int a = min( row[i], row[i + 1] );
                int b = max( row[i], row[i + 1] );
                if (a % 2 == 0 && a + 1 == b)
                {
                    row.erase( row.erase( row.begin() + i ) );
                    i -= 2;
                }
            }
            int bestI = -1, bestJ = -1;
            int best = -1;
            for(int i = 0; i + 1 < row.size(); ++i)
                for (int j = i + 1; j < row.size(); ++j)
                    if (i + 1 < j || i % 2 == 1)
                    {
                        swap( row[i], row[j] );
                        int current = check( i / 2 * 2, row ) + check( j / 2 * 2, row );
                        if (current > best)
                        {
                            best = current;
                            bestI = i;
                            bestJ = j;
                        }
                        swap( row[i], row[j] );
                    }
            if (best > 0)
            {
                swap( row[bestI], row[bestJ] );
                ++result;
            }
        }
        return result;
    }
};