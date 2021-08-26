class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		vector<int> result;
		if (!is_sorted(A.begin(), A.end()))
		{
			int N = A.size();
			for (int k = N; k >= 1; --k)
			{
				int pos = find(A.begin(), A.end(), k) - A.begin();
				if (pos + 1 < k)
				{
					if (pos > 0)
					{
						result.push_back(pos + 1);
						reverse(A.begin(), A.begin() + pos + 1);
					}
					result.push_back(k);
					reverse(A.begin(), A.begin() + k);
				}
			}
		}
		return result;
	}
};