class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int N = points.size();
        int result = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                if (i != j)
                {
                    if (points[i][0] > points[j][0] || points[i][1] < points[j][1])
                        continue;
                    int count = 0;
                    for (int k = 0; k < N; ++k)
                    {
                        if (i == k || j == k)
                            continue;
                        if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
                            points[i][1] >= points[k][1] && points[k][1] >= points[j][1])
                        {
                            ++count;
                            break;
                        }
                    }
                    result += count == 0;
                }
        return result;
    }
};
