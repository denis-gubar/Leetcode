class Solution {
public:
    int calc(int count, int upgrade, int sell, int money)
    {
        int a = 0, b = count + 1;
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (1LL * m * upgrade <= 1LL * max(0, count - m) * sell + money)
                a = m;
            else
                b = m;
        }
        return a;
    }
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        int const N = count.size();
        vector<int> result(N);
        for (int i = 0; i < N; ++i)
            result[i] = calc(count[i], upgrade[i], sell[i], money[i]);
        return result;
    }
};
