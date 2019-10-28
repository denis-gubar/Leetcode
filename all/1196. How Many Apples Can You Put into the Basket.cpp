class Solution {
public:
	int maxNumberOfApples(vector<int>& arr) {
		int result = 0, sum = 0;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size() && sum + arr[i] <= 5000; ++i)
			++result, sum += arr[i];
		return result;
	}
};