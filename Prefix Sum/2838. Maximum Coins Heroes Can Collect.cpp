class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        monsters.push_back(1 << 30);
        int const N = heroes.size(), M = monsters.size();
        vector<long long> result(N);
        vector<int> I(M), H(N);
        iota(I.begin(), I.end(), 0);
        iota(H.begin(), H.end(), 0);
        sort(I.begin(), I.end(), [&monsters](int a, int b)
            {
                return monsters[a] < monsters[b];
            });
        sort(H.begin(), H.end(), [&heroes](int a, int b)
            {
                return heroes[a] < heroes[b];
            });
        long long balance = 0;
        for (int i = 0, j = 0; i < N; ++i)
        {
            while (monsters[I[j]] <= heroes[H[i]])
                balance += coins[I[j]], ++j;
            result[H[i]] = balance;
        }
        return result;
    }
};
