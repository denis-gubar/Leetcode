class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int N = s.size();
        int result = 0;
        for (int start = 0; start < N; ++start)
        {
            int balance = 0;
            for (int i = start; i < N; ++i)
            {
                if (s[i] == '0')
                    ++balance;
                else
                    --balance;
                if (balance == 0)
                {
                    if (is_sorted(s.begin() + start, s.begin() + i + 1))
                        result = max(result, i - start + 1);
                }
            }
        }
        return result;
    }
};
