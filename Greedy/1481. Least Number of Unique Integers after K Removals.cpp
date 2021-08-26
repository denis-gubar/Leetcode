class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		vector<int>	A(arr), B;
		sort(A.begin(), A.end());
		int count = A.size();
		int prev = 0;
		for(int i = 1; i < count; ++i)
			if (A[i] != A[i - 1])
			{
				B.push_back(i - prev);
				prev = i;
			}
		B.push_back(count - prev);
		sort(B.begin(), B.end());
		reverse(B.begin(), B.end());
		while (k > 0)
		{
			--B.back();
			if (!B.back()) B.pop_back();
			--k;
		}
		return B.size();
	}
};