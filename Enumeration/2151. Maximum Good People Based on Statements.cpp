class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int result = 0;
        int N = statements.size();        
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            bool isOk = true;
            int good = 0;
            for(int k = 0; k < N; ++k)
                if (mask & (1 << k))
                {
                    ++good;
                    for (int j = 0; j < N; ++j)
                    {
                        bool isOtherGood = (mask & (1 << j)) > 0;
                        if (statements[k][j] != 2 && statements[k][j] != isOtherGood)
                        {
                            isOk = false;
                            break;
                        }
                    }
                    if (!isOk)
                        break;
                }
            if (isOk)
                result = max(result, good);
        }
        return result;
    }
};
