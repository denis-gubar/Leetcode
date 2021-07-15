class Solution {
public:
	string largestOddNumber(string num) {
		int N = num.size();
		for (int i = N - 1; i >= 0; --i)
			if (num[i] % 2 == 1)
				return num.substr(0, i + 1);		
		return {};
	}
};