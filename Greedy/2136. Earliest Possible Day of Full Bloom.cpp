class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int N = plantTime.size();
        int result = 0;
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&plantTime, &growTime](int i, int j)
            {
                int a = plantTime[i], x = growTime[i];
                int b = plantTime[j], y = growTime[j];
                return max(a + x, a + b + y) < max(b + y, b + a + x);
            });
        int day = 0;
        for (int i = 0; i < N; ++i)
        {
            day += plantTime[I[i]];
            result = max(result, day + growTime[I[i]]);
        }
        return result;
    }
};
