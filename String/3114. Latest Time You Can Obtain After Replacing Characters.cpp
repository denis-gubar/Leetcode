class Solution {
public:
    string findLatestTime(string s) {
        string result;
        for (int i = 0; i < 720; ++i)
        {
            string digits;
            int h = i / 60;
            int m = i % 60;
            digits.push_back('0' + h / 10);
            digits.push_back('0' + h % 10);
            digits.push_back(':');
            digits.push_back('0' + m / 10);
            digits.push_back('0' + m % 10);
            bool flag = true;
            for (int j = 0; j < 5; ++j)
                if (digits[j] != s[j] && s[j] != '?')
                    flag = false;
            if (flag)
                result = digits;
        }
        return result;
    }
};
