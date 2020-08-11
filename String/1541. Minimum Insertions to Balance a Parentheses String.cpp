class Solution {
public:
	int minInsertions(string s) {
		int result = 0;
		int n = s.size();
        int b = 0;
        int dif = 0;
        for(int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                ++b;
            else
            {
                if (i + 1 < n && s[i + 1] == ')')
                {
                    --b; ++i;
                }
                else
                {
                    ++result;
                    --b;
                }
                if (b < 0)
                {
                    ++result;
                    ++b;
                }
            }
        }
        result += b * 2;
		return result;
	}
};