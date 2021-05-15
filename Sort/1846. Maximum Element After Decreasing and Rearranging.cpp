class Solution {
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int prev = 0;
		int N = arr.size();
		for (int i = 0; i + 1 < N; ++i)
		{
			arr[i] = min({arr[i], prev + 1, arr[i + 1]});
			prev = arr[i];
		}
		arr.back() = min(prev + 1, arr.back());
		return arr.back();
	}
};