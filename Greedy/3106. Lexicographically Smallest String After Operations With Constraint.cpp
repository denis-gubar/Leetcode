class Solution {
public:
    int calc(char a, char b)
    {
        int result = abs(a - b);
        if (a < b)
            result = min(result, a + 26 - b);
        else
            result = min(result, b + 26 - a);
        return result;
    }
    string getSmallestString(string s, int k) {
        int N = s.size();
        string result;
        result.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                int x = calc(c, s[i]);
                if (x <= k)
                {
                    result += c;
                    k -= x;
                    break;
                }
            }
        }
        return result;
    }
};
