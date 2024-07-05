class Solution {
public:
    bool splitString(string s) {
        int N = s.size();
        s += '$';
        long long const INF = 10'000'000'000LL;
        for (int prefix_length = 1; prefix_length < N; ++prefix_length)
        {
            long long x = stoll(s.substr(0, prefix_length));
            if (x > INF)
                break;
            int i = prefix_length;
            long long y = 0;
            bool isEmpty = true;
            for (char c : s.substr(prefix_length))
            {
                if (c == '$')
                {
                    if (isEmpty || !isEmpty && y == 0 && x == 1)
                        return true;
                    break;
                }
                y = y * 10 + (c - '0');
                isEmpty = false;
                if (y >= x)
                    break;
                if (y > 0 && y + 1 == x)
                    isEmpty = true, x = y, y = 0;
            }
        }
        return false;
    }
};
