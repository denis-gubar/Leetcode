class Solution {
public:
    struct Data
    {
        int health;
        char dir;
        int pos;
    };
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> result;
        int N = positions.size();
        if (N == 1)
            return healths;
        result.reserve(N);
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&positions](int a, int b)
            {
                return positions[a] < positions[b];
            });
        list<Data> L;
        for (int i = 0; i < N; ++i)
        {
            int pos = I[i];
            L.push_back({ healths[pos], directions[pos], pos });
        }
        for (auto it = L.begin(); it != L.end(); )
        {
            if (it->dir == 'L')
            {
                ++it;
                continue;
            }
            if (next(it) == L.end())
                break;
            if (next(it)->dir == 'R')
            {
                ++it;
                continue;
            }
            if (it->health == next(it)->health)
            {
                it = L.erase(L.erase(it));
                if (it != L.begin())
                    it = prev(it);
                continue;
            }
            if (it->health < next(it)->health)
            {
                it = L.erase(it);
                if (--it->health == 0)
                    it = L.erase(it);
                if (it != L.begin())
                    it = prev(it);
                continue;
            }
            if (it->health > next(it)->health)
            {
                L.erase(next(it));
                if (--it->health == 0)
                    it = L.erase(it);
                if (it != L.begin())
                    it = prev(it);
                continue;
            }
        }
        vector<pair<int, int>> P;
        P.reserve(N);
        for (auto it = L.begin(); it != L.end(); ++it)
            P.push_back({ it->pos, it->health });
        sort(P.begin(), P.end());
        for (pair<int, int> p : P)
            result.push_back(p.second);
        return result;
    }
};
