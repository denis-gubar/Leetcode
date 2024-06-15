class Solution {
public:
    string calc(int n)
    {
        string result;
		if (n < 3)
		{
			result += (n - 1);
			return result;
		}
		result += calc((n - 1) / 2);
		result += calc((n - 1) % 2 + 1);
		return result;
    }
    string kthLuckyNumber(int k) {
		string result = calc(k);
        string const digits{"47"};
        for(char& c : result)
            c = digits[c];
        return result;
    }
};