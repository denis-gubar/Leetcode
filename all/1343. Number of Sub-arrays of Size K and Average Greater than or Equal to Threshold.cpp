class Solution {
public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		int result = 0;
		int sum = accumulate(arr.begin(), arr.begin() + (k - 1), 0);
		int T = threshold * k;
		for (int i = k - 1; i < arr.size(); ++i)
		{
			sum += arr[i];
			if (i >= k)
				sum -= arr[i - k];
			result += sum >= T;
		}
		return result;
	}
};