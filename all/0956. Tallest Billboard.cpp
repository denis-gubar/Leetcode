char static F[2'501][2'501];
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int N = rods.size();
        int total = accumulate(rods.begin(), rods.end(), 0);
        sort(rods.begin(), rods.end());
        int maxSum = total / 2;
        int hwm = 0;
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        vector<pair<int, int>> Q;
        Q.reserve((maxSum + 1) * (maxSum + 1));
        Q.push_back({ 0, 0 });
        for (int i = 0; i < N; ++i)
        {
            int const& delta = rods[i];
            for (int j = Q.size() - 1; j >= 0; --j)
            {
                int const& x = Q[j].first;
                int const& y = Q[j].second;
                int nx = x + delta, ny = y;
                if (nx <= maxSum)
                {
                    if (!F[nx][ny])
                        F[nx][ny] = 1, Q.push_back({ nx, ny });
                }
                nx = x, ny = y + delta;
                if (ny <= maxSum)
                {
                    if (!F[nx][ny])
                        F[nx][ny] = 1, Q.push_back({ nx, ny });
                }
            }
        }
        for (int result = maxSum; result >= 0; --result)
            if (F[result][result])
                return result;
        return -1;
    }
};
