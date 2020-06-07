class Solution {
public:
	vector<int> getStrongest(vector<int>& arr, int k) {
		int N = arr.size();
		nth_element(arr.begin(), arr.begin() + (N - 1) / 2, arr.end());
		int m = arr[(N - 1) / 2];
		auto comp = [m](int a, int b)
		{
            if (abs(b - m) == abs(a - m))
                return b < a;
			return abs(b - m) < abs(a - m);
		};
		nth_element(arr.begin(), arr.begin() + k, arr.end(), comp);
		return vector<int>(arr.begin(), arr.begin() + k);
	}
};