class Solution {
public:
	bool winnerOfGame(string colors) {
		int N = colors.size();
		int A = 0, B = 0;
		int size = 0;
		for (char c : colors)
		{
			if (c == 'A')
				++size;
			else
			{
				if (size > 2)
					A += size - 2;
				size = 0;
			}
		}
		if (size > 2)
			A += size - 2;
		size = 0;
		for (char c : colors)
		{
			if (c == 'B')
				++size;
			else
			{
				if (size > 2)
					B += size - 2;
				size = 0;
			}
		}
		if (size > 2)
			B += size - 2;
		return A > B;
	}
};