class Solution {
public:
	string originalDigits(string s) {
		vector<string> digits{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
		unordered_map<char, int> M;
		for (char c : s)
			++M[c];
		vector<int> A(10);
		auto remove = [&M, &A, &digits](char x, string const& s)
		{
            int delta = M[x];
			for (char c : s)
				M[c] -= delta;
			A[find(digits.begin(), digits.end(), s) - digits.begin()] += delta;
		};
		remove('x', "six");
		remove('g', "eight");
		remove('u', "four");
		remove('w', "two");
		remove('z', "zero");
		remove('o', "one");
		remove('f', "five");
		remove('v', "seven");
		remove('i', "nine");
		remove('t', "three");
		string result;
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < A[i]; ++j)
				result += '0' + i;
		return result;
	}
};