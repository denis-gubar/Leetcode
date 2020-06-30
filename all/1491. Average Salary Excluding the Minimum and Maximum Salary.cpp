class Solution {
public:
	double average(vector<int>& salary) {
		int count = 0, sum = 0;
		int a = *min_element(salary.begin(), salary.end());
		int b = *max_element(salary.begin(), salary.end());
		for (int s : salary)
			if (s != a && s != b)
				++count, sum += s;
		return 1.0 * sum / count;
	}
};