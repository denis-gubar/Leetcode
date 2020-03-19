class Solution {
public:
	int minSetSize(vector<int>& arr) {
		int result = 0;
		map<int, int> M;
		for (int a : arr)
			++M[a];
		vector<int> A;
		for (auto m : M)
			A.push_back(m.second);
		sort(A.begin(), A.end());
		int count = 0;
		while (count * 2 < arr.size())
		{
			++result;
			count += A.back();
			A.pop_back();
		}
		return result;
	}
};