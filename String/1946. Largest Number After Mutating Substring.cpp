class Solution {
public:
	string maximumNumber(string num, vector<int>& change) {
		string result;
		int count = 0;
		for (char c : num)
		{
			if (count == 0)
			{
				if (c < change[c - '0'] + '0')
				{
					c = change[c - '0'] + '0';
					++count;
				}
			}
			else if (count == 1)
			{
				if (c <= change[c - '0'] + '0')
					c = change[c - '0'] + '0';
				else
					++count;
			}
			result += c;
		}
		return result;
	}
};