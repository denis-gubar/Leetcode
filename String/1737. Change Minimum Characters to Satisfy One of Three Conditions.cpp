class Solution {
public:
	vector<int> calc(string const& s)
	{
		vector<int> result(26);
		for (char c : s)
			++result[c - 'a'];
		return result;
	}
	int minCharacters(string a, string b) {
		vector<int> A = calc(a);
		vector<int> B = calc(b);
		int result = a.size() + b.size();
		for (char c = 'a'; c <= 'z'; ++c)
		{
			result = min(result, 
				static_cast<int>(a.size()) - A[c - 'a'] +
				static_cast<int>(b.size()) - B[c - 'a']);
		}
		for (char c = 'b'; c <= 'z'; ++c)
		{
			int current = 0;
			for (char x = 'a'; x < c; ++x)
				current += A[x - 'a'];
			for (char x = c; x <= 'z'; ++x)
				current += B[x - 'a'];
			result = min(result, current);
			current = 0;
			for (char x = 'a'; x < c; ++x)
				current += B[x - 'a'];
			for (char x = c; x <= 'z'; ++x)
				current += A[x - 'a'];
			result = min(result, current);
		}
		return result;
	}
};