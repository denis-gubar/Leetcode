class Solution {
public:
	string maximumBinaryString(string binary) {
		string result(binary);
		int N = result.size();
		int x = result.find('0');
		if (x != string::npos)
		{
			result.resize(x);
			int c1 = 0, c2 = 0;
			while (x < N)
			{
				if (binary[x] == '0')
					++c1;
				else
					++c2;
				++x;
			}
			if (c1)
				result += string(c1, '0');
			if (c2)
				result += string(c2, '1');
		}
		for (int i = 0; i < N - 1; ++i)
			if (result[i] == '0' && result[i + 1] == '0')
				result[i] = '1';
		return max(binary, result);
	}
};