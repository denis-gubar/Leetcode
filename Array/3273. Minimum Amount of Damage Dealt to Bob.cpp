class Solution {
public:
    struct Data
    {
        double ratio;
        int turns;
        int damage;
        friend bool operator< (Data L, Data R)
        {
            return tie(L.ratio, L.turns, L.damage) < tie(R.ratio, R.turns, R.damage);
        }
    };
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long result = 0;
        int const N = health.size();
        vector<Data> F(N);
        for (int i = 0; i < N; ++i)
            F[i] = { -1.0 * damage[i] / ((health[i] + power - 1) / power),
                    (health[i] + power - 1) / power,
                    -damage[i] };
        sort(F.begin(), F.end());
        long long current = accumulate(damage.begin(), damage.end(), 0LL);
        for (int i = 0; i < N; ++i)
            result += current * F[i].turns, current += F[i].damage;
        return result;
    }
};
