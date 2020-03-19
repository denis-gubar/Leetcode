class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		map<int, int> M;
		for (int a : arr)
			++M[a];
		for (auto m : M)
			if (m.second * 4 > arr.size())
				return m.first;
		return -1;
	}
};