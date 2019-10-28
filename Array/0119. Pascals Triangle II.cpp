class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> prev{}, current{ 1 };
		for (int i = 1; i <= rowIndex; ++i)
		{
			prev = current;
			for (int j = 1; j < i; ++j)
				current[j] += prev[j - 1];
			current.push_back({ 1 });
		}
		return current;
	}
};