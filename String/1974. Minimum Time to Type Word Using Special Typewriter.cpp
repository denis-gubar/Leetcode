class Solution {
public:
	int minTimeToType(string word) {
		int result = 0;
		char pos = 'a';
		for (char c : word)
		{
			if (c != pos)
			{
				int delta = (c + 26 - pos) % 26;
                int delta2 = abs(26 - delta);
				result += min(delta, delta2);
                pos = c;
			}
			++result;
		}
		return result;
	}
};