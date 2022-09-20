class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int N = garbage.size();
        auto calc = [N, &garbage, &travel](char c)
        {
            int total = 0;
            bool collected = false;
            for (int i = N - 1; i >= 0; --i)
            {
                if (collected)
                    total += travel[i];
                int x = count(garbage[i].begin(), garbage[i].end(), c);
                collected |= x > 0;
                total += x;
            }
            return total;
        };
        int result = calc('M') + calc('G') + calc('P');
        return result;
    }
};
