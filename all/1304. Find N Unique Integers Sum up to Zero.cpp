class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> result(n);
		int sum = 0;
		for (int i = 1; i < n; ++i)
			sum += (result[i] = i);
		result[0] = -sum;
		return result;
	}
};