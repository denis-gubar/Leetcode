static int F[100'005][2];
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int result = 0;
        int const INF = 1'000'000'002;
        int const R = robots.size(), W = walls.size();
        robots.push_back(-INF); distance.push_back(0);
        robots.push_back(2 * INF); distance.push_back(0);
        sort(walls.begin(), walls.end());
        vector<int> I(R + 2);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&robots](int a, int b)
            {
                return robots[a] < robots[b];
            });
        vector<int> robotsTemp(robots), distanceTemp(distance);
        for (int i = 0; i < R + 2; ++i)
        {
            int const& pos = I[i];
            robots[i] = robotsTemp[pos];
            distance[i] = distanceTemp[pos];
        }
        robots[0] = robots[1] - distance[1] - 1;
        robots[R + 1] = robots[R] + distance[R] + 1;
        memset(F, 0, sizeof(F));
        auto calc = [&walls](int left, int right) -> int
            {
                auto itL = lower_bound(walls.begin(), walls.end(), left);
                if (itL == walls.end() || *itL > right)
                    return 0;
                auto itR = lower_bound(walls.begin(), walls.end(), right + 1);
                if (itR == walls.begin())
                    return 0;
                --itR;
                if (*itR < left)
                    return 0;
                return itR - itL + 1;
            };
        for (int i = 1; i <= R; ++i)
        {
            F[i][0] = max(F[i - 1][0] + calc(max(robots[i - 1] + 1, robots[i] - distance[i]), robots[i]),
                F[i - 1][1] + calc(min(robots[i], max(robots[i - 1] + distance[i - 1] + 1, robots[i] - distance[i])), robots[i]));
            F[i][1] = max(F[i - 1][0], F[i - 1][1]) +
                calc(robots[i], min(robots[i] + distance[i], robots[i + 1] - 1));
        }
        return max(F[R][0], F[R][1]);
    }
};
