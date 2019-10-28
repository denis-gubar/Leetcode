class Solution {
public:
	string toLowerCase(string str) {
		string result{ str };
		for (char& c : result)
			if (c >= 'A' && c <= 'Z')
				c = 'a' + (c - 'A');
		return result;
	}
};