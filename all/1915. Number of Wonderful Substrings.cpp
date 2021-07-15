class Solution {
public:
	long long wonderfulSubstrings(string word) {
		long long result = 0;
		vector<long long> A(1 << 10);
        A[0] = 1;
		int state = 0;
		for (char c : word)
		{
            state ^= 1 << (c - 'a');
			result += A[state];
			for (int k = 0; k < 10; ++k)
				result += A[state ^ (1 << k)];
			++A[state];
		}
		return result;
	}
};