class Solution {
public:
    string smallestBeautifulString(string const& s, int k) {
        string result(s);
        int N = s.size();
        int pos = N - 1;
        ++result[pos];
        while (pos >= 0 && pos < N)
        {
            if (result[pos] >= k + 'a')
            {
                result[pos] = 'a', --pos;
                if (pos < 0)
                    break;
                ++result[pos];
            }
            else if (pos > 0 && result[pos] == result[pos - 1] || pos > 1 && result[pos] == result[pos - 2])
                ++result[pos];
            else
                ++pos;
        }
        if (pos < 0)
            result.clear();
        return result;
    }
};
