class Solution {
public:
	int calculateTime(string keyboard, string word) {
		int result = 0;
		int pos = 0;
		for (char c : word)
		{
			int newPos = keyboard.find(c);
			result += abs(pos - newPos);
			pos = newPos;
		}
		return result;
	}
};