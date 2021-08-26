class Solution {
public:
	int minimumDeletions(string s) {
		int a = count(s.begin(), s.end(), 'a');
		int b = count(s.begin(), s.end(), 'b');
		if (!a || !b) return 0;
		int L = 0, R = a;
		int N = s.size();
		int result = N;
		for (int i = 0; i < N; ++i)
		{
			result = min(result, L + R);
			if (s[i] == 'a')
				--R;
			else
				++L;
		}
		result = min(result, L + R);
		return result;
	}
};