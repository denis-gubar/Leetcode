class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        string const D{ "NESW" };
        int N = 0, E = 0, S = 0, W = 0, total = 0;
        auto update = [&total, &result, k](int sum)
            {
                int delta = min(k, total - sum);
                int rest = total - delta - sum;
                int current = sum + min(k, total - sum) - rest;
                result = max(result, current);
            };
        for (char c : s)
        {
            if (c == 'N')
                ++N;
            if (c == 'E')
                ++E;
            if (c == 'S')
                ++S;
            if (c == 'W')
                ++W;
            ++total;
            update(N + E);
            update(N + W);
            update(S + E);
            update(S + W);
        }
        return result;
    }
};
