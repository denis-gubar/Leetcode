class Solution {
public:
	int maximumSwap(int num) {
		int result = num;
		if (num == 1000000000)
			return result;
		string s = to_string(num);
		for (int a = 0; a + 1 < s.size(); ++a)
			for (int b = a + 1; b < s.size(); ++b)
			{
				swap(s[a], s[b]);
				int current = atoi(s.c_str());
				result = max(result, current);
				swap(s[a], s[b]);
			}
		return result;
	}
};