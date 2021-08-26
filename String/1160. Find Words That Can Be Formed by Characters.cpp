class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int result = 0;
		vector<int> count(128);
		for (char c : chars)
			++count[c];
		for (string const& word : words)
		{
			vector<int> A(count);
			bool flag = true;
			for (char c : word)
				if (--A[c] < 0)
					flag = false;
			if (flag)
				result += word.size();
		}
		return result;
	}
};