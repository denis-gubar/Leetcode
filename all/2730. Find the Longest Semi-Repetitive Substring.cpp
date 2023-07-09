class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int N = s.size();
        int result = 1;
        for (int i = 0; i < N; ++i)
        {
            bool flag = false;
            for (int j = i + 1; j < N; ++j)
            {
                if (s[j] == s[j - 1])
                {
                    if (flag)
                        break;
                    flag = true;
                }
                result = max(result, j - i + 1);
            }
        }
        return result;
    }
};
