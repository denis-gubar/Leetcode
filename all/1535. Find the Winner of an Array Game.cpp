class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		int result = 0;
		deque<int> A(arr.begin(), arr.end());
		int numWins = 0, N = A.size();
		k = min(N, k);
		while (numWins < k)
		{
			int lost = 0;
			if (A[0] > A[1])
			{
				result = A[0];
				++numWins;
				lost = A[1];
			}
			else
			{
				result = A[1];
				numWins = 1;
				lost = A[0];
			}
			A.pop_front();
			A[0] = result;
			A.push_back(lost);
		}
		return result;
	}
};