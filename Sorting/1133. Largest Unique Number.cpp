class Solution {
public:
	int largestUniqueNumber(vector<int>& A) {
		int result = -1;
		vector<int> M(1001);
		for (int a : A)
			++M[a];
		for (int i = 0; i < 1001; ++i)
			if (M[i] == 1)
				result = i;
		return result;
	}
};