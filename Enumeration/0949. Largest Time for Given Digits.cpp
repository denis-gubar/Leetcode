class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		string result;
		sort(A.begin(), A.end());
		for (int i = 0; i < 1440; ++i)
		{
			vector<int> digits;
			int h = i / 60;
			int m = i % 60;
			digits.push_back(h % 10);
			digits.push_back(h / 10);
			digits.push_back(m % 10);
			digits.push_back(m / 10);
			sort(digits.begin(), digits.end());
			if (A == digits)
				result = to_string(100 + h).substr(1) + ":" + to_string(100 + m).substr(1);
		}
		return result;
	}
};