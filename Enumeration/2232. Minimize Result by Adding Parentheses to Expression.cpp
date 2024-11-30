class Solution {
public:
    string minimizeResult(string expression) {
        string result;
        int best = 1 << 30;
        int const pos = expression.find('+'), N = expression.size();
        for (int a = 0; a < pos; ++a)
        {
            int left = ((a == 0) ? 1 : stoi(expression.substr(0, a)));
            int midL = stoi(expression.substr(a, pos - a));
            for (int b = pos + 2; b <= N; ++b)
            {
                int right = ((b == N) ? 1 : stoi(expression.substr(b)));
                int midR = stoi(expression.substr(pos + 1, b - pos - 1));
                if (left * (midL + midR) * right < best)
                {
                    best = left * (midL + midR) * right;
                    result = expression.substr(0, a) + '(' + expression.substr(a, pos - a);
                    result += '+';
                    result += expression.substr(pos + 1, b - pos - 1) + ')' + expression.substr(b);
                }
            }
        }
        return result;
    }
};
