class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> M(1001);
		vector<int> result;
		for (int a : arr1)
			++M[a];
		for (int a : arr2)
		{
			for (int x = 0; x < M[a]; ++x)
				result.push_back(a);
			M[a] = 0;
		}
		for(int i = 0; i < M.size(); ++i)
			for (int x = 0; x < M[i]; ++x)
				result.push_back(i);
		return result;
	}
};