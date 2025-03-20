static int F[395];
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int const N = days.size();
        memset(F, 1, sizeof(F));
        F[0] = 0;
        auto update = [](int& x, int value)
            {
                if (x > value)
                    x = value;
            };
        int last = 0;
        for (int i : days)
        {
            while (last + 1 < i)
                update(F[last + 1], F[last]), ++last;
            for(int j = 0, NF = F[i - 1] + costs[0]; j < 1; ++j)
                update(F[i + j], NF);
            for (int j = 0, NF = F[i - 1] + costs[1]; j < 7; ++j)
                update(F[i + j], NF);
            for (int j = 0, NF = F[i - 1] + costs[2]; j < 30; ++j)
                update(F[i + j], NF);
            last = i;
        }
        return F[days[N - 1]];
    }
};
