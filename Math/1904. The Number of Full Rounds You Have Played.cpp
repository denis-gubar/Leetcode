class Solution {
public:
    int calc(string const& s)
    {
        return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    }
    int numberOfRounds(string loginTime, string logoutTime) {
        int a = calc(loginTime), b = calc(logoutTime);
        if (a > b)
            b += 1440;
        a = (a + 14) / 15;
        b = b / 15;
        return max(0, b - a);
    }
};
