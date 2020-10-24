class Solution {
public:
	double trimMean(vector<int>& arr) {
		double result = 0, count = 0;
		int N = arr.size();
		sort(arr.begin(), arr.end());
		int x = N / 20;
		for (int i = x; i + x < N; ++i, ++count)
			result += arr[i];
		return result / count;
	}
};