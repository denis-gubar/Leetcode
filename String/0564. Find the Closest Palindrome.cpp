class Solution {
public:
    string nearestPalindromic(string n) {
        string result;
        long long N = stoll(n) * 3;
        auto calc = [&result, N, &n](string const& s)
            {
                if (n == s)
                    return;
                if (result.empty())
                {
                    result = s;
                    return;
                }
                long long x = stoll(s) * 3 + 1;
                long long r = stoll(result) * 3 + 1;
                if (abs(x - N) < abs(r - N))
                    result = s;
            };
        if (N < 33)
            return to_string(stoll(n) - 1);
        int M = n.size();
        for (long long x = 0, y = 2, i = 18; i > 0; --i)
        {
            x = x * 10 + 9, y = y * 10 - 9;
            calc(to_string(x));
            calc(to_string(y));
        }
        string t;
        t.reserve(19);
        long long x = stoll(n.substr(0, (M + 1) / 2));
        for (int delta = -1; delta <= 1; ++delta)
        {
            t = to_string(x + delta);
            copy(t.rbegin() + (M % 2), t.rend(), back_inserter(t));
            calc(t);
        }
        return result;
    }
};

