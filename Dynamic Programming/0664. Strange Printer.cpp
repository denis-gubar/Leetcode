static char F[100][100][27];
class Solution {
public:
    char const INF = 101;
    char calc(int first, int last, int color)
    {
        char& result = F[first][last][color];
        if (result == INF)
        {
            if (first > last)
                result = 0;
            else if (first == last)
                result = color + 'a' != s[first];
            else
            {
                if (color == 26 && s[first] == s[last])
                    result = min<char>(result, 1 + calc(first, last, s[first] - 'a'));
                for (int mid = first + 1; mid <= last; ++mid)
                {
                    char left = min(calc(first, mid - 1, s[first] - 'a') + (s[first] != color + 'a'),
                                    calc(first, mid - 1, s[mid - 1] - 'a') + (s[mid - 1] != color + 'a'));
                    char right = min(calc(mid, last, s[mid] - 'a') + (s[mid] != color + 'a'),
                                    calc(mid, last, s[last] - 'a') + (s[last] != color + 'a'));
                    result = min<char>(result, left + right);
                }
            }
        }
        return result;
    }
    string s;
    int strangePrinter(string s) {
        this->s = s;
        int N = s.size();
        memset(F, INF, sizeof(F));
        return calc(0, N - 1, 26);
    }
};

