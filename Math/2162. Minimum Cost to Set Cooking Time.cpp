class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int const INF = 1'000'000'000;
        int result = INF;
        vector<vector<int>> F(10, vector<int>(10'000, INF));
        queue<int> Q;
        int start = startAt, total = 0;
        F[startAt][total] = 0;
        Q.push(start); Q.push(total);
        while (!Q.empty())
        {
            start = Q.front(); Q.pop();
            total = Q.front(); Q.pop();
            for (int i = 0; i < 10; ++i)
            {
                int cost = moveCost * (i != start ? 1 : 0) + pushCost;
                int next = total * 10 + i;
                if (next < 10'000 && F[i][next] > F[start][total] + cost)
                {
                    F[i][next] = F[start][total] + cost;
                    Q.push(i); Q.push(next);
                }
            }
        }
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10'000; ++j)
                if (j / 100 * 60 + j % 100 == targetSeconds)
                    result = min(result, F[i][j]);            
        return result;
    }
};
