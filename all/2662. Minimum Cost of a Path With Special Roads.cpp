static int D[402][402];
static pair<int, int> P[402];
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        memset(D, 1, sizeof(D));
        map<pair<int, int>, int> M;
        int N = 0;
        auto add = [&M, &N](int x, int y) -> int
        {
            auto it = M.find({ x, y });
            if (it == M.end())
            {
                P[N] = { x, y };
                M[{x, y}] = N;
                ++N;
                return N - 1;
            }
            return it->second;
        };
        for (vector<int> const& e : specialRoads)
        {
            int const& x1 = e[0];
            int const& y1 = e[1];
            int const& x2 = e[2];
            int const& y2 = e[3];
            int V = add(x1, y1);
            int U = add(x2, y2);
        }
        for (vector<int> const& e : specialRoads)
        {
            int const& x1 = e[0];
            int const& y1 = e[1];
            int const& x2 = e[2];
            int const& y2 = e[3];
            int const& cost = e[4];
            int V = add(x1, y1);
            int U = add(x2, y2);
            D[V][U] = min(D[V][U], cost);
        }
        int S = add(start[0], start[1]), T = add(target[0], target[1]);
        for (int V = 0; V < N; ++V)
            for (int U = 0; U < N; ++U)
                D[V][U] = min(D[V][U], abs(P[V].first - P[U].first) + abs(P[V].second - P[U].second));
        for (int i = 0; i < N; ++i)
            for (int V = 0; V < N; ++V)
                for (int U = 0; U < N; ++U)
                    D[V][U] = min(D[V][U], D[V][i] + D[i][U]);
        return D[S][T];
    }
};

