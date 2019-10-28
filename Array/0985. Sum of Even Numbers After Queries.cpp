class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		vector<int> result;
		int sum = 0;
		for (int a : A)
			if (a % 2 == 0)
				sum += a;
		for (const vector<int>& query : queries)
		{
			int val = query[0], index = query[1];
			if (A[index] % 2 == 0)
			{
				if (val % 2 == 0)
					sum += val;
				else
					sum -= A[index];
			}
			else
			{
				if (val % 2 != 0)
					sum += val + A[index];
			}
			A[index] += val;
			result.push_back(sum);
		}
		return result;
	}
};