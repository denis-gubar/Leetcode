class Solution {
public:
	int maxWidthRamp(vector<int>& A) {
		int result = 0;
		vector<int> Last(50001);
		for (int i = 0; i < A.size(); ++i)
			Last[A[i]] = i;
		for (int i = 49999; i >= 0; --i)
			if (Last[i] < Last[i + 1])
				Last[i] = Last[i + 1];
		for (int i = 0; i < A.size(); ++i)
			result = max(result, Last[A[i]] - i);
		return result;
	}
};