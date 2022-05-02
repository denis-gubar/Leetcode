class Solution {
public:
    int calc(string const& s)
    {
        int result = 0;
        result += ((s[0] - '0') * 10 + (s[1] - '0')) * 60;
        result += (s[3] - '0') * 10 + (s[4] - '0');
        return result;
    }
    int convertTime(string current, string correct) {
        int result = 0;
        int A = calc(current), B = calc(correct);
        if (A > B)
            B += 1440;
        while (A < B)
        {
            if (B - A >= 60)
            {
                A += 60;
                ++result;
                continue;
			}
            if (B - A >= 15)
			{
				A += 15;
				++result;
				continue;
			}
			if (B - A >= 5)
			{
				A += 5;
				++result;
				continue;
			}
			if (B - A >= 1)
			{
				A += 1;
				++result;
				continue;
			}
        }
        return result;
    }
};
