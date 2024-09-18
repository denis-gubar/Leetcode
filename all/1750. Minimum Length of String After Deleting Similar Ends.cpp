class Solution {
public:
	int minimumLength(string s) {
        int N = s.size();
		int left = 0, right = N - 1;
		while (left < right && s[left] == s[right])
		{
			char x = s[right];
			while (left <= right && s[left] == x)
				++left;
			while (left <= right && s[right] == x)
				--right;
		}
		return right - left + 1;
	}
};