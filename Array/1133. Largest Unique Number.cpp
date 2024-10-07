class Solution {
public:
	int largestUniqueNumber(vector<int>& A) {
		unique_ptr<short[]> M = make_unique<short[]>(1'001);
		for (short a : A)
			++M[a];
		for (short i = 1000; i >= 0; --i)
			if (M[i] == 1)
				return i;
		return -1;
	}
};