class Solution {
public:
    int splitNum(int num) {
        string s(to_string(num));
        int N = s.size();
        int result = num;
        sort(s.begin(), s.end());
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            int a = 0, b = 0;
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    a = a * 10 + (s[k] - '0');
                else
                    b = b * 10 + (s[k] - '0');
            result = min(result, a + b);
        }
        return result;
    }
};
