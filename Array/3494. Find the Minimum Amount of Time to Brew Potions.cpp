static long long F[2][5'000];
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int const N = skill.size(), M = mana.size();
        long long time = 0;
        for (int i = 0, j = 0; i < N; ++i)
        {
            time += 1LL * skill[i] * mana[j];
            F[j % 2][i] = time;
        }
        for (int j = 1; j < M; ++j)
        {
            long long delta = -10'000'000'000LL;
            time = F[(j + 1) % 2][0];
            for (int i = 0; i < N; ++i)
            {
                delta = max(delta, F[(j + 1) % 2][i] - time);
                time += 1LL * skill[i] * mana[j];
                F[j % 2][i] = time;
            }
            for (int i = 0; i < N; ++i)
                F[j % 2][i] += delta;
        }
        return F[(M + 1) % 2][N - 1];
    }
};
