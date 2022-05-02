class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		int result = 0;
		for (string const& s : sentence)
			if (s.size() > cols)
				return 0;
		int N = sentence.size();
		int x = 0, y = 0;
		while (x < rows)
		{
			for (int i = 0; x < rows && i < N; ++i)
			{
				if (y == 0 && i == 0 && x > 0 && rows / x > 1)
				{
					int period = x;
					result *= rows / period;
					x *= rows / period;
				}
				if (y + sentence[i].size() <= cols)
					y += sentence[i].size() + 1;
				else
					++x, y = 0, --i;
			}
			if (x == rows)
				break;
			++result;			
		}
		return result;
	}
};