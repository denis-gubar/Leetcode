class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> result(12);
        int best = 0;
        for (int mask = 1; mask < (1 << 12); ++mask)
        {
            int score = 0;
            int x = 0;
            for (int k = 1; k < 12; ++k)
                if (mask & (1 << k))
                {
                    x += aliceArrows[k] + 1;
                    score += k;
                }
            if (best < score && x <= numArrows)
            {
                best = score;
                for (int k = 1; k < 12; ++k)
                    if (mask & (1 << k))
                        result[k] = aliceArrows[k] + 1;
                    else
                        result[k] = 0;
                result[0] = numArrows - x;
            }
        }
        return result;
    }
};
