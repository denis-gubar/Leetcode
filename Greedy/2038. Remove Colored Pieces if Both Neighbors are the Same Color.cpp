class Solution {
public:
	bool winnerOfGame(string colors) {
		colors += '#';
		auto calc = [&colors](char t) -> int
			{
				int result = 0, size = 0;
				for (char c : colors)
				{
					if (c == t)
						++size;
					else
					{
						if (size > 2)
							result += size - 2;
						size = 0;
					}
				}
				return result;
			};
		return calc('A') > calc('B');
	}
};
