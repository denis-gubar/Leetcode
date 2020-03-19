class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		vector<int> result(arr);
		result.back() = -1;
		for (int i = result.size() - 2; i >= 0; --i)
			result[i] = max(arr[i + 1], result[i + 1]);
		return result;
	}
};