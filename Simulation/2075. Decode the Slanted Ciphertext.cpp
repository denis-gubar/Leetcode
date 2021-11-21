class Solution {
public:
	string decodeCiphertext(string encodedText, int rows) {
		int N = encodedText.size();
		string result;
		int columns = N / rows;
		for (int x = 0, y = 0; y < columns; )
		{
			result += encodedText[x * columns + y];
			++x, ++y;
			if (x == rows)
			{
				x = 0;
				y -= rows - 1;
			}
		}
        while(result.back() == ' ')
            result.pop_back();
		return result;
	}
};