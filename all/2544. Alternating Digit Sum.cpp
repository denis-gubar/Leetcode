class Solution {
public:
    int alternateDigitSum(int n) {
        int result = 0;
        string s = to_string(n);
        for (int i = 0; i < s.size(); ++i)
            if (i % 2 == 0)
                result += s[i] - '0';
            else
                result -= s[i] - '0';
        return result;
    }
};
