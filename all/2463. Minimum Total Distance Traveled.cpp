static long long F[101][101][101];
class Solution {
public:    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int N = robot.size(), M = factory.size();
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());
        memset(F, 125, sizeof(F));
        const long long INF = F[0][0][0];
        long long result = INF;
        F[0][0][0] = 0;
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for (int k = 0; k <= factory[j][1]; ++k)
                    if (F[i][j][k] < INF)
                    {                        
                        F[i][j + 1][0] = min(F[i][j + 1][0], F[i][j][k]);
                        if (k < factory[j][1])
                            F[i + 1][j][k + 1] = min(F[i + 1][j][k + 1], F[i][j][k] + abs(robot[i] - factory[j][0]));
                    }
        for (int j = 0; j < M; ++j)
            for (int k = 0; k <= factory[j][1]; ++k)
                result = min(result, F[N][j][k]);
        return result;
    }
};
