class Solution {
public:
	int maximumSwap(int num) {
		int result = num;
		string s = to_string(num);
        int const N = s.size();
		for (int a = 0; a + 1 < N; ++a)
			for (int b = a + 1; b < N; ++b)
			{
				swap(s[a], s[b]);
				int current = atoi(s.c_str());
				result = max(result, current);
				swap(s[a], s[b]);
			}
		return result;
	}
};