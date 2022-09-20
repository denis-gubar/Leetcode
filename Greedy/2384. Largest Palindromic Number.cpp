class Solution {
public:
    string largestPalindromic(string num) {
        string result;
        vector<int> M(10);
        for (char c : num)
            ++M[c - '0'];
        string middle;
        for (int i = 9; i >= 0; --i)
        {
            if (M[i] % 2 == 1 && middle.empty())
                middle = string(1, i + '0');
            int count = M[i] / 2;
            if (count > 0)
            {
                if (i > 0 || !result.empty())
                    result += string(count, i + '0');
            }
        }
        string t = result;
        reverse(t.begin(), t.end());
        result += middle;
        result += t;
        if (result.empty() && M[0] > 0)
            result = "0";
        return result;
    }
};
