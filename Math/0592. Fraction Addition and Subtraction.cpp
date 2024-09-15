class Solution {
public:
    string fractionAddition(string expression) {
        string result;
        expression.push_back('-');
        vector<int> A(20);
        vector<bool> isNegative(20);
        int step = 0;
        for (char c : expression)
        {
            if (c == '-')
            {
                if (step != 0)
                    ++step;
                isNegative[step] = true;
            }
            else if (c == '+' || c == '/')
                ++step;
            else
                A[step] = A[step] * 10 + (c - '0');
        }
        for (int i = 0; i < step; ++i)
            if (isNegative[i])
                A[i] = -A[i];
        for (int i = step - 2; i > 0; i -= 2)
        {
            int P = A[i] * A[i - 1] + A[i - 2] * A[i + 1];
            int Q = A[i - 1] * A[i + 1];
            int K = gcd(P, Q);
            P /= K;
            Q /= K;
            A[i - 2] = P;
            A[i - 1] = Q;
        }
        result += to_string(A[0]);
        result += '/';
        result += to_string(A[1]);
        return result;
    }
};
