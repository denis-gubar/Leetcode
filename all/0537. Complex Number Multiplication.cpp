class Solution {
public:
	pair<int, int> parse(string const& x)
	{
		int pos = x.find('+');
		int a = stoi(x.substr(0, pos));
		int b = stoi(x.substr(pos + 1, x.size() - pos - 2));
		return { a, b };
	}
	string complexNumberMultiply(string a, string b) {
		pair<int, int> A = parse(a);
		pair<int, int> B = parse(b);
		int real = A.first * B.first - A.second * B.second;
		int im = A.first * B.second + B.first * A.second;
		return to_string(real) + '+' + to_string(im) + 'i';
	}
};