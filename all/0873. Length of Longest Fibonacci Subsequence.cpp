class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int result = 0;
		int const n = A.size();
		unordered_set<int> S;
		for (int i : A)
			S.insert(i);
		for(int i = 0; i + 2 < n; ++i)
			for(int j = i + 1; j + 1 < n; ++j)
				if (S.find(A[i] + A[j]) != S.end())
				{
					int current = 3;
					int prev = A[j], next = A[i] + A[j];
					while (S.find(prev + next) != S.end())
					{
						++current;
						int x = prev + next;
						prev = next;
						next = x;
					}
					result = max(result, current);
				}
		return result;
	}
};