class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		int M = arr.back();
		arr.back() = -1;
		for (int i = arr.size() - 2; i >= 0; --i)
		{
			int NM = max(M, arr[i]);
			arr[i] = M;
			M = NM;
		}
		return arr;
	}
};