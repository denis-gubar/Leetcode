class Solution {
public:
    string hex(int N)
    {
        string digits{ "0123456789ABCDEF" };
        string result;
        while (N > 0)
        {
            result += digits[N % 16];
            N /= 16;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string hex3(int N)
    {
        string digits{ "0123456789" };
        for (char c = 'A'; c <= 'Z'; ++c)
            digits += c;
        string result;
        while (N > 0)
        {
            result += digits[N % 36];
            N /= 36;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string concatHex36(int N) {
        return hex(N * N) + hex3(N * N * N);
    }
};
