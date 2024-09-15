class Solution {
public:
    string largestPalindrome(int N, int K) {
        if (K == 1 || K == 3 || K == 9)
            return string(N, '9');
        if (N == 1)
        {
            for (int i = 9; ; --i)
                if (i % K == 0)
                    return to_string(i);
        }
        if (N == 2)
        {
            for (int i = 9; ; --i)
                if (i % K == 0)
                    return to_string(i * 11);
        }
        if (K == 6)
        {
            if (N % 2 == 1)
                return '8' + string(N / 2 - 1, '9') + '8' + string(N / 2 - 1, '9') + '8';
            return '8' + string(N / 2 - 2, '9') + '7' + '7' + string(N / 2 - 2, '9') + '8';
        }
        if (K == 2)
            return '8' + string(N - 2, '9') + '8';
        if (K == 4)
        {
            if (N == 3)
                return "888";
            return "88" + string(N - 4, '9') + "88";
        }
        if (K == 8)
        {
            if (N <= 6)
                return string(N, '8');
            return "888" + string(N - 6, '9') + "888";
        }
        if (K == 5)
            return '5' + string(N - 2, '9') + '5';
        string result(N, '9');
        auto check = [N, &result]() -> bool
            {
                int reminder = 0;
                for (int i = 0; i < N; ++i)
                    reminder = (reminder * 10 + result[i] - '0') % 7;
                return reminder == 0;
            };
        if (N % 2 == 0)
            while (!check())
                --result[N / 2], --result[N / 2 - 1];
        else
            while (!check())
                --result[N / 2];
        return result;
    }
};
