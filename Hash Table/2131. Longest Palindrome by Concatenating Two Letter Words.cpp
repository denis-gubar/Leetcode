class Solution {
public:
    int hash(string const& s)
    {
        int result = (s[0] - 'a') * 26 + (s[1] - 'a');
        return result;
    }
    int longestPalindrome(vector<string>& words) {
        vector<int> M(26 * 26);
        for (string const& s : words)
            ++M[hash(s)];
        int result = 0;
        int odd = 0;
        for(char a = 'a'; a <= 'z'; ++a)
            for (char b = a; b <= 'z'; ++b)
            {
                string x, y;
                x += a;
                x += b;
                y += b;
                y += a;
                if (a != b)  
                    result += min(M[hash(x)], M[hash(y)]) * 4;
                else
                {
                    int k = M[hash(x)];
                    if (k > 0)
                    {
                        if (k % 2 == 1)
                            odd = 1;
                        result += k / 2 * 4;
                    }
                }
            }
        result += odd * 2;
        return result;
    }
};
